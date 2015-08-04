/*********************************************************************
*
*
*	Ian Chang masc0962
*	Joaquin Aguirre masc0976
*	06/20/2013
*	CS570
*	
*	main.cpp - includes the clock.h, opt.h and lru.h files.
*	calls the start functions from each file
*
**********************************************************************/

#include <iostream>
#include <fstream>
#include <list>

#include "clock.h"
#include "opt.h"
#include "lru.h"

using namespace std;

int number_of_pages; // Declare global variable of pages

int main(int argc, char* argv[]) 
{

	// Getting input of how many pages from the user
 	cout << "Please enter the number of pages to be used --> "; 	cin >> number_of_pages;
 	cout << "You entered " << number_of_pages << "!" << endl;

	// Creating a Clock object and calling the run command
	Clock myClock(number_of_pages);
	cout << endl << "***** Running Clock *****" << endl;
	myClock.run();
	
	
	// Calling the OPT start function
	cout << endl << "***** Running OPT *****" << endl;
	optFunction(number_of_pages);
	
	// Calling the LRU start function
	cout << endl << "***** Running LRU *****" << endl;
	StartLRU(number_of_pages);

 	return 0;
}
