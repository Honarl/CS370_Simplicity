#include "Simplicity.hpp"
#include <list>
#include <forward_list>

using namespace std;
using namespace simplicity;

int main(void){
	 list<char> testCharList = {'s','g','f','g','d','j','k',
                                'l','o','u','y','t','r','v','b',
                                'n','m','j','h','k','i','o','p',
                                'd','s','f','g','h','d','w','e',
                                'd','f','r'};
    printLinkedList(testCharList, "TestCharLinkedListOutput");

    list<string> testStringList = {"This","is","our","project"};
    printLinkedList(testStringList, "TestStringLinkedListOutput");
	
	forward_list<string> l = {"Does", "anyone", "have", "questions?"};
	printForwardLinkedList(l,"forwardlist");
	
	return EXIT_SUCCESS;
}