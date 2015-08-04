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
*	File: count.cpp
*
*	Notes:	This file containts the function to create  two 
*	   processes. It then will call on two functions. One to
*	   print out the local time every second and the other 
*	   to countdown. Once the countdown process is complete
*	   then a message will be sent to the process printing
*	   the local time. Once the process has been killed, it
*	   will terminate its process and notify the parent
*	   process.
******************************************************************/
#include "a3.h"

/***	Create two processes. One will run the the countdown
	 function and the second will run the localTime function.
	 
							       ***/
void createTwoProcess(int t){
	int status;
	pid_t firstChild, secondChild;

	firstChild = fork();
	if(firstChild < 0){
		cerr << "Error forking child process\n";
		exit(-1);
	}
	if(firstChild == 0){
		localTime();
	}
	else{
		secondChild = fork();
		if(secondChild < 0){
			cerr << "Error forking a child process\n";
			exit(-1);
		}
		else if(secondChild == 0){
			countDownTimer(t);
			kill(firstChild,SIGKILL);
		}
		else{
			waitpid(secondChild,&status,0);
			cout << "All children processes have terminated" << endl;

		}
	}
}

/***	countDowntimer prints out and counts down from an inputted value  ***/
int countDownTimer(int t){
	
	for(t; t >= 0; t--){
		cout << "Time remaining: " << t << " seconds\n";
		sleep(1);
	}
	return t;	
}	

/*** localTime - when called will print out the local time every second forever.
	The only way to terminate this funciton is to kill the process.	     ***/
void localTime(){
	time_t ctt;
	while(true){
		ctt = time(0);
		tm *ltm = localtime(&ctt);
		cout << "current time:" << ltm -> tm_hour << ":" << 
			ltm-> tm_min << ":" << ltm-> tm_sec << endl;
		sleep(1);
		
	}
}
