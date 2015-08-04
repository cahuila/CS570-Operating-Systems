/*********************************************************************
*
*
*	Ian Chang masc0962
*	Joaquin Aguirre masc0976
*	06/20/2013
*	CS570
*
*	clock.cpp - Is the object clock class
*	Declares the constructor and functions needed
*	to run the clock paging scenario.
**********************************************************************/

#include "clock.h"

//	Clock constructor
Clock::Clock(int num) {
	size = num;
	pages = new int[size];
	useBit = new bool[size];
	initPages();
}


//	used to initialize Clock variables
void Clock::initPages() {
	
	for(int x = 0; x < size; x++) {
		pages[x] = -1;
		useBit[x] = false;
	}		
}

//	used to look for a pages already in the array
int Clock::findPage(int lookup) {
	for(int x = 0; x < size; x++)
		if(pages[x] == lookup)
			return x;
	return -1;
}
// will return the use value of a location in an array
bool Clock::getUseValue(int index) {
	return useBit[index];
}

// will set the page value and use bit in the array
void Clock::setPage(int index, int value) {
	pages[index] = value;
	setUse(index,true);
}

// will set the use bit in the array
void Clock::setUse(int index, bool value) {
	useBit[index] = value;
}

// will return the size of the page array
int Clock::getSize() {
	return size;
}
// will get the next position in the array
// if the value is at the end of the array
// the function will return the start of the
// array. If its not the end of the array
// the funciton will return the next position
// in the array.
int Clock::nextPosition(int position) {
	if((position+1) == size)
		return 0;
	else
		return position+1;

}

// prints out the contents of the page array
void Clock::print() {
	for(int x=0; x<size; x++)
		cout << " " << pages[x];
	cout << endl;
}

// runs the clock paging algorithm
void Clock::run() {
	ifstream infile("pages.txt");
	int i;
	int position = 0;
	int temp;
	int count = 0;
	int faults = 0;
	
	while(infile >> i)
	{
		cout << i << " : " << position << " - " << count << " -- ";
		temp = findPage(i);
		if(temp == -1) {
			temp = position;
			if(count >= size) {
				while(getUseValue(temp))
				{
					setUse(temp, false);
					temp = nextPosition(temp);
				}
			}
			count++;
			setPage(temp, i);
			position = nextPosition(temp);
			cout << "*";
			faults++;
		}
		else
		{
			if(count >= size)
				position = temp;
			setUse(position, true);
			cout << " ";
			 
		}
		print();

	}
	cout << "The total number of faults = " << faults << endl;
	infile.close();
}			
		
