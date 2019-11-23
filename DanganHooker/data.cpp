#include "Data.h"
#include "Scripting.h"

using namespace std; 

const Data::DetourInfo Data::Dangan2DetourInfo[2] = 
{
	{0x332A0, 0x333AE,  Sound::VoiceLineMaths,  "FUNC_SOUND_VOICEMATH"},
	{0x7D2BE, 0x7D2C5, Scripting::GetOperationFunction, "INST_SCRIPTING_GET_OPFUNC"}
};

