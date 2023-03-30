#include "Simplicity.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <string>
#include <random>

//Team Simplicity main test file
using namespace std; 
using namespace simplicity;

int main (void){
//  ARRAY TEST CASES
//  Array Int
    int testIntArray[] = {};
    printArray(testIntArray);   // should output empty data structure prompt 

//  Array Char
    char testCharArray[] = {'A','b','C','d','E','f'};
    printArray(testCharArray);

//  Array Strings
    string testStringArray[] = {"The","string", "array", "test", "was", "passed", "!"};
    printArray(testStringArray);
 //   arrayToFile(testStringArray);   // should save array to SimplicityArrayOutput.txt

//  STACK TEST CASES
//  Stack Int
    stack<int> testIntStack;
    testIntStack.push(1);
    testIntStack.push(2);
    testIntStack.push(3);
    testIntStack.push(4);
    testIntStack.push(5);
    testIntStack.push(6);
    testIntStack.push(7);
    for(int i = 0; i < 7; i++) 
    {
        printStack(testIntStack);
        testIntStack.pop();
    }
    printStack(testIntStack);   // should output empty data structure prompt

//  Stack Char
    stack<char> testCharStack;
    testCharStack.push('a');
    testCharStack.push('B');
    testCharStack.push('c');
    testCharStack.push('D');
    testCharStack.push('e');
    testCharStack.push('F');
    testCharStack.push('G');
    printStack(testCharStack); 

//  Stack Strings
    stack<string> testStringStack;
    testStringStack.push("This");
    testStringStack.push("tests");
    testStringStack.push("a");
    testStringStack.push("stack");
    testStringStack.push("of");
    testStringStack.push("Strings");
    printStack(testStringStack);
 //   stackToFile(testStringStack);   // should save stack to SimplicityStackOutput.txt

    
// Queue Test Cases
//  Queue Int
    queue<int> testIntQueue;
    testIntQueue.push(1534);
    testIntQueue.push(24535);
    testIntQueue.push(-34);
    testIntQueue.push(4);
    testIntQueue.push(5345666);
    testIntQueue.push(6445);
    testIntQueue.push(-7);
    for(int i = 0; i < testIntQueue.size(); i++) 
    {
        printQueue(testIntQueue);
        testIntQueue.pop();
    }
    printQueue(testIntQueue);   // should output empty data structure prompt

//  Queue Char
    queue<char> testCharQueue;
    testCharQueue.push('A');
    testCharQueue.push('b');
    testCharQueue.push('C');
    testCharQueue.push('d');
    testCharQueue.push('E');
    testCharQueue.push('f');
    testCharQueue.push('G');
    printQueue(testCharQueue);

//  Queue Strings
    queue<string> testStringQueue;
    testStringQueue.push("This");
    testStringQueue.push("tests");
    testStringQueue.push("a");
    testStringQueue.push("queue");
    testStringQueue.push("of");
    testStringQueue.push("strings");
    printQueue(testStringQueue);
  //  queueToFile(testStringQueue);   // should save queue to SimplicityQueueOutput.txt


//  Vector Test Cases
//  Vector Int
    vector<int> testIntVector;
    testIntVector.push_back(-51);
    testIntVector.push_back(7542);
    testIntVector.push_back(375474);
    testIntVector.push_back(447);
    testIntVector.push_back(-5);
    testIntVector.push_back(46);
    testIntVector.push_back(6547);
    testIntVector.push_back(438);

//  Vector Char
    vector<char> testVector;
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    char x = letters[rand() % 26];
    for(int i = 0; i < 50; i++){
        testVector.push_back('a' + rand()%26);
    }
    printVector(testVector);
 //   vectorToFile(testVector);   // should save vector to SimplicityVectorOutput.txt


//  Vector String
    vector<string> testStringVector;
    testStringVector.push_back("This");
    testStringVector.push_back("tests");
    testStringVector.push_back("a");
    testStringVector.push_back("vector");
    testStringVector.push_back("of");
    testStringVector.push_back("strings");

// List Test Cases
//  List Int
    list<int> testIntList = {1,2,3,4,5,6,7};
    printLinkedList(testIntList);

// List Strings
    list<string> testStringList = {"This","is","a","list", "test"};
    printLinkedList(testStringList);

//  List Char
    list<char> testCharList = {'s','g','f','g','d','j','k',
                                'l','o','u','y','t','r','v','b',
                                'n','m','j','h','k','i','o','p',
                                'd','s','f','g','h','d','w','e',
                                'd','f','r'};
    printLinkedList(testCharList);


// 2D Array Test Case
    int test2D[2][3];
    test2D[0][0] = 10;
    test2D[0][1] = 11;
    test2D[0][2] = 12;
    test2D[0][3] = 13;
    test2D[1][0] = 14;
    test2D[1][1] = 15;
    test2D[1][2] = 16;
    test2D[1][3] = 17;
    test2D[2][0] = 18;
    test2D[2][1] = 19;
    test2D[2][2] = 20;
    test2D[2][3] = 21;
    print2DArray(test2D);
    return EXIT_SUCCESS;
}