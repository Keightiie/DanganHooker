#include "Debug.h"
#include "MemoryAddresses.h"

BYTE * Debug::Menu = (BYTE*)AbsoluteAddress(0x2A74B0);

int Debug::FUN_004d7850() 
{
	return *(int*)AbsoluteAddress(0x347228);
}

int Debug::FUN_004d7870(void)

{
	return *(int*)AbsoluteAddress(0xD6870);
}


void Debug::TopMenu()
{

	float fVar1;
	char cVar2;
	int uVar3;
	int iVar4;
	char *pcVar5;
	char local_48[64];
	int local_8;

	BYTE *DAT_006a84b1 = (BYTE*)AbsoluteAddress(0x2A74B1);
	
	int* DAT_006a2588 = (int*)AbsoluteAddress(0x2A1588);
	//int local_8 = DAT_006a2588 ^ (uint)&stack0xfffffffc;

	*(int*)AbsoluteAddress(0x2A8B38) = 0;
	*(int*)AbsoluteAddress(0x2A7C20) = 0;
	
	uVar3 = FUN_004d7850();
	if ((uVar3 & 0x100001) == 0) {
		uVar3 = FUN_004d7850();
		if ((uVar3 & 0x200002) != 0) {
			DAT_006a84b1 = DAT_006a84b1 + 1;
		}
	}
	else {
		DAT_006a84b1 = DAT_006a84b1 - 1;
	}
	if (*DAT_006a84b1 < 2) {
		*DAT_006a84b1 = 8;
	}
	else {
		if (8 < *DAT_006a84b1) {
			*DAT_006a84b1 = 2;
		}
	}
	uVar3 = FUN_004d7870();
	if ((uVar3 & 0x20) != 0) {
		*Menu = *DAT_006a84b1;
		*(BYTE*)AbsoluteAddress(0x2A74B2) = 0;
	}
	uVar3 = FUN_004d7870();
	if ((uVar3 & 0x10) != 0) {
		*(BYTE*)AbsoluteAddress(0x2A8B38) = 0; 
		*(BYTE*)AbsoluteAddress(0x2A7C20) = 0;
		Menu = 0;
	}
	iVar4 = 0x14;
	//fVar1 = *(float*)AbsoluteAddress(0x354BE0)[(int)((float)(((float)AbsoluteAddress(0x354BE0)33F3C4 << 2) % 0xb4) * 3.14159274 * 0.00555556 * 651.89862061 ) & 0xfff];
	//FUN_004135b0(0, 0, 0x80, 0x5a, 0x8000, 0);
	Console::DebugConsole(0, 0, "DEBUG : TOP_MENU");
	uVar3 = 2;


	do {
		DWORD aadd = 0x28CB80 + (4 * uVar3);
		char * test = (char *)(DWORD *)AbsoluteAddress(aadd);

		sprintf_s(local_48, "%s", test);
		if (uVar3 == (int)*DAT_006a84b1) {
			pcVar5 = local_48;
			do {
				cVar2 = *pcVar5;
				pcVar5 = pcVar5 + 1;
			} while (cVar2 != '\0');
			//FUN_004135b0(8, iVar4, &DAT_00623db0); 222DB0
			//FUN_004135b0(8, iVar4 + 6, (int)(pcVar5 + -(int)(local_48 + 1)) * 8 + 8, 2,
			//	(uint)((ushort)(int)(fVar1 * 15.00000000) & 0xff | 0xf000), 0);
		}
		Console::DebugConsole(0x10, iVar4, local_48);
		uVar3 = uVar3 + 1;
		iVar4 = iVar4 + 10;
	} while ((int)uVar3 < 9);
	Console::DebugConsole(300, 0, "CIRCLE    : RETURN");
	Console::DebugConsole(300, 10, "CROSS     : END");
	//FUN_005c6ff4();
	return;
}
