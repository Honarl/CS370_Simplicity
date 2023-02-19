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
					std::cout<<"+";
					for(int j = 0; j < length; j++){
						for(int i = 0; i < (width + 2); i++){
							std::cout<<"-";
						}
						std::cout<<"+";
					}
					std::cout<<std::endl;
				}
				
				template <typename T>
				static void printContent(T content[], int length, int width){
					std::cout<<"|";
					for(int i = 0; i < length; i++){
						std::cout<<" ";
						std::cout<<std::setw(width);
						std::cout<<content[i];
						std::cout<<" |";
					}
					std::cout<<std::endl;
				}
				
				static void printBottom(int length, int width){
					std::cout<<"+";
					for(int j = 0; j < length; j++){ 
						for(int i = 0; i < (width + 2); i++){
							std::cout<<"-";
						}
						std::cout<<"+";
					}
					std::cout<<std::endl;
					for(int i = 0; i < length; i++){
						std::cout<<" ";
						int halfway = 0;
						if((width+2) % 2 == 0){
							halfway = (width / 2);
							std::cout<<" ";
							std::cout<<std::setw(halfway)<<" "<<i;
							
							for(int j = 0; j < halfway; j++)
								std::cout<<" ";	
						}
						else{
							halfway = (width / 2) +1 ; 

							std::cout<<" ";
							std::cout<<std::setw(halfway)<<i;
							
							for(int j = 0; j < halfway; j++)
								std::cout<<" ";		
						}
						
						//std::cout<<" ";
					}
					
					std::cout<<std::endl;
				}
				
				template <typename T>
				static int widestMember(T content[], int len){
					int widest = 1;
					for(int g = 0; g < len; g++){
						int width = 1;
						std::ostringstream str1;			// output string stream
						str1 << content[g];					// sending number to output as string
						std::string content = str1.str();	// converting to string
						width = content.length(); 			// getting length
						if(width > widest)
							widest = width;
					}
					return widest;
				}
				
			public:
				template <typename T>
				static void print(T content[], int length){
					int width = widestMember(content, length);
					printTop(length, width);
					printContent(content, length, width);
					printBottom(length,width);
				}
				
		
	};
	
	
}

#endif // SIMPLICITY_H_INCLUDED
