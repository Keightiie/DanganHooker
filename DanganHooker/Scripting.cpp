#include "Scripting.h"
#include "data.h"
#include "console.h"
#include "MemoryAddresses.h"

DWORD Scripting::OperationFunctions[Cnt_opcodes];

void __declspec(naked) Scripting::GetOperationFunction()
{
	_asm
	{
		mov edx, OperationFunctions[eax * 4]
		jmp[CommonAddresses::ReturnGetOpFunc]
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

