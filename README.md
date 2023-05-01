# CS370Simplicity
Look at them data structures


----- QUICK START GUIDE -----

-Place Simplicity.hpp and rogueutil.h in your working directory
-Include "Simplicity.hpp" at the top of your source code (#include "Simplicity.hpp")

INSTALLATION GUIDE

Linux:
  
  -Run the following command in a terminal to install the g++-10 compiler:
    "sudo apt install gcc-10"
  Any gcc compiler after 10 will suffice
  
  
  -Ensure that you have git installed by running the following command:
    "sudo apt install git"
    
  
  -Install the library onto your machine by running the following command:
    "git clone https://github.com/Honarl/CS370Simplicity"
  
  
  -You can also download the repository directly from GitHub without requiring a clone
  
Windows:
  
  -Install gcc10 or later & git
    You can acquire the latest version of GCC at https://winlibs.com/#download-release
  You can install git by running the following command in Powershell:
    "winget install Git.Git"
  
  -Update your paths to include gcc10. If you are using Powershell you can use the following command: 
    "$env:PATH += ";pathTogcc""
  
  
  -Install the library onto your machine by running the following command prompt
    "git clone https://github.com/Honarl/CS370Simplicity"
  
  
  -You can also download the repository directly from GitHub without requiring a clone
  
  
Mac:
   
   -Mac users can use git functions if they have Xcode and Xcode Command Line Tools installed, which you can install using the terminal line "xcode-select --install"
   
   
   -Mac users can also use HomeBrew to install git, HomeBrew can be installed by following the instructions on https://brew.sh/, and then followed up by using the command "brew install git"
  
  
  -Install the library onto your machine by running the following command prompt
    "git clone https://github.com/Honarl/CS370Simplicity"
  
  
  -You can also download the repository directly from GitHub without requiring a clone
  
COMPILING:
  
  Simplicity uses the C++20 standard, so when you compile ensure that your IDE or compiler is aware and has the following flags set, using "main.cpp" as an example file name:

    "g++-10 -std=c++2a main.cpp"
    OR
    "g++-10 -std=c++20 main.cpp"
  
----- USER MANUAL ------
  

HOW TO USE:
  
  The Simplicity library functions are under a namespace called "simplicity". When not using the namespace, all Simplicity functions require you to input simplicity::<function> in order to use each function. Use a Simplicity function to display your data structures to your terminal screen or save their output to files.
  
  All Simplicity library functions use templates to allow you to print out a structure of any data type with minimal input from you.
  
  Please ensure that you are compiling with the C++20 standard (or any future release) when using the Simplicity library.
  
  ONE-DIMENSIONAL ARRAYS:
    
    -To print out your array, use "printArray(_structname_)". The function will take one-dimensional arrays and STL arrays of any data type and will display in the console window when your code is run.
    
    -To print your array output to a file, use "arrayToFile(_arrayname, filename_)". The function will take one-dimensional arrays and STL arrays of any data type. A file will be created in the same directory as your program file with the name you supplied.
  
  ONE-DIMENSIONAL VECTORS:
    
    -To print out your vector, use "printVector(_vectorname_)". The function will take one-dimensional vectors of any data type and display in the console window when your code is run.
    
    -To print your vector output to a file, use "vectorToFile(_vectorname, filename_)". This function will take one-dimensional vectors of any data type. A file will be created in the same directory as your program file with the name you supplied.
  
  STACKS:
    
    -To print out your stack, use "printStack(_stackname_)". This function will take stacks of any data type and display in the console window when your code is run.
    
    -To print your output to a file, use "stackToFile(_stackname, filename_)". This function will take stacks of any data type. A file will be created in the same directory as your program file with the name you supplied.
  
  QUEUES:
    
    -To print out your queue, use "printQueue(_queuename_)". This function will take queues of any data type and display in the console window when your code is run.
    
    -To print your output to a file, use "queueToFile(_queuename, filename_)". This function will take queues of any data type. A file will be created in the same directory as your program file with the name you supplied.
  
  LINKED LISTS:
    
    -To print out a linked list, use "printLinkedList(_linkedlistname, filename_)". This function will take linked lists of any data type and display in the console window when your code is run. If your list is too large to display, a file will be created using the file name supplied.
    
    -To ensure a linked list is printed to a file, use "listToFile(_linkedlistname, filename_)".
  
  FORWARD LISTS:
    
    -To print out a forward list, use "printForwardLinkedList(_forwardlistname, filename_)". This function will take forward lists of any data type and display int he console window when your code is run. If your list is too large to display, a file will be created using the file name supplied.
    
    -To ensure a forward list is printed to a file, use "forwardListToFile(_forwardlistname, filename_)".
  
  2D ARRAYS:
    
    -To print out a two-dimensional standard array, use "print2DArray(_arrayname, x, y, filename_)", where x represents the first dimension of your array and y is the second. This function will take 2D arrays of any data type and display in the console window when your code is run. If your array is too large to display, a file will be created in the same directory as your program file with the name you supplied. To guarantee file output, use "arrayToFile(_arrayname, x, y, filename_)".
    
    -To print out a two-dimensional STL array, use "print2DArray(_arrayname, x, y, filename_)", where x represents the outer dimension of your array and y is the inner dimension. This function will take 2D STL arrays of any data type and display in the console window when your code is run. If your array is too large to display, a file will be created in the same directory as your program file with the name you supplied. To guarantee file output, use "arrayToFile(_arrayname, x, y, filename_)".
