#pragma once
#include <Windows.h>
class Scripting
{
public:

	static const int Cnt_opcodes = 0x100;
	static DWORD OperationFunctions[];
	static DWORD ADDRESS_ReturnGetOpFunc;

	static void GetOperationFunction();
	static void LoadCustomOpcodes();

	//opcode Functions
	static void TEST_CustomOpcode();
};

