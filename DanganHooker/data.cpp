#include "Data.h"
#include "Scripting.h"
#include "File.h"

using namespace std; 

string Data::GamePath = "";
string Data::ModName = "MyFirstMod";

int Data::Game = -1;

const Data::DetourInfo Data::DanganDetourInfo[2] =
{
	{0xC46A0, 0xC4717, File::GetFilePath, "FUNC_FILE_GETPATH"},
	{0x4D178, 0x4D17F, Scripting::GetOperationFunction, "INST_SCRIPTING_GET_OPFUNC"}
};
const Data::DetourInfo Data::Dangan2DetourInfo[3] = 
{
	{0x332A0, 0x333AE,  Sound::VoiceLineMaths,  "FUNC_SOUND_VOICEMATH"},
	{0x7D2BE, 0x7D2C5, Scripting::GetOperationFunction, "INST_SCRIPTING_GET_OPFUNC"},
	{0xEFCD0, 0xEFD47, File::GetFilePath, "FUNC_FILE_GETPATH"}
};




