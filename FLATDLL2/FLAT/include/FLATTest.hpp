//  MIND EXPLORER
//  MSC COMPUTING SCIENCE - INDIVIDUAL PROJECT - IMPERIAL COLLEGE LONDON
//  Author: WILLIAM MOYLE
//  Last updated: 03/09/15

//  FLATTEST CLASS DECLARATION FILE
//  The FLATTest class handles the main communication between the Swift app
//  and the C++ FLAT program. It is called via CPlusPlusToObjC.h

#ifndef __FLAT_Tester__FLAT__
#define __FLAT_Tester__FLAT__

#include "SpatialQuery.hpp"
#include "SeedBuilder.hpp"
#include "SpatialObjectFactory.hpp"
#include "Mesh.hpp"
#include "MeshData.hpp"

#ifdef __cplusplus


class FLATTest {
public:
    std::string inputStem;
    //std::string queryFile;
    //char *inputStem;
    //char *queryFile;
    FLAT::QueryStatistics stats;
    std::vector<FLAT::spaceUnit> results;
    int numCoords;

    FLATTest(char* filename, int len);
    ~FLATTest();
    
	void clearResults();
    void performTest(float p0, float p1, float p2, float p3, float p4, float p5);
    void printMeshCoords();
};


#endif
#endif
