#pragma once
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include "sound.h"

class Functions
{

public:
	struct FunctionData
	{
		DWORD Address;
		int Size;
		void * Replacement;
		const char* Name;
	};

	static const FunctionData DR2functions[];
	static void HookFunctions();


};

class Data 
{
public:
	//static DWORD OPCOdeFuncs[256];
	static void HookOPCodes();
	enum DR2DataPositions
	{
		DR2BGArrayPointer = 0x2FE778

	};
};