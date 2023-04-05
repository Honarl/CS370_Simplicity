#include <iostream>
#include <array>
#include "Simplicity.hpp"

using namespace std;
using namespace simplicity;

int main()
{
    array<int, 5> n;

    //taking values of elements from user
    for(int i = 0; i < n.size() ; i++)
    {
	cout << "Enter value of n[" << i << "]"<< endl;
    	cin >> n[i];
    }

    /* printing the values of elements of array */
    for (int j = 0; j < n.size(); j++ )
    {
        cout << "n[" << j << "] = " << n[j] << endl;
    }
	printArray(n);
    return 0;
}