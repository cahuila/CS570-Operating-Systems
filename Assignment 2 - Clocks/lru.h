/*********************************************************************
*
*
*	Ian Chang masc0962
*	Joaquin Aguirre masc0976
*	06/20/2013
*	CS570
*
*	lru.h - declares the variables and functions that will be
*	used in the lru.cpp file.
**********************************************************************/

#ifndef LRU_H
#define LRU_H

// declaration of include files
#include <list>
#include <iostream>
#include <fstream>
using namespace std;


// Function delcaration
int LRUFunction(int lookup_num);
void StartFileReading();
void StartLRU(int size);

#endif
