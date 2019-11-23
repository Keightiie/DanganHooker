#include "data.h"
#include "detour.h"
#include "main.h"
#include "console.h"
#include "TestingFuncs.h"


using namespace std; 

DWORD OPCOdeFuncs[256] = {0x0};


DWORD jmpBackAdd = 0;
void __declspec(naked) grabOPThing()
{
	_asm
	{
		mov edx, OPCOdeFuncs[eax * 4]
		jmp[jmpBackAdd]
	}
}

const Functions::FunctionData Functions::DR2functions[2] = {
	{0x332A0, 0x10E,  Sound::VoiceLineMaths,  "FUNC_VOICEMATH"}, 
	{0x7D2BE, 0x7,  grabOPThing,  "INST_ReadOPFunc"}
};

void Functions::HookFunctions()
{
	
	for (int a = 0; a < 2; a++)
	{
		Detour::Hook(Functions::DR2functions[a].Address, Functions::DR2functions[a].Replacement, Functions::DR2functions[a].Size);
		Console::WriteLine("%s has been hooked!", Functions::DR2functions[a].Name);
	}
}

void Data::HookOPCodes()
{

	for (int a = 0; a < 77; a++)
	{
		DWORD result = Detour::GrabPointer(0x30B910 + (4 * a));
		OPCOdeFuncs[a] = result;

	}
	jmpBackAdd = Detour::GetExactAddress(0x7D2BE + 0x7);
	OPCOdeFuncs[0xFF] = (DWORD)&TestingFuncs::CustomOPCodeTest;

	Detour::WriteByte(0x7D2B8, 0xFF);

}

