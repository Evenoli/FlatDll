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

extern "C"
{
	extern DECLDIR bool PerformQuery(float** resultVerts, int* resultLen, float p0, float p1, float p2, float p3, float p4, float p5);

	extern DECLDIR int add(int a, int b);

	extern DECLDIR int addtest(int a, int b);

	extern DECLDIR char *trimwhitespace(char *str);
}

#endif