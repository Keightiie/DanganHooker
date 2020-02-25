#include "File.h"
#include "data.h"
#include "console.h"
#include <iostream>


using namespace std;

const char * LanguageDirs[] = {"jp", "us", "ch", "sp"};

const char * ArchiveRoots[] = {"archive:DrCommon/", "archive:Dr1/", "archive:Dr2/", "DrCommon/",  "Dr2/", "Dr1/" };
const char * ArchiveFolderNames[] = { "bin", "cg", "flash", "model", "modelbg", "module", "se", "texture", "texture/low", "bin", "cg", "flash", "font", "icon", "movie", "script", "voice", "texture", "save_icon" };

int File::GetFilePath(char * ResultDest, char * FileName, int a3)
{
	char v4[64];
	char v3[300];

	int RootDirectory;

	if (a3 >= 10)
	{
		if (a3 < 20)
		{
			std::snprintf(v4, 64, "data/%s/%s/%s", LanguageDirs[Data::Langauge], ArchiveFolderNames[a3 - 1], FileName);
		}
	}
	else
	{
		std::snprintf(v4, 64, "data/all/%s/%s", ArchiveFolderNames[a3 - 1], FileName);
	}


	if (Data::Game == Data::Games::DR1)
	{
		sprintf(v3, "%s/mods/%s/%s%s", &Data::GamePath[0], &Data::ModName[0], ArchiveRoots[5], v4);

		if (FileExists(v3))
		{
			Console::WriteLine("[GAME] Loading modded file: %s", v4);
			return sprintf(ResultDest, "mods/%s/%s%s", &Data::ModName[0], ArchiveRoots[5], v4);
		}

		Console::WriteLine("[GAME] Loading file: %s", v4);
		return sprintf(ResultDest, "%s%s", ArchiveRoots[1], v4);

	}

	if (Data::Game == Data::Games::DR2)
	{
		sprintf(v3, "%s/mods/%s/%s%s", &Data::GamePath[0], &Data::ModName[0], ArchiveRoots[4], v4);

		if (FileExists(v3))
		{
			Console::WriteLine("[GAME] Loading modded file: %s", v4);
			return sprintf(ResultDest, "mods/%s/%s%s", &Data::ModName[0], ArchiveRoots[4], v4);
		}

		Console::WriteLine("[GAME] Loading file: %s", v4);
		return sprintf(ResultDest, "%s%s", ArchiveRoots[2], v4);
	}



}

bool File::FileExists(const char * filename)
{
	ifstream ifile(filename);
	if (ifile) {
		return true;
	}
	else { return false; }
}

