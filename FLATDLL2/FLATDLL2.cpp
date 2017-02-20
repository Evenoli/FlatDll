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
FlatManager *m_flatMan;

FlatManager::FlatManager()
{
	if (GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
	{
		char* trimmedPath = trimwhitespace(cCurrentPath);
		int len = strlen(trimmedPath);

		m_flat = new FLATTest(trimmedPath, len);
	}
}

FlatManager::~FlatManager()
{
	delete(m_flat);
	delete(m_trimmedPath);
}


void FlatManager::PerformQuery(float p0, float p1, float p2, float p3, float p4, float p5)
{
	if (m_flat)
	{
		m_flat->clearResults();
		m_flat->performTest(p0, p1, p2, p3, p4, p5);
	}
}

int  FlatManager::GetResCoordsNum()
{
	if (m_flat)
		return m_flat->numCoords;
	else
		return -1;
}

std::vector<FLAT::spaceUnit>  FlatManager::GetResCoords()
{
	if(m_flat)
		return m_flat->results;
	else
	{
		return *(new std::vector<FLAT::spaceUnit>());
	}
}

char* FlatManager::trimwhitespace(char *str)
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

extern "C" {

	extern DECLDIR bool InitFlatManager()
	{
		m_flatMan = new FlatManager();
		if (m_flatMan == nullptr)
			return false;

		return true;
	}


	extern DECLDIR bool PerformQuery(float** resultVerts, int* resultLen, float p0, float p1, float p2, float p3, float p4, float p5)
	{
		if (m_flatMan == nullptr)
			return false;

		m_flatMan->PerformQuery(p0, p1, p2, p3, p4, p5);

		int resLen = m_flatMan->GetResCoordsNum();
		*resultLen = resLen;
		if (resLen != -1)
		{
			*resultVerts = new float[resLen];
			std::vector<FLAT::spaceUnit> res = m_flatMan->GetResCoords();

			for (int i = 0; i < resLen; i++) {
				(*resultVerts)[i] = res[i];
			}
			return true;
		}

		return false;

		
	}
}
