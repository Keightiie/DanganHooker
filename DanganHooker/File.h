#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

class File
{
public:
	static void FUN_004c56a0(char* ResultDest, char* fileName, int a3);
	static void FUN_004c58c0(char* ResultDest, char* fileName, int a3);
	static void FUN_004c5b00(char* ResultDest, char* fileName, int a3);
	static bool FileExists(const char *filename);
};

