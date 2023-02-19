#ifndef SIMPLICITY_H_INCLUDED
#define SIMPLICITY_H_INCLUDED
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <limits>
#include <typeinfo>
#include <sstream>
#include <iomanip>

namespace simplicity{
	class simple{
			private:
				static void printTop(int length, int width){
					std::cout<<"+";								// printing leftmost corner
					for(int j = 0; j < length; j++){			// loop to end current member box
						for(int i = 0; i < (width + 2); i++){	// loop to print width 
							std::cout<<"-";
						}
						std::cout<<"+";
					}
					std::cout<<std::endl;						// ending top structure
				}
				
				template <typename T>
				static void printContent(T content[], int length, int width){
					std::cout<<"|";									// Leftmost member box
					for(int i = 0; i < length; i++){				// loop to print whitespace and member
						std::cout<<" "<<std::setw(width);
						std::cout<<content[i]<<" |";
					}
					std::cout<<std::endl;							// ending content line
				}
				
				static void printBottom(int length, int width){
					std::cout<<"+";										// ending leftmost corner
					for(int j = 0; j < length; j++){ 					// loop to print corner marker
						for(int i = 0; i < (width + 2); i++){			// loop to print bottom line
							std::cout<<"-";
						}
						std::cout<<"+";
					}
					std::cout<<std::endl;								// ending bottom of structure
					
					for(int i = 0; i < length; i++){					// loop to print indexs
						std::cout<<" ";
						int halfway = 0;								// initializing to zero
						if((width+2) % 2 == 0){							// checking if member takes up an even number of spaces
							halfway = (width / 2);						// setting midpoint
							std::cout<<" "<<std::setw(halfway)<<" "<<i;	// printing index with appropiate whitespace
							for(int j = 0; j < halfway; j++)			// loop to finish printing out whitespace
								std::cout<<" ";	
						}
						else{											// widest data must take up an odd number of spaces
							halfway = (width / 2) + 1 ; 				// setting halfway point and rounding up
							std::cout<<" "<<std::setw(halfway)<<i;		// printing whitespace and index
							for(int j = 0; j < halfway; j++)			// loop to finish printing whitespace
								std::cout<<" ";		
						}
					}
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
				
			public:
				template <typename T>
				static void print(T content[], int length){
					int width = widestMember(content, length);	// finding the width to print
					printTop(length, width);					// printing top of structure
					printContent(content, length, width);		// printing content of struct
					printBottom(length,width);					// printing bottom of struct and indexs
				}
				
		
	};
	
	
}

#endif // SIMPLICITY_H_INCLUDED
