/*****************************************************************************/
/*                    Buffered      analog output example                    */
/*                                                                           */
/*  This example shows how to use the powerdaq API to perform a buffered     */  
/*  update. The update is performed in a hardware timed fashion              */
/*  that is appropriate for fast speed generation (> 1MHz).                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/*      Copyright (C) 2001 United Electronic Industries, Inc.                */
/*      All rights reserved.                                                 */
/*---------------------------------------------------------------------------*/
/*                                                                           */ 
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <math.h>
#include <signal.h>
#include "win_sdk_types.h"
#include "powerdaq.h"
#include "powerdaq32.h"

#include "ParseParams.h"


typedef enum _state
{
   closed,
   unconfigured,
   configured,
   running
} tState;

typedef struct _bufferedAoData
{
   int abort;                    // set to TRUE to abort generation
   int board;                    // board number to be used for the AI operation
   int handle;                   // board handle
   int adapterType;              // adapter type, shoul be atMF or atPD2AO
   int nbOfChannels;             // number of channels
   DWORD channelList[64];
   int nbOfPointsPerChannel;     // number of samples per channel
   int nbOfFrames;
   int halfFIFOSize;             // Half size of the DAC FIFO
   double updateRate;            // sampling frequency on each channel
   tState state;                 // state of the acquisition session
   unsigned int *rawBuffer;      // address of the buffer allocated by the driver to store
   int regenerate;
} tBufferedAoData;


int InitBufferedAO(tBufferedAoData *pAoData);
int BufferedAO(tBufferedAoData *pAoData, double *buffer);
void CleanUpBufferedAO(tBufferedAoData *pAoData);

void GenerateSinWave(double* pBuffer, int nbChannels, int nbSamplePerChannel, int iteration);


static tBufferedAoData G_AoData;

// exit handler
void BufferedAOExitHandler(int status, void *arg)
{
   CleanUpBufferedAO((tBufferedAoData *)arg);
}


int InitBufferedAO(tBufferedAoData *pAoData)
{
   int retVal = 0;
   Adapter_Info adaptInfo;

   // get adapter type
   retVal = _PdGetAdapterInfo(pAoData->board, &adaptInfo);
   if (retVal < 0)
   {
      printf("BufferedAO: _PdGetAdapterInfo error %d\n", retVal);
      exit(EXIT_FAILURE);
   }

   pAoData->adapterType = adaptInfo.atType;
   if(pAoData->adapterType & atMF)
      printf("This is an MFx board\n");
   else if(pAoData->adapterType & atPD2AO)
      printf("This is an AO32 board\n");
   else
   {
      printf("This device doesn't have AO capability\n");
      exit(EXIT_FAILURE);
   }

   pAoData->handle = PdAcquireSubsystem(pAoData->board, AnalogOut, 1);
   if(pAoData->handle < 0)
   {
      printf("BufferedAO: PdAcquireSubsystem failed\n");
      exit(EXIT_FAILURE);
   }

   pAoData->state = unconfigured;

   retVal = _PdAOutReset(pAoData->handle);
   if (retVal < 0)
   {
      printf("BufferedAO: PdAOutReset error %d\n", retVal);
      exit(EXIT_FAILURE);
   }

   // need also to call this function if the board is a PD2-AO-xx
   if(pAoData->adapterType & atPD2AO)
   {
      retVal = _PdAO32Reset(pAoData->handle);
      if (retVal < 0)
      {
         printf("BufferedAO: PdAAO32Reset error %d\n", retVal);
         exit(EXIT_FAILURE);
      }
   }

   return 0;
}


int BufferedAO(tBufferedAoData *pAoData, double *voltBuffer)
{
   int retVal;
   DWORD aoCfg;
   DWORD cvDivider;
   DWORD count = 0;
   DWORD eventsToNotify = eTimeout | eFrameDone | eBufferDone | eBufferError | eStopped;
   DWORD events;
   DWORD multiplier;
   DWORD scanIndex, numScans;
   struct timeval tv1, tv2; 
   int i, j, k;
   

   // setup the board to use hardware internal clock
   aoCfg = AOB_CVSTART0 | AOB_INTCVSBASE;  // 33 MHz internal timebase
   if(pAoData->regenerate)
   {
      aoCfg |= AOB_REGENERATE; // This configuration bits causes the board to automatically
                               // regenerate from the data stored in this FIFO.
   }
      
   if(pAoData->adapterType & atPD2AO)
   {
      multiplier = 0xFFFF;  
      retVal = _PdRegisterBuffer(pAoData->handle, (WORD**)&pAoData->rawBuffer, AnalogOut,
                              pAoData->nbOfFrames, pAoData->nbOfPointsPerChannel,
                              pAoData->nbOfChannels, 
                              BUF_BUFFERWRAPPED | BUF_DWORDVALUES);
   }
   else
   {
      multiplier = 0xFFF;  
      retVal = _PdRegisterBuffer(pAoData->handle, (WORD**)&pAoData->rawBuffer, AnalogOut,
                              pAoData->nbOfFrames, pAoData->nbOfPointsPerChannel,
                              1, 
                              BUF_BUFFERWRAPPED | BUF_DWORDVALUES);
      aoCfg |= AOB_DMAEN;
   }
   
   if (retVal < 0)
   {
      printf("BufferedAO: PdRegisterBuffer error %d\n", retVal);
      exit(EXIT_FAILURE);
   }
   
   // Fill all the frames with the same data
   for(k=0; k<pAoData->nbOfFrames; k++)
   {
      for(i=0; i<pAoData->nbOfPointsPerChannel; i++)
      {
         for(j=0; j<pAoData->nbOfChannels; j++)
         {
            // We use the DWORD data format on AO boards, with this format, we need to specify
            // the ouput channel in the upper 16 bits of each sample
            if(pAoData->adapterType & atPD2AO)
            {
               pAoData->rawBuffer[k*pAoData->nbOfPointsPerChannel*pAoData->nbOfChannels+
                                  i*pAoData->nbOfChannels+j] = (pAoData->channelList[j] << 16) |
                                  (unsigned int)floor((voltBuffer[i*pAoData->nbOfChannels+j] + 10.0) / 20.0 * multiplier);
            }
            else // MF boards have only 2 12 bits AO channels, data for both channels are combined in a single
                 // value: ch0 | ch1 << 12
            {
               if(0==j)
               {
                  pAoData->rawBuffer[k*pAoData->nbOfPointsPerChannel+i] = 
                                     (unsigned int)floor((voltBuffer[i*pAoData->nbOfChannels+j] + 10.0) / 20.0 * multiplier);
               }
               else if(1==j)
               {
                  pAoData->rawBuffer[k*pAoData->nbOfPointsPerChannel+i] |= 
                                     ((unsigned int)floor((voltBuffer[i*pAoData->nbOfChannels+j] + 10.0) / 20.0 * multiplier)) << 12;
               }
            }
         }
      }
   }


   // set clock divider, assuming that we use the 33MHz timebase
   cvDivider = 33000000.0 / pAoData->updateRate -1;
   
   if(pAoData->adapterType & atMF)
      retVal = _PdAOutAsyncInit(pAoData->handle, aoCfg, 
                               cvDivider, eventsToNotify);
   else
      retVal = _PdAOAsyncInit(pAoData->handle, aoCfg, 
                               cvDivider, eventsToNotify, 
                               pAoData->nbOfChannels, (DWORD*)pAoData->channelList);
   if (retVal < 0)
   {
      printf("BufferedAO: PdAOutAsyncInit error %d\n", retVal);
      exit(EXIT_FAILURE);
   }

   pAoData->state = configured;

   retVal = _PdSetUserEvents(pAoData->handle, AnalogOut, eventsToNotify);
   if (retVal < 0)
   {
      printf("BufferedAO: _PdSetUserEvents error %d\n", retVal);
      exit(EXIT_FAILURE);
   }

   if(pAoData->adapterType & atMF)
      retVal = _PdAOutAsyncStart(pAoData->handle);
   else
      retVal = _PdAOAsyncStart(pAoData->handle);
   if (retVal < 0)
   {
      printf("BufferedAO: PdAOutAsyncStart error %d\n", retVal);
      exit(EXIT_FAILURE);
   }

   pAoData->state = running;
   
   gettimeofday(&tv2, NULL);

   while (!pAoData->abort)
   {
      if(pAoData->regenerate == 0)
      {
          events = _PdWaitForEvent(pAoData->handle, eventsToNotify, 5000);
    
          printf("Received events 0x%x\n", events);
          
          retVal = _PdSetUserEvents(pAoData->handle, AnalogOut, eventsToNotify);
          if (retVal < 0)
          {
             printf("BufferedAO: _PdSetUserEvents error %d\n", retVal);
             exit(EXIT_FAILURE);
          }
       
          if (events & eTimeout)
          {
             printf("BufferedAO: wait timed out\n"); 
             exit(EXIT_FAILURE);
          }
       
          if ((events & eBufferError) || (events & eStopped))
          {
             printf("BufferedAO: buffer error\n");
             exit(EXIT_FAILURE);
          }
       
          if ((events & eBufferDone) || (events & eFrameDone))
          {
             gettimeofday(&tv1, NULL);

             if(pAoData->adapterType & atMF)
                retVal = _PdAOutGetBufState(pAoData->handle, pAoData->nbOfPointsPerChannel, 
                                         SCANRETMODE_MMAP, &scanIndex, &numScans);
             else
                retVal = _PdAOGetBufState(pAoData->handle, pAoData->nbOfPointsPerChannel, 
                                         SCANRETMODE_MMAP, &scanIndex, &numScans);
             if(retVal < 0)
             {
                printf("BufferedAO: buffer error\n");
                exit(EXIT_FAILURE);
             }
    
                 
             count++;
       
             printf("BufferedAO: sent %d scans at %d, in %f ms\n", numScans, scanIndex, (tv1.tv_sec - tv2.tv_sec) * 1000.0 + (tv1.tv_usec - tv2.tv_usec)/1000.0);
             tv2 = tv1;

             // Generate new waveforms
             GenerateSinWave(voltBuffer, G_AoData.nbOfChannels, G_AoData.nbOfPointsPerChannel, count);
             
             // update the frame that was just generated with new data
             for(i=0; i<pAoData->nbOfPointsPerChannel; i++)
             {
                for(j=0; j<pAoData->nbOfChannels; j++)
                {
                    if(pAoData->adapterType & atPD2AO)
                    {
                        pAoData->rawBuffer[scanIndex*pAoData->nbOfChannels+
                                            i*pAoData->nbOfChannels+j] =   (pAoData->channelList[j] << 16) |
                                            (unsigned int)floor((voltBuffer[i*pAoData->nbOfChannels+j] + 10.0) / 20.0 * multiplier);
                    }
                    else // MF boards have only 2 12 bits AO channels, data for both channels are combined in a single
                        // value: ch0 | ch1 << 12
                    {
                        if(0==j)
                        {
                            pAoData->rawBuffer[scanIndex+i] = 
                                                (unsigned int)floor((voltBuffer[i*pAoData->nbOfChannels+j] + 10.0) / 20.0 * multiplier);
                        }
                        else if(1==j)
                        {
                            pAoData->rawBuffer[scanIndex+i] |= 
                                                ((unsigned int)floor((voltBuffer[i*pAoData->nbOfChannels+j] + 10.0) / 20.0 * multiplier)) << 12;
                        }
                    }
                }
             }
          }
      }
      else
      {
          printf("Regenerating...\n");
          sleep(1);
      }
   }

   return retVal;
}


void CleanUpBufferedAO(tBufferedAoData *pAoData)
{
   int retVal;
      
   if(pAoData->state == running)
   {
      if(pAoData->adapterType & atMF)
         retVal = _PdAOutAsyncStop(pAoData->handle);
      else
         retVal = _PdAOAsyncStop(pAoData->handle);
      if (retVal < 0)
         printf("BufferedAO: PdAOutAsyncStop error %d\n", retVal);

      pAoData->state = configured;
   }

   if(pAoData->state == configured)
   {
      retVal = _PdClearUserEvents(pAoData->handle, AnalogOut, eAllEvents);
      if (retVal < 0)
         printf("BufferedAI: PdClearUserEvents error %d\n", retVal);
   
      if(pAoData->adapterType & atMF)
         retVal = _PdAOutAsyncTerm(pAoData->handle); 
      else
         retVal = _PdAOAsyncTerm(pAoData->handle);
      if (retVal < 0)
         printf("BufferedAO: PdAOutAsyncTerm error %d\n", retVal);
   
      retVal = _PdUnregisterBuffer(pAoData->handle, (WORD *)pAoData->rawBuffer, AnalogOut);
      if (retVal < 0)
         printf("BufferedAO: PdUnregisterBuffer error %d\n", retVal);

      pAoData->state = unconfigured;
   }

   if(pAoData->handle > 0 && pAoData->state == unconfigured)
   {
      retVal = PdAcquireSubsystem(pAoData->handle, AnalogOut, 0);
      if (retVal < 0)
         printf("BufferedAO: PdReleaseSubsystem error %d\n", retVal);
   }

   pAoData->state = closed;
}


//////////////////////////////////////////////////////////////////////////
// Function to react to SIGINT (Ctrl+C)
void SigInt(int signum)
{
   if (signum == SIGINT)
   {
      printf("Ctrl+C detected. generation stopped\n");
      G_AoData.abort = TRUE;
   }
}


void GenerateSinWave(double* pBuffer, int nbChannels, int nbSamplePerChannel, int iteration)
{
   int i, j;
   int amplitude = (iteration % 10 + 1);

   for(i=0; i<nbSamplePerChannel; i++)
   {
      for(j=0; j<nbChannels; j++)
      {
         pBuffer[i*nbChannels+j] = amplitude * sin(2*3.1415*(j+1)*i/nbSamplePerChannel);
      }
   }
}


int main(int argc, char *argv[])
{
   double *voltBuffer = NULL;
   int i;
   PD_PARAMS params = {0, 2, {0,1}, 10000.0, 0, 1024, 0};
   
   ParseParameters(argc, argv, &params);

   // initializes acquisition session parameters
   G_AoData.board = params.board;
   G_AoData.nbOfChannels = params.numChannels;
   for(i=0; i<params.numChannels; i++)
       G_AoData.channelList[i] = params.channels[i];
   G_AoData.handle = 0;
   G_AoData.nbOfPointsPerChannel = params.numSamplesPerChannel;
   G_AoData.updateRate = params.frequency;
   G_AoData.nbOfFrames = 4;
   G_AoData.halfFIFOSize = 1024;
   G_AoData.state = closed;
   G_AoData.abort = FALSE;
   G_AoData.rawBuffer = NULL;
   G_AoData.regenerate = params.regenerate;

   // setup exit handler that will clean-up the acquisition session
   // if an error occurs
   on_exit(BufferedAOExitHandler, &G_AoData);

   // set up SIGINT handler
   signal(SIGINT, SigInt);

   // allocate memory for the generation buffer
   voltBuffer = (double *) malloc(G_AoData.nbOfChannels * G_AoData.nbOfPointsPerChannel *
                              sizeof(double));
   if(voltBuffer == NULL)
   {
      printf("BufferedAO: could not allocate enough memory for the generation buffer\n");
      exit(EXIT_FAILURE);
   }

   // writes data to buffer. Each channel will generate a sinus of different frequency
   GenerateSinWave(voltBuffer, G_AoData.nbOfChannels, G_AoData.nbOfPointsPerChannel, 0);

   // initializes acquisition session
   InitBufferedAO(&G_AoData);

   // run the acquisition
   BufferedAO(&G_AoData, voltBuffer);

   // Cleanup acquisition
   CleanUpBufferedAO(&G_AoData);

   // free acquisition buffer
   free(voltBuffer);
   
   return 0;
}
