#ifndef SIMPLICITY_H_INCLUDED
#define SIMPLICITY_H_INCLUDED
#include "rogueutil.h"
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <limits>
#include <typeinfo>
#include <sstream>
#include <iomanip>
#include <fstream>

namespace simplicity{
	class simple{
			private:
				static void printTop(int rowWidth, int width){
					rogueutil::setColor(2);						// setting color to green
					std::cout<<"+";								// printing leftmost corner
					for(int j = 0; j < rowWidth; j++){			// loop to end current member box
						for(int i = 0; i < (width + 2); i++){	// loop to print width
							std::cout<<"-";
						}
						std::cout<<"+";
					}
					std::cout<<std::endl;						// ending top structure
					rogueutil::setColor(15);					// setting back to original color
				}

				template <typename T>
				static void printContent(T content[], int start, int length, int width){
					rogueutil::setColor(2);							// setting color to green
					std::cout<<"|";									// Leftmost member box
					rogueutil::setColor(15);						// setting back to original color
					int end = start + length;
					for(int i = start; i < end; i++){				// loop to print whitespace and member
						std::cout<<" "<<std::setw(width);
						std::cout<<content[i];
						rogueutil::setColor(2);						// setting color to green
						std::cout<<" |";
						rogueutil::setColor(15);					// setting back to original color
					}
					std::cout<<std::endl;							// ending content line
				}
				//I know it's another overload but I didn't want to mess with the naming conventions more than I already did -Morgan
				template <typename T>
				static void printContent(std::queue<T> &content, int start, int length, int width){
				    std::queue<T> temp;                             // Making a new queue and cloning the input one
				    temp = content;                                 // Otherwise we can't iterate without deleting it
					rogueutil::setColor(2);							// setting color to green
					std::cout<<"|";									// Leftmost member box
					rogueutil::setColor(15);						// setting back to original color
					if(start != 0){									// making so the queue start matches the correct location for what has and hasnt been printed
						for(int i = 0; i < start; i++)
							temp.pop();
					}
					for(int i = 0; i < length; i++){			// loop to print whitespace and member
						std::cout<<" "<<std::setw(width);
						std::cout<<temp.front();
						rogueutil::setColor(2);						// setting color to green
						std::cout<<" |";
						rogueutil::setColor(15);					// setting back to original color
						temp.pop();                                 // Move to the next item in the new queue
					}
					std::cout<<std::endl;							// ending content line
				}
				//Printing for stacks
				template <typename T>
				static void printContent(std::stack<T> &content, int length, int width){
				    std::stack<T> temp;                             // Making a new stack and cloning the input one
				    temp = content;                                 // Otherwise we can't iterate without deleting it
				    rogueutil::setColor(2);							// setting color to green
					std::cout<<"+";                                 // Formatting to match arrays and queues
				    for(int j = 0; j < (width + 2); j++){
                        std::cout<<"-";                             // Makes the boxes the same size
				    }
				    std::cout<<"+";                                 // Formatting for top line done
				    std::cout<<std::endl;
					for(int i = 0; i < length; i++){				// loop to print whitespace and member
						rogueutil::setColor(2);						// setting color to green
						std::cout<<"| "<<std::setw(width);
						rogueutil::setColor(15);					// setting back to original color
						std::cout<<temp.top();
						rogueutil::setColor(2);						// setting color to green
						std::cout<<" | "<<i;
						temp.pop();                                 // Move to the next item in the new stack
                        std::cout<<std::endl;						// Next line for next item
                        std::cout<<"+";                             // Box formatting below
                        for(int j = 0; j < (width + 2); j++){
                            std::cout<<"-";
				    }
                        std::cout<<"+";                             // End box formatting
                        rogueutil::setColor(15);					// setting back to original color
						std::cout<<std::endl;                       // Next item
					}

				}

				static void printBottom(int start, int printWidth, int width){
					int end = start + printWidth;
					rogueutil::setColor(2);								// setting color to green
					std::cout<<"+";										// ending leftmost corner
					for(int j = 0; j < printWidth; j++){ 					// loop to print corner marker
						for(int i = 0; i < (width + 2); i++){			// loop to print bottom line
							std::cout<<"-";
						}
						std::cout<<"+";
					}
					std::cout<<std::endl;								// ending bottom of structure

					for(int i = start; i < end; i++){					// loop to print indexs
						std::cout<<" ";
						int halfway = 0;								// initializing to zero
						if((width+2) % 2 == 0){							// checking if member takes up an even number of spaces
							halfway = (width / 2);						// setting midpoint
							std::cout<<" "<<std::setw(halfway)<<" "<<i;	// printing index with appropiate whitespace
							if(i >= 10)									// to account for double digit numbers
								halfway -= 1;
							for(int j = 0; j < halfway; j++)			// loop to finish printing out whitespace
								std::cout<<" ";
						}
						else{											// widest data must take up an odd number of spaces
							halfway = (width / 2) + 1 ; 				// setting halfway point and rounding up
							std::cout<<" "<<std::setw(halfway)<<i;		// printing whitespace and index
							if(i >= 10)									// to account for double digit numbers
								halfway -= 1;
							for(int j = 0; j < halfway; j++)			// loop to finish printing whitespace
								std::cout<<" ";
						}
					}
					rogueutil::setColor(15);							// setting back to original color
					std::cout<<std::endl;								// end index line
				}

				template <typename T>
				static int widestMember(T content[], int len){
					int widest = 1;							// Setting current widest to minimum of one
					for(int g = 0; g < len; g++){			// looping through all members of struct
						int width = 1;						// setting minimum width to 1
						std::ostringstream str1;			// output string stream
						str1 << content[g];					// sending number to output as string
						std::string content = str1.str();	// converting to string
						width = content.length(); 			// getting length
						if(width > widest)					// checking if current member is widest
							widest = width;
					}
					return widest;
				}
				//Same thing as the printContent function, didn't want to mess with the names more than I already did - Morgan
				template <typename T>
				static int widestMember(std::queue<T> &content, int len){
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
				//Determining the widest member in the stack, this one is the third (and hopefully last) overload
				template <typename T>
				static int widestMember(std::stack<T> &content, int len){
					int widest = 1;							// Setting current widest to minimum of one
					std::stack<T> temp;                     // Make a temporary stack
					temp = content;                         // Clone the input queue so we can manipulate it
					for(int g = 0; g < len; g++){			// looping through all members of struct
						int width = 1;						// setting minimum width to 1
						std::ostringstream str1;			// output string stream
						str1 << temp.top();				    // sending number to output as string
						std::string content = str1.str();	// converting to string
						width = content.length(); 			// getting length
						if(width > widest)					// checking if current member is widest
							widest = width;
                        temp.pop();                         //Move to the next item in the queue
					}
					return widest;
				}

			public:
				template<typename T>
				static void arrayToFile(T content[], int length){
				    if(length > 0){
                        std::ofstream ofs{"SimplicityArrayOutput.txt"};	// declaring output file
                        auto cout_buff = std::cout.rdbuf();				// saves pointer to output buffer
                        std::cout.rdbuf(ofs.rdbuf());					// substitute internal buffer with file buffer
                        printArray(content, length);					// filling file buffer with data from function call
                        std::cout.rdbuf(cout_buff);						// returning control to cout
				    }
				    else{
                        std::cout<<"Looks like your array is empty! That file would be nothing!";
				    }

				}

				template <typename T>
				static void queueToFile(std::queue<T>& content, int length){
				    if(!content.empty()){
                        std::ofstream ofs{"SimplicityQueueOutput.txt"};	// declaring output file
                        auto cout_buff = std::cout.rdbuf();				// saves pointer to output buffer
                        std::cout.rdbuf(ofs.rdbuf());					// substitute internal buffer with file buffer
                        printQueue(content, length);					// filling file buffer with data from function call
                        std::cout.rdbuf(cout_buff);						// returning control to cout
				    }
				    else{
                        std::cout<<"Looks like your queue is empty! That file would be nothing!";
				    }

				}

				template <typename T>
				static void stackToFile(std::stack<T>& content, int length){
				    if(!content.empty()){
                        std::ofstream ofs{"SimplicityStackOutput.txt"};	// declaring output file
                        auto cout_buff = std::cout.rdbuf();				// saves pointer to output buffer
                        std::cout.rdbuf(ofs.rdbuf());					// substitute internal buffer with file buffer
                        printStack(content, length);					// filling file buffer with data from function call
                        std::cout.rdbuf(cout_buff);						// returning control to cout

                    }
                    else{
                        std::cout<<"Looks like your stack is empty! That file would be nothing!";
                    }
                }

				template <typename T>
				static void printArray(T content[], int length){
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
							printBottom(j, boxPerRow, width);				// printing bottom of struct and indexs
							std::cout<<std::endl;
						}
				    }
				    else{
                        std::cout<<"Your array is empty! Nothing to print.";
				    }

				}
               //Queue version, I made an overload of printContent() and widestMember() to fit the new structure -Morgan
				template <typename T>
				static void printQueue(std::queue<T>& content, int length){
				    if(!content.empty()){
                        std::cout<<"Printing Queue"<<std::endl;
                        std::cout<<"Front: "<<content.front()<<std::endl;
                        std::cout<<"Back: "<<content.back()<<std::endl;
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
							printBottom(j, boxPerRow, width);				// printing bottom of struct and indexs
							std::cout<<std::endl;
						}
				    }
				    else{
                        std::cout<<"Your queue is empty! Garbage data may follow!";
				    }
				}
				//Stacks are vertical they're gonna be a bit different
				template <typename T>
				static void printStack(std::stack<T>& content, int length){
				    if(!content.empty()){
                        std::cout<<"Printing Stack"<<std::endl;
                        std::cout<<"Top: "<<content.top()<<std::endl;
                        int width = widestMember(content, length); // Find largest item in the entire stack
                        printContent(content, length, width);      // Stack printContent() works to print the entire stack as the two are intertwined
				    }
				    else{
                        std::cout<<"Your stack is empty! Garbage data may follow!";
				    }
				}

				static void windowSize(){
					int rows = 	rogueutil::trows();
					int col = rogueutil::tcols();
					std::cout<<"rows: "<<rows<<std::endl;
					std::cout<<"cols: "<<col<<std::endl;
				}


	};


}

#endif // SIMPLICITY_H_INCLUDED
