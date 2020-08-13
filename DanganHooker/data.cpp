#include "Data.h"
#include "Scripting.h"
#include "File.h"
#include "MemoryAddresses.h"

using namespace std; 

string Data::GamePath;
string Data::ModName = "MyFirstMod";

int Data::Game = -1;

const Data::DetourInfo Data::DanganDetourInfo[3] =
{
	{Dr1Addresses::FILE_PATH_START, Dr1Addresses::FILE_PATH_END, File::FUN_004c56a0, "FUNC_FILE_GETPATH"},
	{Dr1Addresses::FILE_PATH2_START, Dr1Addresses::FILE_PATH2_END, File::FUN_004c5b00, "FUNC_FILE_GETPATH2"},
	{Dr1Addresses::OPCODE_START, Dr1Addresses::OPCODE_END, Scripting::GetOperationFunction, "INST_SCRIPTING_GET_OPFUNC"}
};
const Data::DetourInfo Data::Dangan2DetourInfo[3] = 
{
	{Dr2Addresses::VOICELINE_START, Dr2Addresses::VOICELINE_END,  Sound::VoiceLineMaths,  "FUNC_SOUND_VOICEMATH"},
	{Dr2Addresses::OPCODE_START, Dr2Addresses::OPCODE_END, Scripting::GetOperationFunction, "INST_SCRIPTING_GET_OPFUNC"},
	{Dr2Addresses::FILE_PATH_START, Dr2Addresses::FILE_PATH_END, File::FUN_004c56a0, "FUNC_FILE_GETPATH"}
};




