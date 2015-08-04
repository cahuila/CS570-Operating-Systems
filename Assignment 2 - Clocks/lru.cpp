/*********************************************************************
*
*
*	Ian Chang masc0962
*	Joaquin Aguirre masc0976
*	06/20/2013
*	CS570
*
**********************************************************************/

#include "lru.h"


list<int> pages; // Linked list to hold pages
int size_pages;	// that total number of pages allowed


// LRUFunction will take in a lookup number
// 	it will look through the link list 
//	if a page is found it will remove it from its location
//	and move it to the back of the list.
//	If the page is not found then it will add to the 
//	back of the list (as long as there is still room).
//	If there is no room then the first link will be erased
//	and the new page will be added to the end of the list.
int LRUFunction(int lookup_num)
{
 	for(list<int>::iterator list_iterator = pages.begin(); list_iterator != pages.end(); list_iterator++)
  	{
  		if(*list_iterator == lookup_num)
  		{
   			pages.erase(list_iterator);
   			pages.push_front(lookup_num);
   			return 0;
  		}
	}
	
	// Checks to see if there is still room to add the page
 	if(pages.size() < size_pages)
 	{
  		pages.push_front(lookup_num);
  	}
 	else
 	{
  		pages.pop_back();
  		pages.push_front(lookup_num);
 	}
 	return 1;
}

// Function will start reading from the file and call the LRUFunction
//	to see if it is in the list
void StartFileReading()
{

	// Open the file pages
	ifstream infile("pages.txt"); // Open file


 	int i;    // Temp value for text input
  	int count = 0;
 
 	while(infile >> i)
 	{
  		if(LRUFunction(i) != 0) count++;
  			for(list<int>::iterator list_iterator = pages.begin(); list_iterator != pages.end(); list_iterator++)
  			{
   				cout << *list_iterator << " ";
   			}
  			cout << endl;
 	}
 
 	cout << endl << "Page faults: " << count << endl;
	infile.close();
}

// Starts the LRU
void StartLRU(int size)
{
	size_pages = size;
	StartFileReading();
}
