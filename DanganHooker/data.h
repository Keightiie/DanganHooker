#pragma once
#include <Windows.h>
#include "sound.h"


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

	static const int Langauge = Languages::English;

	static const DetourInfo Dangan2DetourInfo[];

};