#include "Simplicity.hpp"
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <iostream>
#include <cstdlib>

using namespace std;
using namespace simplicity;

int main(void){
	int test2DInt[10][10] = {0};
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++){
            test2DInt[i][j] = rand() % 1000;
        }
    }
    print2DArray(test2DInt, 10, 10);
	
	list<string> testStringList = {"Does","Anyone","Have","Any", "Questions", "?"};
    printLinkedList(testStringList);
	return 0;
}