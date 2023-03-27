#ifndef SIMPLICITY_H_INCLUDED
#define SIMPLICITY_H_INCLUDED
#include "rogueutil.h"
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <limits>
#include <typeinfo>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <span>

namespace simplicity{

	bool fromFileCall = 0;

	void setFileCall(bool x){
		fromFileCall = x;
	}

	bool checkFileCall(){
		return fromFileCall;
	}

	void clearScreen(void){
		rogueutil::cls();
	}

	void wait(void){
		rogueutil::anykey();
	}

	void printTop(int rowWidth, int width){
		if(!checkFileCall())
			rogueutil::setColor(2);					// setting color to green
		std::cout<<"+";								// printing leftmost corner
		for(int j = 0; j < rowWidth; j++){			// loop to end current member box
			for(int i = 0; i < (width + 2); i++){	// loop to print width
				std::cout<<"-";
			}
			std::cout<<"+";
		}
		std::cout<<std::endl;						// ending top structure
		if(!checkFileCall())
			rogueutil::setColor(15);				// setting back to original color
	}

	template <typename T>
	void printContent(T content[], int start, int length, int width){
		if(!checkFileCall())					// checking to avoid ANSI esc characters in txt file
			rogueutil::setColor(2);				// setting color to green
		std::cout<<"|";							// Leftmost member box
		if(!checkFileCall())					// checking to avoid ANSI esc characters in txt file
			rogueutil::setColor(15);			// setting back to original color
		int end = start + length;
		for(int i = start; i < end; i++){		// loop to print whitespace and member
			std::cout<<" "<<std::setw(width);
			std::cout<<content[i];
			if(!checkFileCall())				// checking to avoid ANSI esc characters in txt file
				rogueutil::setColor(2);			// setting color to green
			std::cout<<" |";
			if(!checkFileCall())				// checking to avoid ANSI esc characters in txt file
				rogueutil::setColor(15);		// setting back to original color
		}
		std::cout<<std::endl;					// ending content line
	}

	template <typename T>
	void printContent(std::queue<T> &content, int start, int length, int width){
		std::queue<T> temp;					// Making a new queue and cloning the input one
		temp = content;                     // Otherwise we can't iterate without deleting it
		if(!checkFileCall())				// checking to avoid ANSI esc characters in txt file
			rogueutil::setColor(2);			// setting color to green
		std::cout<<"|";						// Leftmost member box
		if(!checkFileCall())				// checking to avoid ANSI esc characters in txt file
			rogueutil::setColor(15);		// setting back to original color
		if(start != 0){						// making so the queue start matches the correct location for what has and hasnt been printed
			for(int i = 0; i < start; i++)
				temp.pop();
		}
		for(int i = 0; i < length; i++){	// loop to print whitespace and member
			std::cout<<" "<<std::setw(width);
			std::cout<<temp.front();
			if(!checkFileCall())			// checking to avoid ANSI esc characters in txt file
				rogueutil::setColor(2);		// setting color to green
			std::cout<<" |";
			if(!checkFileCall())			// checking to avoid ANSI esc characters in txt file
				rogueutil::setColor(15);	// setting back to original color
			temp.pop();                     // Move to the next item in the new queue
		}
		std::cout<<std::endl;				// ending content line
	}

	template <typename T>					// Printing for stacks
	void printContent(std::stack<T> &content, int length, int width){
		std::stack<T> temp;                             // Making a new stack and cloning the input one
		temp = content;                                 // Otherwise we can't iterate without deleting it
		if(!checkFileCall())							// checking to avoid ANSI esc characters in txt file
			rogueutil::setColor(2);						// setting color to green
		std::cout<<"+";                                 // Formatting to match arrays and queues
		for(int j = 0; j < (width + 2); j++){
			std::cout<<"-";                         	// Makes the boxes the same size
		}
		std::cout<<"+";                                 // Formatting for top line done
		std::cout<<std::endl;
		for(int i = 0; i < length; i++){				// loop to print whitespace and member
			if(!checkFileCall())						// checking to avoid ANSI esc characters in txt file
				rogueutil::setColor(2);					// setting color to green
			std::cout<<"| "<<std::setw(width);
			if(!checkFileCall())						// checking to avoid ANSI esc characters in txt file
				rogueutil::setColor(15);				// setting back to original color
			std::cout<<temp.top();
			if(!checkFileCall())						// checking to avoid ANSI esc characters in txt file
				rogueutil::setColor(2);					// setting color to green
			std::cout<<" | "<<i;
			temp.pop();                            		// Move to the next item in the new stack
			std::cout<<std::endl;						// Next line for next item
			std::cout<<"+";                         	// Box formatting below
			for(int j = 0; j < (width + 2); j++){
				std::cout<<"-";
		}
			std::cout<<"+";                        		// End box formatting
			if(!checkFileCall())						// checking to avoid ANSI esc characters in txt file
				rogueutil::setColor(15);				// setting back to original color
			std::cout<<std::endl;                   	// Next item
		}
	}

	template <typename T, std::size_t length>			// overload for printing for spans
	void printContent(std::span<T,length> content, int start, int len, int width){
		if(!checkFileCall())						// checking to avoid ANSI esc characters in txt file
			rogueutil::setColor(2);					// setting color to green
		std::cout<<"|";								// Leftmost member box
		if(!checkFileCall())						// checking to avoid ANSI esc characters in txt file
			rogueutil::setColor(15);				// setting back to original color
		int end = start + len;
		for(int i = start; i < end; i++){			// loop to print whitespace and member
			std::cout<<" "<<std::setw(width);
			std::cout<<content[i];
			if(!checkFileCall())					// checking to avoid ANSI esc characters in txt file
				rogueutil::setColor(2);				// setting color to green
			std::cout<<" |";
			if(!checkFileCall())					// checking to avoid ANSI esc characters in txt file
				rogueutil::setColor(15);			// setting back to original color
		}
		std::cout<<std::endl;						// ending content line
	}

	void printBottom(int start, int printWidth, int width){
		int end = start + printWidth;
		if(!checkFileCall())									// checking to avoid ANSI esc characters in txt file
			rogueutil::setColor(2);								// setting color to green
		std::cout<<"+";											// ending leftmost corner
		for(int j = 0; j < printWidth; j++){ 					// loop to print corner marker
			for(int i = 0; i < (width + 2); i++){				// loop to print bottom line
				std::cout<<"-";
			}
			std::cout<<"+";
		}
		std::cout<<std::endl;									// ending bottom of structure

		for(int i = start; i < end; i++){						// loop to print indexes
			std::cout<<" ";
			int halfway = 0;									// initializing to zero
			if((width+2) % 2 == 0){								// checking if member takes up an even number of spaces
				halfway = (width / 2);							// setting midpoint
				if(i >= 10)										// to account for double digit numbers
					halfway -= 1;
				std::cout<<" "<<std::setw(halfway)<<" "<<i;		// printing index with appropriate whitespace
				for(int j = 0; j < halfway; j++)				// loop to finish printing out whitespace
					std::cout<<" ";
			}
			else{												// widest data must take up an odd number of spaces
				halfway = (width / 2) + 1 ; 					// setting halfway point and rounding up
				std::cout<<" "<<std::setw(halfway)<<i;			// printing whitespace and index
				for(int j = 0; j < halfway; j++)				// loop to finish printing whitespace
					std::cout<<" ";
			}
		}
		if(!checkFileCall())									// checking to avoid ANSI esc characters in txt file
			rogueutil::setColor(15);							// setting back to original color
		std::cout<<std::endl;									// end index line
	}

	template <typename T>
	int widestMember(T content[], int len){
		int widest = 1;								// Setting current widest to minimum of one
		for(int g = 0; g < len; g++){				// looping through all members of struct
			int width = 1;							// setting minimum width to 1
			std::ostringstream str1;				// output string stream
			str1 << content[g];						// sending number to output as string
			std::string content = str1.str();		// converting to string
			width = content.length(); 				// getting length
			if(width > widest)						// checking if current member is widest
				widest = width;
		}
		return widest;
	}

	template <typename T> 						// Overload that adds in printContent for queue
	int widestMember(std::queue<T> &content, int len){
		int widest = 1;							// Setting current widest to minimum of one
		std::queue<T> temp;                     // Make a temporary queue
		temp = content;                         // Clone the input queue so we can manipulate it
		for(int g = 0; g < len; g++){			// looping through all members of struct
			int width = 1;						// setting minimum width to 1
			std::ostringstream str1;			// output string stream
			str1 << temp.front();				// sending number to output as string
			std::string content = str1.str();	// converting to string
			width = content.length(); 			// getting length
			if(width > widest)					// checking if current member is widest
				widest = width;
			temp.pop();                         // Move to the next item in the queue
		}
		return widest;
	}

	template <typename T>						// overload for finding widest member of stacks
	int widestMember(std::stack<T> &content, int len){
		int widest = 1;							// Setting current widest to minimum of one
		std::stack<T> temp;                    	// Make a temporary stack
		temp = content;                        	// Clone the input queue so we can manipulate it
		for(int g = 0; g < len; g++){			// looping through all members of struct
			int width = 1;						// setting minimum width to 1
			std::ostringstream str1;			// output string stream
			str1 << temp.top();					// sending number to output as string
			std::string content = str1.str();	// converting to string
			width = content.length(); 			// getting length
			if(width > widest)					// checking if current member is widest
				widest = width;
			temp.pop();                         // Move to the next item in the queue
		}
		return widest;
	}

	template <typename T, std::size_t length>							// overload for finding widest member of span
	int widestMember(std::span<T, length>content, int len){
		int widest = 1;													// Setting current widest to minimum of one
		for(auto it = content.begin(); it != content.end(); ++it) {		// looping through all members of struct
			int width = 1;												// setting minimum width to 1
			std::ostringstream str1;									// output string stream
			str1 << *it;												// sending number to output as string
			std::string item = str1.str();								// converting to string
			width = item.length(); 										// getting length
			if(width > widest)											// checking if current member is widest
				widest = width;
		}
		return widest;
	}

	template<typename T, std::size_t length>
	void printArray(std::array<T,length>&content){		        		// overload for Array STL container
		if(!checkFileCall())											// checking to avoid ANSI esc characters in txt file
			clearScreen();
		int len = content.size();										// checking array has data, getting length
		if(len > 0){
			std::cout<<"Printing Array"<<std::endl;
			int width = widestMember(std::span{content}, len);			// finding the width to print
			int windowWidth = rogueutil::tcols();						// determining width of screen window code is run in
			int rowTotalWidth = (width+3) * len;						// finding total length of struct in chars
			while(rowTotalWidth > windowWidth){							// calculating how many chars the top row can be based on window size
				rowTotalWidth -= (width +4);
			}
			int boxPerRow = rowTotalWidth/(width+3);	        		// figuring out how many boxes can be printed in each line
			for(int j = 0; j < len; j += boxPerRow){
				if(j + boxPerRow > len)									// making it so it won't over print boxes
					boxPerRow = len-j;
				printTop(boxPerRow, width);								// printing top of structure
				printContent(std::span{content}, j, boxPerRow, width);	// printing content of struct
				printBottom(j, boxPerRow, width);						// printing bottom of struct and indexes
				std::cout<<std::endl;
			}
			if(checkFileCall()){										// resetting value to false for next function call
				setFileCall(0);
			}
			else{
				std::cout<<"Press any key to continue..."<<std::endl;
				wait();
			}
		}
		else
			std::cout<<"Your array is empty! Nothing to print.";
	}

	template <typename T>
	void printArray(T &content){								// overload for normal array
		if(!checkFileCall()) 									// checking to avoid ANSI esc characters in txt file
			clearScreen();
		int length = sizeof(content)/sizeof(content[0]);		// checking it is not empty, getting length
		if(length > 0){
			std::cout<<"Printing Array"<<std::endl;
			int width = widestMember(content, length);			// finding the width to print
			int windowWidth = rogueutil::tcols();				// determining width of screen window code is run in
			int rowTotalWidth = (width+3) * length;				// finding total length of struct in chars
			while(rowTotalWidth > windowWidth){					// calculating how many chars the top row can be based on window size
				rowTotalWidth -= (width +4);
			}
			int boxPerRow = rowTotalWidth/(width+3);			// figuring out how many boxes can be printed in each line
			for(int j = 0; j < length; j += boxPerRow){
				if(j + boxPerRow > length)						// making it so it won't over print boxes
					boxPerRow = length-j;
				printTop(boxPerRow, width);						// printing top of structure
				printContent(content, j, boxPerRow, width);		// printing content of struct
				printBottom(j, boxPerRow, width);				// printing bottom of struct and indexes
				std::cout<<std::endl;
			}
			if(checkFileCall()){								// resetting for next function call
				setFileCall(0);
			}
			else{
				std::cout<<"Press any key to continue..."<<std::endl;
				wait();
			}
		}
		else{
			std::cout<<"Your array is empty! Nothing to print.";
		}

	}

	template <typename T>
	void printQueue(std::queue<T>& content){
		if(!checkFileCall()) 									// checking to avoid ANSI esc characters in txt file
			clearScreen();
		if(!content.empty()){									// checking it is not empty
			int length = content.size();						// getting number of elements
			std::cout<<"Printing Queue"<<std::endl;
			std::cout<<"Front: "<<content.front()<<std::endl;	// printing first element
			std::cout<<"Back: "<<content.back()<<std::endl;		// printing last element
			int width = widestMember(content, length);			// finding the width to print
			int windowWidth = rogueutil::tcols();				// determining width of screen window code is run in
			int rowTotalWidth = (width+3) * length;				// finding total length of struct in chars
			while(rowTotalWidth > windowWidth){					// calculating how many chars the top row can be based on window size
				rowTotalWidth -= (width + 4);
			}
			int boxPerRow = rowTotalWidth/(width+3);			// figuring out how many boxes can be printed in each line
			for(int j = 0; j < length; j += boxPerRow){
				if(j + boxPerRow > length)						// making it so it won't over print boxes
					boxPerRow = length-j;
				printTop(boxPerRow, width);						// printing top of structure
				printContent(content, j, boxPerRow, width);		// printing content of struct
				printBottom(j, boxPerRow, width);				// printing bottom of struct and indexes
				std::cout<<std::endl;
			}
			if(checkFileCall()){								// resetting for next function call
				setFileCall(0);
			}
			else{
				std::cout<<"Press any key to continue..."<<std::endl;
				wait();
			}
		}
		else{
			std::cout<<"Your queue is empty! Garbage data may follow!";
		}
	}

	template <typename T>
	void printStack(std::stack<T>& content){				// Print stacks vertically
		if(!checkFileCall()) 								// checking to avoid ANSI esc characters in txt file
			clearScreen();
		if(!content.empty()){								// checking not empty
			int length = content.size();					// getting number of elements
			std::cout<<"Printing Stack"<<std::endl;
			std::cout<<"Top: "<<content.top()<<std::endl;	// printing top element
			int width = widestMember(content, length); 		// Find largest item in the entire stack
			printContent(content, length, width);     		// Stack printContent() works to print the entire stack as the two are intertwined
			if(checkFileCall()){							// resetting for next function call
				setFileCall(0);
			}
			else{
				std::cout<<"Press any key to continue..."<<std::endl;
				wait();
			}
		}
		else{
			std::cout<<"Your stack is empty! Garbage data may follow!";
		}
	}

	template<typename T>
	void printVector(std::vector<T>&content){							// overload for vectors
		if(!checkFileCall()) 											// checking to avoid ANSI esc characters in txt file
			clearScreen();
		int len = content.size();										// getting number of members
		if(len > 0){													// verifying it is not empty
			std::cout<<"Printing Vector"<<std::endl;
			int width = widestMember(std::span{content}, len);			// finding the width to print
			int windowWidth = rogueutil::tcols();						// determining width of screen window code is run in
			int rowTotalWidth = (width+3) * len;						// finding total length of struct in chars
			while(rowTotalWidth > windowWidth){							// calculating how many chars the top row can be based on window size
				rowTotalWidth -= (width +4);
			}
			int boxPerRow = rowTotalWidth/(width+3);					// figuring out how many boxes can be printed in each line
			for(int j = 0; j < len; j += boxPerRow){
				if(j + boxPerRow > len)									// making it so it won't over print boxes
					boxPerRow = len-j;
				printTop(boxPerRow, width);								// printing top of structure
				printContent(std::span{content}, j, boxPerRow, width);	// printing content of struct
				printBottom(j, boxPerRow, width);						// printing bottom of struct and indexs
				std::cout<<std::endl;
			}
			if(checkFileCall()){										// resetting for next function call
				setFileCall(0);
			}
			else{
				std::cout<<"Press any key to continue..."<<std::endl;
				wait();
			}
		}
		else
			std::cout<<"Vector is empty! Garbage data may follow!"<<std::endl;
	}

	template<typename T>
	void print2DArray(T &content){
	    int rowNum = 0;
	    if(!checkFileCall())
            clearScreen();
        int length = sizeof(content)/sizeof(content[0][0]);
        if (length > 0){
            std::cout<<"Printing 2D array"<<std::endl;
            //TODO: Add a 2D array widestMember
            int width = widestMember(content, length);
            //END TODO
            int windowWidth = rogueutil::tcols();
            int rowTotalWidth = (width+3) * length;
            while (rowTotalWidth > windowWidth){
                rowTotalWidth -= (width+4);
            }
            int boxPerRow = rowTotalWidth/(width+3);
            std::cout<<"  ";                                        //Print two spaces beforehand so that the boxes will line up with row numbers added
            printTop(boxPerRow, width);
            for (int j = 0; j < length; j += boxPerRow){
                if(j + boxPerRow > length)
                    boxPerRow = length - j;
                std::cout<<rowNum<<" ";                             //Print the row number and then add a space in order to make it not look garbage
                //TODO: Overload printContent for a row check
                printContent(content, j, boxPerRow, width, rowNum);
                //END TODO
                std::cout<<"  ";
                printTop(boxPerRow, width);
                std::cout<<std::endl;
                rowNum++;
            }
            printBottom(j, boxPerRow, width);
            if(checkFileCall){
               setFileCall(0);
            }
            else{
                std::cout<<"Press any key to continue...";<<std::endl;
                wait();
            }
        }
        else{
            std::cout<<"Your array is empty! Nothing to print!";
        }
	}

	template<typename T>
	void arrayToFile(T &content){
		int length = sizeof(content)/sizeof(content[0]);		// checking structure is not empty
		if(length > 0){
			setFileCall(1);										// setting true
			std::ofstream ofs{"SimplicityArrayOutput.txt"};		// declaring output file
			auto cout_buff = std::cout.rdbuf();					// saves pointer to output buffer
			std::cout.rdbuf(ofs.rdbuf());						// substitute internal buffer with file buffer
			printArray(content);								// filling file buffer with data from function call
			std::cout.rdbuf(cout_buff);							// returning control to cout
			std::cout<<"SimplicityArrayOutput.txt has been created!"<<std::endl;
			std::cout<<"Press any key to continue..."<<std::endl;
			wait();
		}
		else{
			std::cout<<"Looks like your array is empty! That file would be nothing!";
		}
	}

	template<typename T, std::size_t length>
	void arrayToFile(std::array<T,length>&content){			// overload for STL array
		if(!content.empty()){
			setFileCall(1);									// setting true
			std::ofstream ofs{"SimplicityArrayOutput.txt"};	// declaring output file
			auto cout_buff = std::cout.rdbuf();				// saves pointer to output buffer
			std::cout.rdbuf(ofs.rdbuf());					// substitute internal buffer with file buffer
			printArray(content);							// filling file buffer with data from function call
			std::cout.rdbuf(cout_buff);						// returning control to cout
			std::cout<<"SimplicityArrayOutput.txt has been created!"<<std::endl;
			std::cout<<"Press any key to continue..."<<std::endl;
			wait();
		}
		else{
			std::cout<<"Looks like your array is empty! That file would be nothing!";
		}
	}

	template <typename T>
	void vectorToFile(std::vector<T>&content){
		int len = content.size();								// checking it is not empty
		if(len > 0){
			setFileCall(1);										// setting true
			std::ofstream ofs{"SimplicityVectorOutput.txt"};	// declaring output file
			auto cout_buff = std::cout.rdbuf();					// saves pointer to output buffer
			std::cout.rdbuf(ofs.rdbuf());						// substitute internal buffer with file buffer
			printVector(content);								// filling file buffer with data from function call
			std::cout.rdbuf(cout_buff);							// returning control to cout
			std::cout<<"SimplicityVectorOutput.txt has been created!"<<std::endl;
			std::cout<<"Press any key to continue..."<<std::endl;
			wait();
		}
		else{
			std::cout<<"Looks like your vector is empty! That file would be nothing!";
		}
	}

	template <typename T>
	void queueToFile(std::queue<T>& content){
		if(!content.empty()){								// checking it is not empty
			setFileCall(1);									// setting true
			int length = content.size();					// getting length
			std::ofstream ofs{"SimplicityQueueOutput.txt"};	// declaring output file
			auto cout_buff = std::cout.rdbuf();				// saves pointer to output buffer
			std::cout.rdbuf(ofs.rdbuf());					// substitute internal buffer with file buffer
			printQueue(content, length);					// filling file buffer with data from function call
			std::cout.rdbuf(cout_buff);						// returning control to cout
			std::cout<<"SimplicityQueueOutput.txt has been created!"<<std::endl;
			std::cout<<"Press any key to continue..."<<std::endl;
			wait();
		}
		else{
			std::cout<<"Looks like your queue is empty! That file would be nothing!";
		}
	}

	template <typename T>
	void stackToFile(std::stack<T>& content){
		if(!content.empty()){								// checking it is not empty
			setFileCall(1);									// setting true
			int length = content.size();					// getting length
			std::ofstream ofs{"SimplicityStackOutput.txt"};	// declaring output file
			auto cout_buff = std::cout.rdbuf();				// saves pointer to output buffer
			std::cout.rdbuf(ofs.rdbuf());					// substitute internal buffer with file buffer
			printStack(content, length);					// filling file buffer with data from function call
			std::cout.rdbuf(cout_buff);						// returning control to cout
			std::cout<<"SimplicityStackOutput.txt has been created!"<<std::endl;
			std::cout<<"Press any key to continue..."<<std::endl;
			wait();
		}
		else{
			std::cout<<"Looks like your stack is empty! That file would be nothing!";
		}
	}
}

#endif // SIMPLICITY_H_INCLUDED
