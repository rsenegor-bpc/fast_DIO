
//-----------------------------------------------------------------------
//
// pdfwmain_i.h          *** DO NOT EDIT THIS FILE ***
//
// UEI PowerDAQ(TM) Firmware driver download include file.
//
// Revision: 020405
// Date:     Fri Apr 05, 2002
//
//-----------------------------------------------------------------------
//
// Copyright (C) 1997-2000 by United Electronic Industries, Inc.
// All rights reserved.
//
//-----------------------------------------------------------------------
#define FW_MAXSEGSIZE 2048

#define FW_SEGMENTS 17

typedef struct {
    DWORD dwMemType;
    DWORD dwMemAdrs;
    DWORD dwMemSize;
    DWORD dwMemData[FW_MAXSEGSIZE];
    } FW_MEMSEGMENT;


const DWORD dwFWExecAdrs = 0x00000100;

const int nFWMemSegments = FW_SEGMENTS;


FW_MEMSEGMENT FWDownloadData[FW_SEGMENTS] = {
    { 0x00000001, 0x00000028, 0x00000003,
      { 0x00077004, 0x00000009, 0x00000000 }},
    { 0x00000002, 0x00000000, 0x0000003D,
      { 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00A7D8E0, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000100, 0x00000000, 0x000007B8, 0x00000000, 0x00000400,
        0x00000200, 0x000001FF, 0x00000000, 0x00000200, 0x00000000,
        0x00000000, 0x00000800, 0x000007FF, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x0000007D, 0x0007F003, 0x00FC0060,
        0x00000100 }},
    { 0x00000003, 0x00000000, 0x00000001,
      { 0x00000100 }},
    { 0x00000001, 0x00000100, 0x000000C0,
      { 0x00200013, 0x00000000, 0x00501D00, 0x0054F000, 0x00FFFFC7,
        0x00000000, 0x000140C5, 0x0000014B, 0x0005A416, 0x000140C5,
        0x0000014C, 0x0005A413, 0x000140C5, 0x0000014E, 0x0005A416,
        0x000140C5, 0x0000014F, 0x0005A413, 0x000140C5, 0x00000150,
        0x0005A410, 0x000140C5, 0x00000110, 0x0005F405, 0x000A1D21,
        0x0008F4BB, 0x000493E0, 0x00050C0D, 0x000A1D20, 0x00050C0B,
        0x0008F4BB, 0x00049FE0, 0x000A1D23, 0x0008F4B7, 0x00FC0621,
        0x00050C05, 0x0008F4BB, 0x00049FE0, 0x000A1D22, 0x00050C01,
        0x00200013, 0x0005F439, 0x00000300, 0x0054F400, 0x00FFFFFF,
        0x00000000, 0x0004C8B0, 0x0004C8BF, 0x0004C8BE, 0x0004C8B1,
        0x0004C8BB, 0x0004C8AA, 0x0004C8B8, 0x0004CCA0, 0x0004CCA1,
        0x0004CCA2, 0x0004CCA3, 0x0004CCA4, 0x0004CCA5, 0x0004CCA6,
        0x0004CCA7, 0x000BF080, 0x00000153, 0x000BF080, 0x000001A8,
        0x000BF080, 0x000002C5, 0x000BF080, 0x000001DB, 0x000BF080,
        0x0000095B, 0x0000FCB8, 0x00000000, 0x000D8BB2, 0x00000497,
        0x000C8181, 0x00000007, 0x000C8182, 0x00000005, 0x000A8526,
        0x000A0102, 0x000A0101, 0x00050FD7, 0x0061F400, 0x000009D1,
        0x0064F400, 0x00000000, 0x0007D984, 0x0007D985, 0x0066F400,
        0x0000013D, 0x0067F400, 0x000001BD, 0x0061F400, 0x0000013D,
        0x0044F400, 0x00000000, 0x00068080, 0x00000165, 0x00445900,
        0x00000000, 0x00000000, 0x0061F400, 0x000001BD, 0x00000000,
        0x00064080, 0x0000016D, 0x00445900, 0x00000000, 0x00000000,
        0x00000000, 0x0000000C, 0x000BF080, 0x00000176, 0x000A0124,
        0x000BF080, 0x00000192, 0x00000004, 0x00505E00, 0x00545E00,
        0x00525E00, 0x00515E00, 0x00555E00, 0x00535E00, 0x00445E00,
        0x00455E00, 0x00465E00, 0x00475E00, 0x00605E00, 0x00705E00,
        0x00055E20, 0x00645E00, 0x00745E00, 0x00055E24, 0x0005F420,
        0x00FFFFFF, 0x0005F424, 0x00FFFFFF, 0x0022CE00, 0x00000000,
        0x000140C5, 0x000001BD, 0x0005F403, 0x00200013, 0x0020001B,
        0x0000000C, 0x0022CE00, 0x00000000, 0x000140C5, 0x0000014D,
        0x00051401, 0x0005FE24, 0x0074FE00, 0x0064FE00, 0x0005FE20,
        0x0070FE00, 0x0060FE00, 0x0047FE00, 0x0046FE00, 0x0045FE00,
        0x0044FE00, 0x0053FE00, 0x0055FE00, 0x0051FE00, 0x0052FE00,
        0x0054FE00, 0x0050FE00, 0x0000000C, 0x0061F400, 0x000009D3,
        0x0064F400, 0x00000072, 0x0007D984, 0x00064780, 0x000001B3,
        0x0007D985, 0x00075C84, 0x00075C85, 0x00000000, 0x00000000,
        0x0007F084, 0x00000A1A, 0x0007F085, 0x000009D0, 0x00075C84,
        0x00075C85, 0x0008F4BE, 0x00000002, 0x0008F485, 0x00100019,
        0x00000000, 0x0000000C }},
    { 0x00000001, 0x000001C0, 0x0000001B,
      { 0x000D0176, 0x000CC901, 0x00000000, 0x0008F48D, 0x00000001,
        0x000D10C0, 0x00000009, 0x0050F400, 0x00000001, 0x000CC901,
        0x00000000, 0x0008C80D, 0x000D0192, 0x00000004, 0x000CC902,
        0x00000000, 0x0008480B, 0x00000000, 0x0000000C, 0x000CC901,
        0x00000000, 0x0008C80D, 0x00000000, 0x0000000C, 0x000A8526,
        0x000A0101, 0x0000000C }},
    { 0x00000001, 0x000001DB, 0x0000015F,
      { 0x00200013, 0x00000000, 0x00500000, 0x00500100, 0x00500200,
        0x00500300, 0x00500500, 0x00500600, 0x00500700, 0x00500A00,
        0x00500B00, 0x00500F00, 0x00501000, 0x00501200, 0x00501300,
        0x00501400, 0x00501500, 0x00501700, 0x00501800, 0x00501900,
        0x00501A00, 0x00501E00, 0x00501F00, 0x00502000, 0x00502100,
        0x00502200, 0x00502300, 0x00502400, 0x00502500, 0x00502600,
        0x00502700, 0x00502900, 0x0007F403, 0x00000002, 0x0007F40F,
        0x00008310, 0x0007F40B, 0x00008310, 0x0007F407, 0x00008310,
        0x0004C88E, 0x0004C88A, 0x0004C886, 0x000ABE28, 0x00000000,
        0x000ABE29, 0x0064F400, 0x0000002C, 0x0007F084, 0x000009D3,
        0x0045F400, 0x00000704, 0x00075C84, 0x00075C85, 0x000BF080,
        0x000004D6, 0x0007F435, 0x00180805, 0x0007F436, 0x00012C30,
        0x0007F43F, 0x0000002C, 0x0007F43E, 0x0000002F, 0x0007F43D,
        0x0000002F, 0x000BF080, 0x000006A5, 0x000BF080, 0x000007AF,
        0x000BF080, 0x000007CE, 0x000BF080, 0x000008CC, 0x000BF080,
        0x000008C2, 0x0007B4A8, 0x00000100, 0x000A2A28, 0x000C9D83,
        0x00000008, 0x00200013, 0x00000000, 0x00587000, 0x00FC007B,
        0x00587000, 0x00FC007F, 0x0000000C, 0x000D0176, 0x0008F485,
        0x00000000, 0x000642A0, 0x00000000, 0x0008F4BF, 0x00000000,
        0x0008F4BE, 0x00000002, 0x0008F485, 0x00100019, 0x000D0192,
        0x00000004, 0x000D01C0, 0x0054F400, 0x00FFFFFF, 0x00000000,
        0x00210600, 0x0004CCA0, 0x0004CCA1, 0x0004CCA2, 0x0004CCA3,
        0x0004CCA4, 0x0004CCA5, 0x0004CCA6, 0x0004CCA7, 0x000CC902,
        0x00000000, 0x0008510B, 0x0064F400, 0x00000001, 0x0006C600,
        0x00000258, 0x000CC902, 0x00000000, 0x00085CCB, 0x00000000,
        0x00000000, 0x00223000, 0x0064F400, 0x00000001, 0x0006C600,
        0x00000262, 0x0058DC00, 0x00000000, 0x00075888, 0x00000000,
        0x00000000, 0x00200013, 0x0005F439, 0x00C00300, 0x0004C8B0,
        0x0004C8BF, 0x0004C8BE, 0x0004C8B1, 0x0004C8BB, 0x0004C8AA,
        0x0004C8B8, 0x000AE180, 0x000C0233, 0x000D01C0, 0x000CC8A0,
        0x00000005, 0x000A0101, 0x000D10C0, 0x00000003, 0x000A0121,
        0x000C01C7, 0x000A8506, 0x00087089, 0x0000001C, 0x00000004,
        0x00505E00, 0x00545E00, 0x00525E00, 0x000A0102, 0x0050F400,
        0x00000005, 0x000CC901, 0x00000000, 0x0008C80D, 0x00508100,
        0x00044C68, 0x000CC901, 0x00000000, 0x0008C80D, 0x000C1C16,
        0x00000000, 0x00044C2C, 0x00000000, 0x000C1C1A, 0x000CC901,
        0x00000000, 0x0008C80D, 0x00044C30, 0x00000000, 0x000C1C10,
        0x00000000, 0x00044C34, 0x00000000, 0x000C1C20, 0x000CC901,
        0x00000000, 0x0008C80D, 0x00508300, 0x000CC901, 0x00000000,
        0x0008C80D, 0x00508B00, 0x000CC901, 0x00000000, 0x0008C80D,
        0x0052FE00, 0x0054FE00, 0x0050FE00, 0x00000004, 0x000D01C0,
        0x0004C868, 0x000C01C7, 0x000D01C0, 0x000C1D20, 0x00000000,
        0x0004CC34, 0x000C1D10, 0x000140C6, 0x000000FF, 0x00000000,
        0x000ACC42, 0x00000000, 0x000ACC65, 0x000C8189, 0x00000004,
        0x000ACC62, 0x00000000, 0x0004CC30, 0x000CCCA4, 0x00000003,
        0x000A0128, 0x000ACC64, 0x00000000, 0x00542900, 0x000C01C7,
        0x00000004, 0x00000004, 0x0000000C, 0x0000000C, 0x0007F084,
        0x000009D3, 0x0060F400, 0x000002D5, 0x0064F400, 0x00000010,
        0x00060480, 0x000002D1, 0x0007D885, 0x00075C84, 0x00075C85,
        0x00000000, 0x00000000, 0x0008F4BF, 0x003FFB47, 0x0000000C,
        0x000002D9, 0x000002E6, 0x000002F1, 0x0000031B, 0x000C8188,
        0x00000008, 0x000C82B4, 0x00000005, 0x000A0122, 0x000A0108,
        0x00050C02, 0x00050C05, 0x000C82B3, 0x00000004, 0x0007B090,
        0x00000029, 0x00000004, 0x000C83AB, 0x00000006, 0x000A032B,
        0x000C8383, 0x00000003, 0x000A0122, 0x000C82B3, 0x00000004,
        0x0007B090, 0x00000029, 0x00000004, 0x00445F00, 0x00455F00,
        0x00044468, 0x0045A100, 0x000AC463, 0x00452200, 0x000AC464,
        0x0045A600, 0x000AC465, 0x00452700, 0x000AC467, 0x00000000,
        0x000CC489, 0x0000000D, 0x000AC449, 0x000B22A0, 0x00000574,
        0x000B22A1, 0x0000057F, 0x000B27A0, 0x0000062B, 0x000B27A1,
        0x0000063A, 0x000B27A4, 0x00000649, 0x000CC48A, 0x0000000D,
        0x000AC44A, 0x000B22A2, 0x00000574, 0x000B22A3, 0x0000057F,
        0x000B27A2, 0x0000062B, 0x000B27A3, 0x0000063A, 0x000B27A5,
        0x00000649, 0x0004C468, 0x0045FF00, 0x0044FF00, 0x00000004,
        0x000A0122, 0x00000004, 0x000D01C0, 0x00655E00, 0x00210C00,
        0x00000000, 0x000140C2, 0x00FFFF80, 0x00000000, 0x00219500,
        0x000CC902, 0x00000000, 0x0008480B, 0x00000000, 0x00506500,
        0x0065FE00, 0x000C01C7, 0x000D01C0, 0x00655E00, 0x00210C00,
        0x00000000, 0x000140C2, 0x00FFFF80, 0x00000000, 0x00219500,
        0x00000000, 0x00000000, 0x00000000, 0x0050E500, 0x0065FE00,
        0x000C01C9 }},
    { 0x00000001, 0x0000033A, 0x000000B4,
      { 0x000D0176, 0x000D0381, 0x0046BC00, 0x000CC901, 0x00000000,
        0x0008C60D, 0x0020001B, 0x0064F400, 0x0000003D, 0x0006C600,
        0x00000349, 0x000BF080, 0x000003A2, 0x00545C00, 0x00000009,
        0x00000000, 0x0064F400, 0x0000003D, 0x0006C600, 0x00000352,
        0x000CC901, 0x00000000, 0x0008DC8D, 0x00000000, 0x00000000,
        0x000C01C7, 0x000D0176, 0x000D0381, 0x0046F400, 0x00000001,
        0x000CC901, 0x00000000, 0x0008C60D, 0x000D03E2, 0x000CC902,
        0x00000000, 0x00084C0B, 0x0051F400, 0x00000006, 0x000D03CF,
        0x000D03E8, 0x000C01C7, 0x000D0176, 0x000D0381, 0x0046BC00,
        0x000CC901, 0x00000000, 0x0008C60D, 0x000CC902, 0x00000000,
        0x0008460B, 0x0064F400, 0x0000003D, 0x0006C600, 0x00000374,
        0x000CC902, 0x00000000, 0x00085C8B, 0x00000000, 0x000D03E2,
        0x0020001B, 0x0064F400, 0x0000003D, 0x0006C600, 0x0000037E,
        0x0054DC00, 0x000BF080, 0x000003CF, 0x00000009, 0x000D03E8,
        0x000C01C7, 0x0007F42F, 0x00000000, 0x0007F42D, 0x00000000,
        0x0007F42E, 0x0000002C, 0x0000000C, 0x0007F42D, 0x00000004,
        0x00050C04, 0x0007F42D, 0x00000024, 0x00050C01, 0x00012D23,
        0x00061BA0, 0x00000000, 0x00012D03, 0x000605A0, 0x00000000,
        0x0000000C, 0x000C1E9A, 0x00060B80, 0x000003A0, 0x00200033,
        0x000D1048, 0x00000005, 0x000D0388, 0x000D10C0, 0x00000003,
        0x000D038B, 0x00000000, 0x00000000, 0x0000000C, 0x00212C00,
        0x000140C2, 0x00000600, 0x000D0395, 0x000602A0, 0x00000000,
        0x00200013, 0x00061080, 0x000003B7, 0x0007F42D, 0x0000000C,
        0x000612A0, 0x00000000, 0x00016D24, 0x00200037, 0x000601A0,
        0x00000000, 0x0007F42D, 0x00000004, 0x00061AA0, 0x00000000,
        0x00000000, 0x0007F42D, 0x00000000, 0x0000000C, 0x0007F42D,
        0x00000000, 0x00060BA0, 0x00000000, 0x0007F42D, 0x00000004,
        0x00061AA0, 0x00000000, 0x0054F400, 0x0002BF20, 0x0006CC00,
        0x000003CB, 0x00016D24, 0x00000218, 0x00000000, 0x00000000,
        0x00000000, 0x0007F42D, 0x00000000, 0x0000000C, 0x000C1C30,
        0x00212C00, 0x000140C2, 0x00000500, 0x000D0395, 0x000C1D30,
        0x000C1E90, 0x00061080, 0x000003E0, 0x00200033, 0x000D1048,
        0x00000005, 0x000D0388, 0x000D10C0, 0x00000003, 0x000D038B,
        0x00000000, 0x00000000, 0x000C03BB, 0x0054F400, 0x000004C0,
        0x000D0395, 0x0007F42D, 0x00000000, 0x0000000C, 0x0054F400,
        0x00000400, 0x000D0395, 0x0007F42D, 0x00000000, 0x0000000C }},
    { 0x00000001, 0x000003EE, 0x000001B1,
      { 0x000D01C0, 0x000BF080, 0x000004D6, 0x000CC902, 0x00000000,
        0x0008460B, 0x000CC902, 0x00000000, 0x0008470B, 0x0044F400,
        0x00000000, 0x00500200, 0x00460600, 0x00470700, 0x000CC88B,
        0x00000009, 0x000CC8AC, 0x00000005, 0x000A1E20, 0x000A2020,
        0x00050C03, 0x000A1E22, 0x000A2022, 0x000CC88D, 0x00000007,
        0x000CC8AE, 0x00000004, 0x000A1F21, 0x00050C02, 0x000A1F23,
        0x000CC890, 0x00000003, 0x000A0129, 0x000CC894, 0x0000001C,
        0x0008F4AF, 0x00000000, 0x0008F4AC, 0x004EF251, 0x0008F4A0,
        0x004402C5, 0x0008F4A2, 0x00000000, 0x0008F4A3, 0x00FFFFAC,
        0x0008F4A1, 0x000001FF, 0x0007F084, 0x000009D3, 0x0064F400,
        0x0000001E, 0x0045F400, 0x00000599, 0x00075C84, 0x00075C85,
        0x0064F400, 0x00000018, 0x0045F400, 0x00000594, 0x00075C84,
        0x00075C85, 0x000C1880, 0x00009000, 0x00000000, 0x0004C824,
        0x00000000, 0x000C01C7, 0x000D01C0, 0x000C82A9, 0x00000005,
        0x0007F40B, 0x00008310, 0x00050C03, 0x0007F40B, 0x00000310,
        0x0004C889, 0x000C01C7, 0x000D01C0, 0x000C82AA, 0x00000005,
        0x0007F40F, 0x00008310, 0x00050C03, 0x0007F40F, 0x00000310,
        0x0004C88D, 0x000C01C7, 0x000D01C0, 0x00044628, 0x00000000,
        0x000AC661, 0x000AC662, 0x00000000, 0x0004C628, 0x0006C800,
        0x00000453, 0x000CC902, 0x00000000, 0x0008460B, 0x00000000,
        0x0004C66C, 0x00000000, 0x00500400, 0x00044628, 0x00000000,
        0x000AC662, 0x00000000, 0x0004C628, 0x000C01C7, 0x000D01C0,
        0x000003F8, 0x00448300, 0x00210C00, 0x00000000, 0x00200046,
        0x000C1920, 0x00008018, 0x00000000, 0x00540300, 0x0000FEB8,
        0x000C01C7, 0x00505E00, 0x00545E00, 0x00525E00, 0x00044C68,
        0x00000000, 0x000C1C16, 0x00000000, 0x00044C2C, 0x00000000,
        0x000C1C1A, 0x000CC901, 0x00000000, 0x0008C80D, 0x0052FE00,
        0x0054FE00, 0x0050FE00, 0x00000004, 0x000D01C0, 0x000CC8A0,
        0x00000006, 0x000A0310, 0x000BF080, 0x0000054A, 0x00050C04,
        0x000A0330, 0x000BF080, 0x00000523, 0x000C01C7, 0x000D0176,
        0x000BF080, 0x00000574, 0x000C01C7, 0x000D0176, 0x000BF080,
        0x0000057F, 0x000C01C7, 0x00445E00, 0x00044428, 0x00000000,
        0x000AC464, 0x00000000, 0x0004C428, 0x000CC901, 0x00000000,
        0x0008F48D, 0x00000001, 0x0044FE00, 0x00000004, 0x00445E00,
        0x00044428, 0x00000000, 0x000AC465, 0x00000000, 0x0004C428,
        0x000CC901, 0x00000000, 0x0008F48D, 0x00000001, 0x0044FE00,
        0x00000004, 0x000D0176, 0x00500400, 0x00044828, 0x00000000,
        0x000AC861, 0x00000000, 0x0004C828, 0x000C01C7, 0x000D0176,
        0x00044C28, 0x00500500, 0x000140C2, 0x00000003, 0x00000000,
        0x0004CC28, 0x000C01C7, 0x000D0176, 0x000BF080, 0x000004D6,
        0x000C01C7, 0x00010F02, 0x00010B02, 0x00010F00, 0x00010B00,
        0x0007F40B, 0x00008310, 0x0007F409, 0x00000000, 0x0007F40F,
        0x00008310, 0x0007F40D, 0x00000000, 0x0008F4A0, 0x00000000,
        0x0064F400, 0x00000018, 0x0007F084, 0x000009D3, 0x0045F400,
        0x00000593, 0x00075C84, 0x00075C85, 0x0008F4AF, 0x00FFFFAC,
        0x0008F4AE, 0x00FFFFCD, 0x0008F0AD, 0x0000002E, 0x0008F4AC,
        0x004EF241, 0x0000000C, 0x000D04B7, 0x0044F400, 0x00000000,
        0x00044D28, 0x00010B00, 0x000140CA, 0x00000003, 0x000140CE,
        0x00FFFFF7, 0x00010F00, 0x0004CD28, 0x000A0108, 0x000A0109,
        0x00440200, 0x0004C430, 0x00440400, 0x0004C434, 0x00440300,
        0x00440500, 0x00440600, 0x00440700, 0x0004C424, 0x00442900,
        0x00441E00, 0x00441F00, 0x00442000, 0x00442100, 0x00442200,
        0x00044428, 0x00000000, 0x000AC462, 0x000AC469, 0x00000000,
        0x0004C428, 0x0000000C, 0x00445E00, 0x00048C40, 0x00000005,
        0x00000000, 0x0004446C, 0x00050C03, 0x0044F400, 0x00800000,
        0x000CC901, 0x00000000, 0x0008C40D, 0x0044FE00, 0x00000004,
        0x00445E00, 0x000CC901, 0x00000000, 0x0008F48D, 0x00000001,
        0x000CC902, 0x00000000, 0x0008440B, 0x00000000, 0x000C82B4,
        0x0000000E, 0x0006C400, 0x0000051C, 0x00048C60, 0x00000004,
        0x0000008C, 0x00050C05, 0x0004446C, 0x000CC901, 0x00000000,
        0x0008C40D, 0x00000000, 0x00000000, 0x000CC901, 0x00000000,
        0x0008F48D, 0x00800000, 0x0044FE00, 0x00000004, 0x000C8390,
        0x00000026, 0x000C83B1, 0x00000024, 0x000A0331, 0x0046A900,
        0x00000000, 0x000AC642, 0x000AC645, 0x000C8189, 0x00000004,
        0x000AC662, 0x00000000, 0x00462900, 0x000C8188, 0x00000003,
        0x000AC644, 0x0004C630, 0x000C8294, 0x00000005, 0x0008F4AF,
        0x00000000, 0x000AA037, 0x00468200, 0x00000000, 0x000CC683,
        0x00000005, 0x000CC6A4, 0x00000003, 0x00010B20, 0x000CC686,
        0x00000005, 0x000CC6A7, 0x00000003, 0x00010F20, 0x00469E00,
        0x00000000, 0x00462100, 0x0000000C, 0x000C8294, 0x00000003,
        0x000D04B7, 0x000C8391, 0x00000026, 0x0046F400, 0x00000000,
        0x00000000, 0x00462100, 0x000A0311, 0x0046A900, 0x00000000,
        0x000AC642, 0x000AC665, 0x00000000, 0x00462900, 0x0004C630,
        0x00468200, 0x00000000, 0x000CC683, 0x00000005, 0x000CC6A4,
        0x00000003, 0x00010B00, 0x000CC686, 0x00000005, 0x000CC6A7,
        0x00000003, 0x00010F00, 0x0006DC80, 0x0000056D, 0x00048C43,
        0x00000003, 0x0000008C, 0x00000000, 0x00000000, 0x00044628,
        0x00000000, 0x000AC662, 0x00000000, 0x0004C628, 0x0000000C,
        0x00459F00, 0x0007B488, 0x00000008, 0x00452100, 0x000C83A8,
        0x00000006, 0x000A0328, 0x000C8380, 0x00000003, 0x000A0122,
        0x0000000C, 0x0045A000, 0x0007B488, 0x00000000, 0x00452100,
        0x000C83A9, 0x00000006, 0x000A0329, 0x000C8381, 0x00000003,
        0x000A0122, 0x0000000C, 0x000D01C0, 0x0004C827, 0x000C01C7,
        0x000D01C0, 0x00502E00, 0x000D04D6, 0x000C01C7, 0x000AAC37,
        0x00000004, 0x00000004, 0x000CEC37, 0x00000000, 0x0008F4AF,
        0x00000000, 0x00000004, 0x0008F4A2, 0x00000000, 0x000A0122,
        0x000A0108, 0x000AA037, 0x00000004 }},
    { 0x00000001, 0x0000059F, 0x000001F0,
      { 0x000D01C0, 0x000AC877, 0x00000000, 0x00210500, 0x000D06A5,
        0x000CC902, 0x00000000, 0x0008440B, 0x00450A00, 0x00440E00,
        0x000CC5A0, 0x0000000D, 0x000CC581, 0x0000000B, 0x000CC5A2,
        0x00000006, 0x000A2324, 0x000A2424, 0x000A2524, 0x00050C04,
        0x000A2325, 0x000A2425, 0x000A2525, 0x000CC587, 0x00000009,
        0x000CC5A8, 0x00000005, 0x000A2320, 0x000A2520, 0x00050C03,
        0x000A2322, 0x000A2522, 0x000CC589, 0x00000007, 0x000CC5AA,
        0x00000004, 0x000A2421, 0x00050C02, 0x000A2423, 0x0046A300,
        0x00000000, 0x00462600, 0x000C01C7, 0x000D01C0, 0x0007F407,
        0x00008310, 0x0004C885, 0x00010722, 0x000C01C7, 0x000D01C0,
        0x000003F8, 0x00210C00, 0x00518B00, 0x00448B00, 0x00210500,
        0x00200046, 0x000C1CA5, 0x000C1960, 0x00009018, 0x00000000,
        0x000C1930, 0x0000202A, 0x00000000, 0x00540B00, 0x000C01C7,
        0x000C8B93, 0x00000016, 0x000C8AAD, 0x00000014, 0x00478B00,
        0x00000000, 0x000CC795, 0x00000008, 0x000CC7AD, 0x00000006,
        0x000A0B2D, 0x000CC784, 0x00000003, 0x000A0122, 0x000CC796,
        0x00000008, 0x000CC7AC, 0x00000006, 0x000A0B2C, 0x000CC783,
        0x00000003, 0x000A0122, 0x0000000C, 0x00445E00, 0x00448B00,
        0x000CC901, 0x00000000, 0x0008C40D, 0x0044FE00, 0x00000004,
        0x000D01C0, 0x000CC8A0, 0x00000005, 0x000A0B12, 0x000D0623,
        0x00050C03, 0x000A0B32, 0x000D060D, 0x000C01C7, 0x000D0176,
        0x000D062B, 0x000C01C7, 0x000D0176, 0x000D063A, 0x000C01C7,
        0x000C8B92, 0x00000015, 0x000C8BB3, 0x00000013, 0x000C8A80,
        0x0000000C, 0x000C8AA1, 0x0000000A, 0x000C8AA6, 0x00000006,
        0x0007F407, 0x00008310, 0x000D10C0, 0x00000004, 0x0007F407,
        0x00000310, 0x00010722, 0x000A0B33, 0x00469E00, 0x00000000,
        0x00462100, 0x0000000C, 0x000C8B93, 0x00000007, 0x000A0B13,
        0x0046F400, 0x00000000, 0x00000000, 0x00462100, 0x0000000C,
        0x0045A400, 0x00000000, 0x00452600, 0x000C8A80, 0x00000005,
        0x000C8AA1, 0x00000003, 0x00010720, 0x000C8BA9, 0x00000006,
        0x000A0B29, 0x000C8B80, 0x00000003, 0x000A0122, 0x0000000C,
        0x0045A500, 0x00000000, 0x00452600, 0x000C8A80, 0x00000005,
        0x000C8AA1, 0x00000003, 0x00010700, 0x000C8BAA, 0x00000006,
        0x000A0B2A, 0x000C8B81, 0x00000003, 0x000A0122, 0x0000000C,
        0x0045A500, 0x00000000, 0x00452600, 0x000D064F, 0x00000000,
        0x0000000C, 0x00505F00, 0x00545F00, 0x00525F00, 0x00445F00,
        0x00455F00, 0x00605F00, 0x00055F20, 0x000C94AF, 0x0000001E,
        0x000C94B0, 0x0000001C, 0x000C94B1, 0x0000001A, 0x000C8B95,
        0x00000016, 0x000C8A8D, 0x0000000D, 0x000A0B15, 0x00200013,
        0x0054B400, 0x000140C5, 0x00000000, 0x0005A442, 0x0004CCA0,
        0x00503700, 0x00053620, 0x00053520, 0x00050C08, 0x000C8BB0,
        0x00000006, 0x000A0B30, 0x000C8B87, 0x00000003, 0x000A0122,
        0x00050C16, 0x000D074E, 0x00050C14, 0x00509400, 0x00000000,
        0x000CC88F, 0x00000004, 0x000AC849, 0x00000000, 0x000CC890,
        0x00000004, 0x000AC84A, 0x00000000, 0x000CC891, 0x00000003,
        0x000AC84B, 0x000C1880, 0x0000C000, 0x00000000, 0x00501400,
        0x0004C864, 0x00010700, 0x0005FF20, 0x0060FF00, 0x0045FF00,
        0x0044FF00, 0x0052FF00, 0x0054FF00, 0x0050FF00, 0x0000000C,
        0x000C8B93, 0x0000000A, 0x000C8B95, 0x00000008, 0x000D064F,
        0x000CC901, 0x00000000, 0x0008F48D, 0x00000001, 0x00000004,
        0x000CC901, 0x00000000, 0x0008F48D, 0x00800000, 0x00000004,
        0x000D0176, 0x000D0707, 0x000D06B9, 0x000C01C7, 0x000D0176,
        0x000D06A5, 0x000C01C7, 0x0044F400, 0x00000000, 0x00010700,
        0x00440A00, 0x00440B00, 0x000A0B35, 0x00440C00, 0x00440D00,
        0x00440E00, 0x0007F407, 0x00008310, 0x0004C485, 0x00442300,
        0x00442400, 0x00442500, 0x00442600, 0x00442700, 0x000D0707,
        0x000D06B9, 0x0000000C, 0x00200013, 0x00000000, 0x00084C07,
        0x00000000, 0x0050F400, 0x00800800, 0x000D06C1, 0x0000000C,
        0x0004C8DC, 0x00000000, 0x00000000, 0x0001B786, 0x000006C4,
        0x0000000C, 0x000D01C0, 0x0001B786, 0x000006C8, 0x0004C8DC,
        0x000A0B2B, 0x000C01C7, 0x000D0176, 0x000C8A8D, 0x00000006,
        0x00010700, 0x000D0707, 0x0054B300, 0x00050C05, 0x0044B500,
        0x0054B300, 0x00000000, 0x00200044, 0x000CC901, 0x00000000,
        0x0008CC0D, 0x00200003, 0x00000000, 0x0005A41D, 0x000CC902,
        0x00000000, 0x0008440B, 0x000C8A8D, 0x00000004, 0x00443400,
        0x00050C05, 0x0054F400, 0x000007FF, 0x00000000, 0x00543400,
        0x000C8A97, 0x0000000A, 0x00208C00, 0x00000000, 0x000140C5,
        0x00000400, 0x00052403, 0x000D0711, 0x00050C09, 0x000A0A17,
        0x0006C400, 0x000006F9, 0x000CC902, 0x00000000, 0x0008440B,
        0x000D0730, 0x00000000, 0x000C8AAD, 0x00000006, 0x000C8AB2,
        0x00000004, 0x000D10C0, 0x00000005, 0x00010720, 0x000A0B32,
        0x00010722, 0x000C01C7, 0x000003F8, 0x000D064F, 0x00000004,
        0x00200013, 0x00000000, 0x0054F400, 0x00000000, 0x00000000,
        0x00503500, 0x00543600, 0x00543700, 0x00543400, 0x0000000C,
        0x00200013, 0x00208800, 0x0008F49B, 0x00FFFFCB, 0x0000000A,
        0x0008F498, 0x000EE2C4, 0x0008F09A, 0x00000036, 0x0008C819,
        0x000003F8, 0x0060B600, 0x00209800, 0x0005B420, 0x00000000,
        0x00000000, 0x00000000, 0x00204800, 0x00603600, 0x0054B500,
        0x0070F400, 0x00000000, 0x00200040, 0x00000000, 0x00543500,
        0x0000FEB8, 0x000A9837, 0x000CD837, 0x00000000, 0x000A0B15,
        0x0000000C, 0x000003F8, 0x00200013, 0x000C8BB7, 0x0000001A,
        0x0054B500, 0x00000000, 0x000140C5, 0x00000800, 0x00000000,
        0x00051412, 0x0060B600, 0x0005B420, 0x000C1C30, 0x00000008,
        0x000A0B15, 0x00503500, 0x004C5800, 0x00603600, 0x000C1D30,
        0x000140C5, 0x00000400, 0x00000000, 0x0005F403, 0x000A0B16,
        0x00050C04, 0x000A0B36, 0x00050C02, 0x000A0B37, 0x0000FEB8,
        0x0000000C, 0x00200013, 0x000C8BB5, 0x00000023, 0x0054B500,
        0x00000000, 0x000140C5, 0x00000000, 0x00000000, 0x0005A41A,
        0x000140C5, 0x00000001, 0x00000000, 0x0005F402, 0x00050C02,
        0x000A0B35, 0x0060B700, 0x0005B420, 0x000C1C30, 0x0000000A,
        0x000A0B17, 0x00503500, 0x004CD800, 0x00603700, 0x0004C4DC,
        0x000C1D30, 0x00280000, 0x000140C5, 0x00000400, 0x00000000,
        0x0005F403, 0x000A0B16, 0x00050C05, 0x000A0B36, 0x00050C03,
        0x000A0B35, 0x00050C01, 0x0000000C, 0x000D0176, 0x000003F8,
        0x0060B600, 0x00209800, 0x0005B420, 0x00000000, 0x00000000,
        0x00000000, 0x00204800, 0x00603600, 0x0054B500, 0x0070F400,
        0x00000000, 0x00200040, 0x00000000, 0x00543500, 0x000140C5,
        0x00000400, 0x00000000, 0x0000FEB8, 0x0005F403, 0x000A0B16,
        0x00050C03, 0x000A0B36, 0x00050C01, 0x000C01C7, 0x000D01C0,
        0x000C01C7 }},
    { 0x00000001, 0x0000078F, 0x00000035,
      { 0x000D01C0, 0x000BF080, 0x000007AF, 0x00500F00, 0x0004C83C,
        0x000C1C0C, 0x00000000, 0x0004C838, 0x000C01C7, 0x000D0176,
        0x00044C74, 0x00000000, 0x000C1C10, 0x00000000, 0x00044C60,
        0x00000000, 0x000C1880, 0x00010010, 0x000C01C9, 0x000D0176,
        0x00044874, 0x00000000, 0x000C1880, 0x00010000, 0x000C01C9,
        0x000D0176, 0x00044460, 0x000C01C7, 0x000D0176, 0x000BF080,
        0x000007AF, 0x000C01C7, 0x00044468, 0x00000000, 0x000AC446,
        0x000AC447, 0x000AC463, 0x000AC464, 0x000AC465, 0x000AC469,
        0x000AC46A, 0x00000000, 0x0004C468, 0x0044F400, 0x00000000,
        0x00000000, 0x00441100, 0x0004C43C, 0x00440F00, 0x0004C438,
        0x00441000, 0x00044460, 0x0000000C }},
    { 0x00000001, 0x000007C4, 0x00000011,
      { 0x000D01C0, 0x000C1880, 0x00010000, 0x00000000, 0x0004C874,
        0x000C01C7, 0x000D0176, 0x000BF080, 0x000007CE, 0x000C01C7,
        0x0044F400, 0x00000000, 0x00000000, 0x00441200, 0x00441300,
        0x0004C474, 0x0000000C }},
    { 0x00000001, 0x000007D5, 0x0000011E,
      { 0x000D01C0, 0x000D08C2, 0x000C1880, 0x00012000, 0x00000000,
        0x000CC88F, 0x00000012, 0x000AC840, 0x00000000, 0x000AC841,
        0x00000000, 0x000AC846, 0x00000000, 0x000AC869, 0x00000000,
        0x0004C864, 0x00000000, 0x00505E00, 0x0050F400, 0x00FFFF30,
        0x000D085B, 0x0050FE00, 0x00000000, 0x000CC890, 0x00000012,
        0x000AC842, 0x00000000, 0x000AC843, 0x00000000, 0x000AC847,
        0x00000000, 0x000AC86A, 0x00000000, 0x0004C864, 0x00000000,
        0x00505E00, 0x0050F400, 0x00FFFF70, 0x000D085B, 0x0050FE00,
        0x00000000, 0x000CC891, 0x00000012, 0x000AC844, 0x00000000,
        0x000AC845, 0x00000000, 0x000AC848, 0x00000000, 0x000AC86B,
        0x00000000, 0x0004C864, 0x00000000, 0x00505E00, 0x0050F400,
        0x00FFFFB0, 0x000D085B, 0x0050FE00, 0x00000000, 0x000CC8AF,
        0x00000006, 0x000CC8B0, 0x00000004, 0x000CC891, 0x00000029,
        0x000D08B8, 0x00061EA0, 0x00000000, 0x000D08B8, 0x00061EA0,
        0x00000000, 0x000D08B8, 0x00061EA0, 0x00000000, 0x000D08B8,
        0x00061EA0, 0x00000000, 0x000CC88F, 0x00000006, 0x000AC860,
        0x00000000, 0x000AC861, 0x00000000, 0x000CC890, 0x00000006,
        0x000AC862, 0x00000000, 0x000AC863, 0x00000000, 0x000CC891,
        0x00000006, 0x000AC864, 0x00000000, 0x000AC865, 0x00000000,
        0x00010700, 0x0007F406, 0x00000000, 0x0007F407, 0x00008114,
        0x00519600, 0x00000000, 0x0004C985, 0x00010720, 0x00501400,
        0x0004C864, 0x000C01C7, 0x000D0176, 0x000D0843, 0x000C01C9,
        0x0004482C, 0x00000000, 0x000C1C0A, 0x00000000, 0x00044C68,
        0x00000000, 0x000C1920, 0x0000301B, 0x00000000, 0x00519400,
        0x00000000, 0x000C1C9D, 0x00000000, 0x000C1930, 0x0000301E,
        0x000140C6, 0x000001FF, 0x000C1C30, 0x00000000, 0x00501500,
        0x0000000C, 0x000D01C0, 0x000D085B, 0x000C01C7, 0x00210400,
        0x000CC8A7, 0x0000000A, 0x000CC8A6, 0x00000005, 0x0060F400,
        0x00BFF0C0, 0x00050C09, 0x0060F400, 0x00BFF0C1, 0x00050C06,
        0x000CC8A6, 0x00000005, 0x0060F400, 0x00BFF0C2, 0x00050C01,
        0x000C1881, 0x00008000, 0x00000000, 0x00597000, 0x00BFF0C3,
        0x000CC484, 0x00000006, 0x000C1881, 0x00008008, 0x00000000,
        0x00596000, 0x000CC485, 0x00000006, 0x000C1881, 0x00008010,
        0x00000000, 0x00596000, 0x0000000C, 0x000D01C0, 0x000CC888,
        0x00000007, 0x000C1881, 0x00008000, 0x00000000, 0x00597000,
        0x00BFF0C3, 0x000CC8AA, 0x0000000A, 0x000CC8A9, 0x00000005,
        0x0060F400, 0x00BFF0C0, 0x00050C0C, 0x0060F400, 0x00BFF0C1,
        0x00050C09, 0x000CC8A9, 0x00000005, 0x0060F400, 0x00BFF0C2,
        0x00050C04, 0x0050F400, 0x00800000, 0x000C01C9, 0x000C1880,
        0x0000200B, 0x0020001B, 0x0006C800, 0x0000089E, 0x005DE000,
        0x000C1C91, 0x00000000, 0x0055F400, 0x00000000, 0x00000000,
        0x0006C820, 0x000C1D91, 0x00000000, 0x0021A800, 0x000C01C9,
        0x000D01C0, 0x00549400, 0x00000000, 0x000C1920, 0x00003021,
        0x00000000, 0x00541400, 0x0004CC64, 0x000C01C7, 0x00445E00,
        0x000D08B8, 0x000CC901, 0x00000000, 0x0008F48D, 0x00000001,
        0x0044FE00, 0x00000004, 0x00044428, 0x00000000, 0x000AC468,
        0x00000000, 0x0004C428, 0x0000000C, 0x000D0176, 0x000D08CC,
        0x000D08C2, 0x000C01C7, 0x0044F400, 0x00000000, 0x00044C68,
        0x00441400, 0x000140C6, 0x00FFFFC0, 0x0004C464, 0x00441500,
        0x0004CC68, 0x0000000C, 0x0044F400, 0x00000000, 0x0045F400,
        0x00000036, 0x0007B4A4, 0x00000015, 0x00000000, 0x004D7000,
        0x00BFF0C3, 0x00000000, 0x004C7000, 0x00BFF0C0, 0x0045F400,
        0x00000076, 0x004C7000, 0x00BFF0C0, 0x00000000, 0x004D7000,
        0x00BFF0C3, 0x00000000, 0x004C7000, 0x00BFF0C1, 0x0045F400,
        0x000000B6, 0x004C7000, 0x00BFF0C1, 0x00000000, 0x004D7000,
        0x00BFF0C3, 0x00000000, 0x004C7000, 0x00BFF0C2, 0x00000000,
        0x004C7000, 0x00BFF0C2, 0x0000000C, 0x000D01C0, 0x00501600,
        0x000C01C7 }},
    { 0x00000001, 0x000008F3, 0x00000013,
      { 0x000D01C0, 0x00655E00, 0x00211500, 0x000CC902, 0x00000000,
        0x0008480B, 0x00000000, 0x00586500, 0x0065FE00, 0x000C01C7,
        0x000D01C0, 0x00655E00, 0x00211500, 0x00000000, 0x00000000,
        0x00000000, 0x0058E500, 0x0065FE00, 0x000C01C9 }},
    { 0x00000001, 0x00000906, 0x00000050,
      { 0x000D01C0, 0x000C01C7, 0x000D01C0, 0x00010702, 0x00210900,
        0x000CC88C, 0x0000001B, 0x0007F43D, 0x0000003F, 0x0007F43E,
        0x0000003F, 0x0007F43F, 0x00000000, 0x00000000, 0x00013D03,
        0x000CC8AD, 0x00000004, 0x00013D00, 0x00050C02, 0x00013D20,
        0x000CC8AE, 0x00000004, 0x00013D01, 0x00050C02, 0x00013D21,
        0x000CC8AF, 0x00000004, 0x00013D02, 0x00050C02, 0x00013D22,
        0x00013D04, 0x00050C0E, 0x0007F43D, 0x0000002F, 0x0007F43E,
        0x0000002F, 0x0007F43F, 0x00000004, 0x00000000, 0x00013D03,
        0x000CC8AB, 0x00000004, 0x00013D00, 0x00050C02, 0x00013D01,
        0x000C1D4A, 0x00060B80, 0x00000940, 0x00013D03, 0x00200033,
        0x00058403, 0x00013D05, 0x00050C03, 0x00013D25, 0x00050C01,
        0x00000000, 0x00013D23, 0x00000000, 0x00000000, 0x00060AA0,
        0x00000000, 0x00013D24, 0x00060AA0, 0x00000000, 0x00013D20,
        0x00013D21, 0x00000000, 0x000CC9AC, 0x0000000C, 0x0007F435,
        0x00180805, 0x0007F436, 0x00012C30, 0x0007F43D, 0x0000002F,
        0x0007F43E, 0x0000002F, 0x0007F43F, 0x0000002C, 0x000C01C7 }},
    { 0x00000001, 0x00000956, 0x00000005,
      { 0x000D01C0, 0x000A1A20, 0x000C01C9, 0x000A0122, 0x00000004 }},
    { 0x00000001, 0x0000095B, 0x00000075,
      { 0x00200013, 0x00000000, 0x0054F000, 0x00FFFFC7, 0x00000000,
        0x000140C5, 0x0000014B, 0x0005A40E, 0x000140C5, 0x0000014C,
        0x0005A40B, 0x000140C5, 0x0000014E, 0x0005A491, 0x000140C5,
        0x0000014F, 0x0005A48E, 0x000140C5, 0x00000150, 0x0005A48B,
        0x00050C9F, 0x00019381, 0x00000970, 0x0051F400, 0x00000015,
        0x000D03A2, 0x000140C2, 0x00FC0060, 0x00000000, 0x00219500,
        0x00000000, 0x00000000, 0x00000000, 0x00586500, 0x0051F400,
        0x00000016, 0x000D03A2, 0x000140C2, 0x00FC0064, 0x00000000,
        0x00219500, 0x00000000, 0x00000000, 0x00000000, 0x00586500,
        0x0065F400, 0x00FC0000, 0x0051F400, 0x00000025, 0x000D03A2,
        0x005C6500, 0x0065F400, 0x00FC0001, 0x0051F400, 0x00000026,
        0x000D03A2, 0x005C6500, 0x0065F400, 0x00FC0002, 0x0051F400,
        0x00000027, 0x000D03A2, 0x005C6500, 0x0065F400, 0x00FC0003,
        0x0051F400, 0x00000028, 0x000D03A2, 0x005C6500, 0x0065F400,
        0x00FC0004, 0x0051F400, 0x00000029, 0x000D03A2, 0x005C6500,
        0x0065F400, 0x00FC0005, 0x0051F400, 0x0000002A, 0x000D03A2,
        0x005C6500, 0x0065F400, 0x00FC0006, 0x0051F400, 0x0000002B,
        0x000D03A2, 0x005C6500, 0x0065F400, 0x00FC0007, 0x0051F400,
        0x0000002C, 0x000D03A2, 0x005C6500, 0x00050C16, 0x000D0381,
        0x00200013, 0x0064F400, 0x00000036, 0x00310000, 0x00228900,
        0x000D03A2, 0x00222D00, 0x000140CA, 0x00FFFF00, 0x0021B500,
        0x00205C00, 0x00205900, 0x00000000, 0x005C6500, 0x00222C00,
        0x00000000, 0x000140C5, 0x00000020, 0x0005A402, 0x00050FD1,
        0x00000000, 0x0000000C }},
    { 0x00000001, 0x000009D0, 0x0000004B,
      { 0x00000000, 0x000BF080, 0x00000170, 0x000BF080, 0x00000233,
        0x00000240, 0x0000026E, 0x0000033A, 0x00000354, 0x0000026F,
        0x00000277, 0x0000027B, 0x000002A7, 0x000002AA, 0x000002C1,
        0x000002C2, 0x0000031D, 0x0000032C, 0x000003EE, 0x00000431,
        0x0000043B, 0x00000445, 0x0000045B, 0x00000467, 0x00000478,
        0x00000483, 0x00000487, 0x0000048B, 0x00000497, 0x000004A3,
        0x000004AB, 0x000004B3, 0x000004F9, 0x00000506, 0x0000058A,
        0x0000058D, 0x0000059F, 0x000005CA, 0x000005D0, 0x000005F7,
        0x000005FE, 0x00000607, 0x0000060A, 0x0000068F, 0x0000069E,
        0x000006A2, 0x000006C7, 0x000006CD, 0x0000078D, 0x0000078F,
        0x00000798, 0x000007A2, 0x000007A8, 0x000007AB, 0x000007C4,
        0x000007CA, 0x000007D5, 0x00000840, 0x00000858, 0x0000087D,
        0x000008A7, 0x000008B0, 0x000008BE, 0x000008FD, 0x000008F3,
        0x00000906, 0x00000906, 0x00000906, 0x00000906, 0x00000906,
        0x00000908, 0x00000956, 0x00000959, 0x00000364, 0x00000591 }} };

//-----------------------------------------------------------------------
// end of pdfwmain_i.h