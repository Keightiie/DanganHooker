#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

class File
{
public:
	static int GetFilePath(char * ResultDest, char * a2, int a3);
	static bool FileExists(const char *filename);
};

