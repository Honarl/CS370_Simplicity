#include "Simplicity.hpp"

//Team Simplicity main test file

int main (void){
/*
    std::cout<<std::setw(150);

    std::cout<<"System Intent: Visualize data structures that students will use in CS 240 in a cross-platform, easy to install C++ library\n";

	std::cout<<std::setw(175);

    std::cout<<"Cycle Intent: Visualize Arrays, Stacks, and Queues from a CS 240 student's program graphically, using ASCII characters, in a simple and easy-to-understand format\n";
*/
//	double content[] = {31248.9756,626448,2147483647,900,5,247,354,25.54,623,6541,635,651,321.6854,321,351,351};
//	int length = sizeof(content)/sizeof(double);
/*
	std::stack<int> testStack;
	testStack.push(15);
	testStack.push(350);
	testStack.push(9);
	testStack.push(23052);
	testStack.push(986435);
	testStack.push(2315);
*/
/*
	std::queue<int> testQueue;
	testQueue.push(15);
	testQueue.push(350);
	testQueue.push(9);
	testQueue.push(23052);
	testQueue.push(986435);
	testQueue.push(2315);
//	int length = 6;


	simplicity::simple::printArray(content);
	simplicity::simple::arrayToFile(content);	
//	simplicity::simple::printQueue(testQueue);
//	simplicity::simple::queueToFile(testQueue);
//	simplicity::simple::printStack(testStack);
//	simplicity::simple::stackToFile(testStack);

*/	//simplicity::simple::windowSize();
	
//	std::vector<int> testVect{156,654,651,321,3217,7924,3114984,6513214,651749584,14023549};
//	simplicity::vectorToFile(testVect);
//	std::array<char,10> testC = {'s','c','p','d','s','x','z','b','r','q'};
//	simplicity::arrayToFile(testC);
	int x[] = {00,10,00,01,01,01,00,00,00,00,00,00,00,00,1,1,1};
	simplicity::arrayToFile(x);


    return EXIT_SUCCESS;
}
