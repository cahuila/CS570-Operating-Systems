/*********************************************************************
*
*
*	Ian Chang masc0962
*	Joaquin Aguirre masc0976
*	06/20/2013
*	CS570
*
**********************************************************************/


#ifndef CLOCK_H
#define CLOCK_H

// include file declarations
#include <fstream>
#include <iostream>

using namespace std;

// Clock class declarations
class Clock {
	public:
		Clock(int num);
		int getSize();
		int findPage(int lookup);
		bool getUseValue(int index);
		void setPage(int index, int value);
		void setUse(int index, bool value);
		void run();
	private:
		int size;
		int* pages;
		bool* useBit;
		void initPages();
		int nextPosition(int position);
		void print();
		
};

#endif
