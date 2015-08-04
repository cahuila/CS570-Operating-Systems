/******************************************************************
*
*
*	Joaquin Aguirre (masc0976)
*	Ian Chang (masc0962)
*
*	Class: CS570, Summer 2013
*
*	Assignment: Aissgnment #3
*
*
*	File: a3.cpp
*
*	Notes:	This file containts the main function. The main
*	   function will check to see if any additional arguments
*	   were entered into the comman prompt with the program
*	   call. If there was then it will run the program with
*	   the input. For example if "a3 9" was entered in the
*	   command prompt then the program will take the 9 input
*	   and use it as the input value for the seconds. If no
*	   additional data was entered than the program will use
*	   6 as its default value.
******************************************************************/

#include "a3.h"


/*****	main function			
	 checks to see if additional arguments was entered, if so
	 then take the value of the argument and use it for the 
	 program counter. If not then use the default value.
	 						     *****/ 
int main(int argc, char *argv[]){
	
	int seconds;
	
	if(argc == 1){			// no arguments, then use default time
		seconds = DEFAULT_TIME;
	}
	else if (argc == 2){		// use command promopt argument
		seconds = atoi(argv[1]);
		cout << "******** " << seconds << endl;
	}
	else{				// if more than one argument entered than error
		cout << "Error command, program existing\n";
		exit(-1);
	}
	
	// Checks to see if a correct value was entered. An integer greater than 0
	if(seconds > 0)
		createTwoProcess(seconds);
	else
		cout << "SORRY INCORRECT INPUT VALUE" <<  endl;
	return 0;
}
