#include "opt.h"
void optFunction(int size){
	int frameSize, d, numPage = 0, page[100];
	int i, j, k, pageFault = 0, temp = 0, location[100];
	int flag = 0, found = 0, index = 0, rpage;
	char c;

	frameSize = size;
	int frame[frameSize];
	ifstream myFile("pages.txt");

	if(myFile.is_open()){
		while(myFile.good()){
			c = myFile.get();
			// ignore space and convert char to int
			if(!isspace(c) && c!= EOF){
				d = c -'0';	
				page[numPage] = d;
				numPage++;
			}
		}
		myFile.close();
	}
	else
		cerr << "Error opening file\n";

	for(i = 0; i < numPage; i++){
		flag = 0;
		// check to see if a page is already in the frame
		for(j = 0; j < frameSize; j++){
			if(frame[j] == page[i]){
				flag = 1;
				break;
			}
		}
		// page is not in the frame
		if(flag == 0){
			for(j = 0; j < frameSize; j++){
				for(temp = i + 1; temp < numPage; temp++){
					location[j] = 0;
					if(frame[j] == page[temp]){
						location[j] = temp - i;	
						break;
					}
				}
			}
			found = 0;
			for(j = 0; j < frameSize; j++){
				// a space to insert
				if(location[j] == 0){
					index = j;
					found = 1;
					break;
				}

			}
			if(found == 0){
				rpage = location[0];
				index = 0;
				for(j = 1; j < frameSize; j++){
					if(rpage < location[j]){
						// location to replace page with
						rpage = location[j];
						index = j;
					}
				}
			}
			frame[index] = page[i];
			cout << "Replace page wiht: " << frame[index] << endl;
			pageFault++;
		
		}
	
	}
	for(k = 0; k < frameSize; k++)
		cout << frame[k] << " ";
	cout << "\nNumber of page fault is: " << pageFault << endl;
}
