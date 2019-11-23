#pragma once
#include <Windows.h>
class Scripting
{
public:

	static const BYTE Cnt_opcodes = 0xFF;
	static DWORD OperationFunctions[];
	static DWORD ADDRESS_ReturnGetOpFunc;

	static void GetOperationFunction();
	static void LoadCustomOpcodes();

	//opcode Functions
	static void TEST_CustomOpcode();
};

