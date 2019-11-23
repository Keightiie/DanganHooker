#include "Scripting.h"
#include "data.h"

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