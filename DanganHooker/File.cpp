#include "File.h"
#include "data.h"
#include "console.h"
#include "MemoryAddresses.h"
#include <iostream>


using namespace std;

const char * LanguageDirs[] = {"jp", "us", "ch", "sp"};

const char * ArchiveRoots[] = {"archive:DrCommon/", "archive:Dr1/", "archive:Dr2/", "DrCommon/",  "Dr2/", "Dr1/" };
const char * ArchiveFolderNames[] = { "bgm", "bin", "cg", "flash", "model", "modelbg", "module", "se", "texture", "texture/low", "bin", "cg", "flash", "font", "icon", "movie", "script", "voice", "texture", "save_icon" };



void File::FUN_004c56a0(char* ResultDest, char* fileName, int a3)
{
	char v4[64];
	char v3[300];
	DWORD CurrentGame = CommonAddresses::CUR_FOLDER_ROOT[Data::Game];
	int CurrentRootFolder = *(int*)AbsoluteAddress(CurrentGame);

	if (a3 < 10) {
		sprintf(v4, "data/all/%s/%s", ArchiveFolderNames[a3], fileName);
	}
	else {
		if (0x13 < a3) goto LAB_004c56ec;
		sprintf(v4, "data/us/%s/%s", ArchiveFolderNames[a3], fileName);
	}
LAB_004c56ec:
	sprintf(ResultDest, "%s%s", (&*(DWORD*)(AbsoluteAddress(0x298644)))[CurrentRootFolder], v4);

	Console::WriteLine("[GAME] Loading file: %s", v4);
	return;
}




void File::FUN_004c58c0(char* ResultDest, char* fileName, int a3)
{
	return;
}

void File::FUN_004c5b00(char* filename, int param2, int *param3)
{

	typedef char** (*LoadFile)(char* param_1, char* param_1_00, char* param_2);

	LoadFile ogLoadFile = (LoadFile)AbsoluteAddress(0xFC6A0);

	DWORD CurrentGame = CommonAddresses::CUR_FOLDER_ROOT[Data::Game];
	int CurrentRootFolder = *(int*)AbsoluteAddress(CurrentGame);

	UINT uVar1 = 0;
	//  undefined4 uVar2;
	//  int iVar3;
	//  int **in_FS_OFFSET;
	const char *Format;
	const char *puVar4;
	//  undefined local_164 [4];
	//  undefined4 local_160;
	//  undefined4 local_15c;
	//  int *local_158;
	char local_154 [256];
	char local_54 [64];
	//  uint local_14;
	//  int *local_10;
	//  undefined *puStack12;
	//  undefined4 local_8;
	//  
	//  local_8 = 0xffffffff;
	//  puStack12 = &LAB_005fb331;
	//  local_10 = *in_FS_OFFSET;
	//  uVar1 = DAT_006a2588 ^ (uint)&stack0xfffffffc;
	//  *(int ***)in_FS_OFFSET = &local_10;
	//  iVar3 = 0;
	//  local_14 = uVar1;


	if (param2 < 10) {
	puVar4 = ArchiveFolderNames[param2];
	Format = "data/all/%s/%s";
LAB_004c5b61:
	sprintf(local_54, Format, puVar4, filename, uVar1);
	}
	else {
	  if (param2 < 0x14) {
		  puVar4 = ArchiveFolderNames[param2];
		  Format = "data/us/%s/%s";
	    goto LAB_004c5b61;
	  }
	}
	sprintf(local_154,"%s%s", ArchiveRoots[CurrentRootFolder],local_54,uVar1);


	//  local_160 = 0;
	//ogLoadFile(local_154, 0x0, 0x0);
	//  FUN_004fd6a0(local_154,0xffffffff);
	//  local_8 = 0;
	//  FUN_005011a0();
	//  local_8 = 1;
	//  local_15c = 0;
	//  local_158 = (int *)0x0;
	//  FUN_00501d70(&local_15c,local_164,1,1);
	//  local_8 = CONCAT31(local_8._1_3_,2);
	//  if ((local_158 != (int *)0x0) && (local_158[8] != 0)) {
	//    iVar3 = (**(code **)(*local_158 + 0x10))();
	//    if (iVar3 == 0) goto LAB_004c5c3c;
	//    uVar2 = FUN_004d64f0(iVar3 + 4,0x40,0xe);
	//    (**(code **)(*local_158 + 8))(uVar2,iVar3);
	//  }
	//  if (param_3 != (int *)0x0) {
	//    *param_3 = iVar3;
	//  }
	//LAB_004c5c3c:
	//  local_8 = CONCAT31(local_8._1_3_,1);
	//  FUN_00516b40();
	//  local_8 = 0xffffffff;
	//  FUN_004fd890();
	//  *in_FS_OFFSET = local_10;
	//  FUN_005c6ff4();
	Console::WriteLine("[DEBUG] FUN_004c5b00: %s", local_154);








	return;
}



bool File::FileExists(const char * filename)
{
	ifstream ifile(filename);
	if (ifile) {
		return true;
	}
	else { return false; }
}

