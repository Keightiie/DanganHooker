#pragma once
#include <Windows.h>
class Scripting
{
public:

	static const BYTE Cnt_opcodes = 74;
	static DWORD OperationFunctions[];
	static DWORD ADDRESS_ReturnGetOpFunc;
	static void GetOperationFunction();
};

