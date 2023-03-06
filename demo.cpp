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

	vector<char> x = {'s','i','m','p','l','i','c','i','t','y'};
	vectorToFile(x);
	
	queue<int> numbers;
	for(int i = 0; i < 20; i++){
		numbers.push(rand());

		if(i > 15){
			numbers.pop();
		}
		
		printQueue(numbers);
	}

	
	return 0;
}