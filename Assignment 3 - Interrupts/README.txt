Name: Ian Chang (masc0962) , Jack Aguirre (masc0976)
Class Information: CS570, Summer 2013
Assignment Information: Assignment #3, interruptible clock and coutdown timer

Filename of this file: README 

File manifest: README, a3.cpp, a3.h, count.cpp
Compile instructions:
			Compile: type "make" in the directory to compile the
			program
			Run: type "a3" to run the program
			Remove: type "make clean" to remove program executatble
			file.
Operating instructions: 
			We decided to seperate the program into three functions:
			
			createTwoProcess - Creates the two child processes and
			has one process run the countDownTimer function and the
			other run the localTime function. It will also have the
			parent process wait until all children processes
			terminate to continue.
			
			localTime - When called it will print out the local time
			to the command prompt once every second. Function runs
			forever until it is killed.
			
			countDownTimer - Will take in an inputed value and
			countdown from the value. Once it reaches 0 it will
			return a 0 value to show that it was sucessful.

Extra features:		Program will accept a value from the command prompt and check
			to make sure that it is a positive number.

Lesson learned: 	We learned to create multiple processes, how to send signal to
			other process, and how to kill a process. We also learned that 
			there are different ways to send a signal to a process to attempt
			to kill it.




