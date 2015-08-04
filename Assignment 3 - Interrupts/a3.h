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
*	File: a3.h
*
*	Notes:	This file contains all the declarations for the 
*	   program to run. 
******************************************************************/
#ifndef A3_H
#define A3_H

/***	Include file declaration	***/
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

/***	Declaration of namespace	***/
using namespace std;

/***	Default time declaration	***/	
#define DEFAULT_TIME 6

/***	Function declaration		***/
int countDownTimer(int t);
void localTime();
void createTwoProcess(int t);

#endif
