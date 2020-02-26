#include "Scripting.h"
#include "data.h"
#include "console.h"
#include "Hook.h"
#include "MemoryAddresses.h"

DWORD Scripting::OperationFunctions[Cnt_opcodes];

const DWORD Scripting::ScriptPointerAddresses[2] =
{
	0x33B6B0, //DR1
	0x3A7240 //DR2

};

const DWORD Scripting::ScriptPositionAddresses[2] =
{
	0x2E3678, //DR1
	0x38A0F8 //DR2

};


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

BYTE Scripting::ReadByte()
{
	int ScriptPtr = *(int*)(*(int*)AbsoluteAddress(ScriptPointerAddresses[Data::Game]) + 4) + (*(int*)AbsoluteAddress(ScriptPositionAddresses[Data::Game]) += 1) + 15;

	return *(BYTE*)ScriptPtr;
}

void Scripting::TEST_CustomOpcode()
{
	Console::WriteLine("[GAME] Custom opcode 0x70FF has been called successfully with argument %d!", ReadByte());
}

