#include "File.h"
#include "data.h"
#include "console.h"
#include <iostream>

using namespace std;

const char * ModName = "MyFirstMod";
const char * LanguageDirs[] = {"jp", "us", "ch", "sp"};
const char * GameDir = "E:/Games/SteamLibrary/steamapps/common/Danganronpa 2 Goodbye Despair/";
const char * ArchiveRoots[] = {"archive:DrCommon/", "archive:Dr1/", "archive:Dr2/", "mods/MyFirstMod/Dr2/"};
const char * ArchiveFolderNames[] = { "bin", "cg", "flash", "model", "modelbg", "module", "se", "texture", "texture/low", "bin", "cg", "flash", "font", "icon", "movie", "script", "voice", "texture", "save_icon" };

int File::GetFilePath(char * ResultDest, char * a2, int a3)
{
	char v4 [64];
	char v3[300];

	int RootDirectory;

	if (a3 >= 10)
	{
		if (a3 < 20)
		{
			std::snprintf(v4, 64, "data/%s/%s/%s", LanguageDirs[Data::Langauge] ,ArchiveFolderNames[a3 - 1], a2);
		}
	}
	else
	{
		std::snprintf(v4, 64, "data/all/%s/%s", ArchiveFolderNames[a3 - 1], a2);
	}
	sprintf(v3, "%s%s%s", GameDir, ArchiveRoots[3], v4);
	if (FileExists(v3)) 
	{
		sprintf(v3, "[GAME] Loading modded file: %s", v4);
		Console::WriteLine(v3);
		return sprintf(ResultDest, "%s%s", ArchiveRoots[3], v4);
	}
	sprintf(v3, "[GAME] Loading file: %s", v4);
	Console::WriteLine(v3);
	return sprintf(ResultDest, "%s%s", ArchiveRoots[2], v4);

}

bool File::FileExists(const char * filename)
{
	ifstream ifile(filename);
	if (ifile) {
		return true;
	}
	else { return false; }
}

