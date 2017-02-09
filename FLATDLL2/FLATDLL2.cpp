// FLATDLL2.cpp : Defines the exported functions for the DLL application.
//

#define FLATDLL2_EXPORTS

#include "stdafx.h"
#include "FLATDLL2.h"

#include <string.h>
#include <stdio.h>  /* defines FILENAME_MAX */
#include <direct.h>
#define GetCurrentDir _getcwd

char cCurrentPath[FILENAME_MAX];

extern "C" {


	extern DECLDIR char *trimwhitespace(char *str)
	{
		char *end;

		// Trim leading space
		while (isspace((unsigned char)*str)) str++;

		if (*str == 0)  // All spaces?
			return str;

		// Trim trailing space
		end = str + strlen(str) - 1;
		while (end > str && isspace((unsigned char)*end)) end--;

		// Write new null terminator
		*(end + 1) = 0;

		return str;
	}

	extern DECLDIR int add(int a, int b)
	{
		return a+b;
	}

	extern DECLDIR int addtest(int a, int b)
	{
		return addt(a, b);
	}


	extern DECLDIR bool PerformQuery(float** resultVerts, int* resultLen, float p0, float p1, float p2, float p3, float p4, float p5)
	{
		if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
		{
			return false;
		}

		char* trimmedPath = trimwhitespace(cCurrentPath);
		int len = strlen(trimmedPath);
		//char * path = new char[len+2];
		//strcpy_s(path, len+2, trimmedPath);

		FLATTest* Flat = new FLATTest(trimmedPath, len);
		Flat->performTest(p0, p1, p2, p3, p4, p5);

		*resultLen = Flat->numCoords;
		*resultVerts = new float[Flat->numCoords];

		for (int i = 0; i < Flat->numCoords; i++) {
			(*resultVerts)[i] = Flat->results[i];
		}
		
		//Destroy Flat?

		return true;
	}
}
