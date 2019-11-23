#include "Scripting.h"
#include "data.h"
#include "console.h"

DWORD Scripting::OperationFunctions[Cnt_opcodes];
DWORD Scripting::ADDRESS_ReturnGetOpFunc = 0;

void __declspec(naked) Scripting::GetOperationFunction()
{
	_asm
	{
		mov edx, OperationFunctions[eax * 4]
		jmp[ADDRESS_ReturnGetOpFunc]
	}
}

void Scripting::LoadCustomOpcodes()
{
	Scripting::OperationFunctions[0xFF] = (DWORD)&Scripting::TEST_CustomOpcode;
}

void Scripting::TEST_CustomOpcode()
{
	Console::WriteLine("[GAME] Custom opcode 0x70FF has been called successfully!");
}

