#pragma once

#ifndef _FLATDLL2_H_
#define _FLATDLL2_H_

#if defined FLATDLL2_EXPORTS
#define DECLDIR __declspec(dllexport)
#else
#define DECLDIR __declspec(dllimport)
#endif

#include "FLAT\include\FLATTest.hpp"
#include "FLAT\include\addtest.h"

//Class to hold the initialised 'FlatTest' object to allow quicker querying
class FlatManager
{
public:
	FlatManager();
	~FlatManager();
	void PerformQuery(float p0, float p1, float p2, float p3, float p4, float p5);
	int GetResCoordsNum();
	std::vector<FLAT::spaceUnit> GetResCoords();

private:
	FLATTest* m_flat;
	char* m_trimmedPath;
	int m_pathLen;
	char *trimwhitespace(char *str);
};



extern "C"
{
	extern DECLDIR bool InitFlatManager();

	extern DECLDIR bool PerformQuery(float** resultVerts, int* resultLen, float p0, float p1, float p2, float p3, float p4, float p5);
}



#endif