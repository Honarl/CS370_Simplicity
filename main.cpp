#include "Simplicity.h"
//Team Simplicity main test file


int main (void){

    std::cout<<std::setw(150);

    std::cout<<"System Intent: Visualize data structures that students will use in CS 240 in a cross-platform, easy to install C++ library\n";

	std::cout<<std::setw(175);

    std::cout<<"Cycle Intent: Visualize Arrays, Stacks, and Queues from a CS 240 student's program graphically, using ASCII characters, in a simple and easy-to-understand format\n";

	int content[] = {626448,214748364,900,5,247,354};
	int length = 6;

	simplicity::simple::print(content,length); 

    return EXIT_SUCCESS;
}
