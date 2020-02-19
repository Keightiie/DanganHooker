#pragma once
#include <Windows.h>
#include "sound.h"
#include <string.h>
#include <string>
#include <iostream>
#include <TlHelp32.h>


class Data 
{
public:
	struct DetourInfo
	{
		DWORD AddressStart;
		DWORD AddressEnd;
		void * DetourFunction;
		const char* DetourName;
	};

	enum Languages 
	{
		Japanese = 0,
		English = 1,
		Chinese = 2,
		Spanish = 3

	};

	enum Games
	{
		DR1 = 0,
		DR2 = 1

	};

	static int Game;

	static const int Langauge = Languages::English;

	static const DetourInfo Dangan2DetourInfo[];
	static const DetourInfo DanganDetourInfo[];

	static string GamePath;
	static string ModName;


	//static const float * mypointer = reinterpret_cast<float*>(AbsolouteAddress(0x3A72C4));

};