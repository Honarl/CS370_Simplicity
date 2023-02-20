#include "Simplicity.h"
//Team Simplicity main test file


int main (void){

    std::cout<<std::setw(150);

    std::cout<<"System Intent: Visualize data structures that students will use in CS 240 in a cross-platform, easy to install C++ library\n";

	std::cout<<std::setw(175);

    std::cout<<"Cycle Intent: Visualize Arrays, Stacks, and Queues from a CS 240 student's program graphically, using ASCII characters, in a simple and easy-to-understand format\n";

	int content[] = {626448,214748364,900,5,247,354};
	int length = 6;

	std::stack<int> testStack;
	testStack.push(15);
	testStack.push(350);
	testStack.push(9);
	testStack.push(23052);
	testStack.push(986435);
	testStack.push(2315);


	std::queue<int> testQueue;
	testQueue.push(15);
	testQueue.push(350);
	testQueue.push(9);
	testQueue.push(23052);
	testQueue.push(986435);
	testQueue.push(2315);


	simplicity::simple::printArray(content,length);
	simplicity::simple::printQueue(testQueue,length);
	simplicity::simple::printStack(testStack,length);



    return EXIT_SUCCESS;
}
