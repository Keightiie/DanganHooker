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
	int CurrentRootFolder = *(int*)AbsoluteAddress(CommonAddresses::CUR_FOLDER_ROOT[Data::Game]);

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

void File::FUN_004c5b00(char* ResultDest, char* fileName, int a3)
{
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

