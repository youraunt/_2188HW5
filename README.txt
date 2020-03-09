*******************************************************
*  Name      :	Brice Allen
*  Student ID:	107452188
*  Class     :  CSC 2421
*  HW#       :  5
*  Due Date  :  March 9, 2020
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program "2188HW5" implements a doubly linked list
utilizing std::list. I tried to implement layered menus
for this project. First, you are greeted with the main
menu which has six options:
1. Load files
    load sub menu
    1. load new dictionary
        this gets the file name and checks if the file exists
        then if exists opens file and loads into std::list
    2. load words to search
        this gets the file name and checks if the file exists
        then if exists opens file and loads into std::list
    3. return to main menu
        goes up one menu level to main menu
2. Sort
    utilizes std::sort to alphabetically sort list (case insensitive)
3. Display
    writes to console
4. Search
    search sub menu
    1. search forwards
        searches for specified words front to back
         and keeps track of iterations
    2. search backwards
    searches for specified words back to front
    and keeps track of iterations
    I wanted to use boost reverse here but the grid doesnt like boost
    3. return to main menu
    goes up one menu level to main menu
5. Write out
    Writes to file
6. Exit
    calls exitProgram() fucntion and exits with flag EXIT_SUCCESS
*******************************************************
*  Citations
*******************************************************
I used https://en.cppreference.com/w/cpp/filesystem/exists
to see if files exist before opening.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that calls sub-functions
   to read data from the user.

Name:  functions.h
   Contains the prototypes for the class function.

Name: function.cpp
   Defines and implements the functions class for handling user input,
    Menus and corresponding switches live here. Display functions to
    write to console also live here.
Name: DictEntry.h
    Provided
Name: Dictionary.h
    Provided I added a function to build lists
Name: Dictionary.cpp
    Implementation of provided functions.



*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.

   The program was developed on QT Creator
   and tested on gnu g++ 4.4.2.
   It was compiled, run, and tested on gcc csegrid.ucdenver.pvt.


*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.
   To uncompress it use the following commands
       % unzip 2188HW5

   Now you should see a directory named homework with the files:
	main.cpp
	functions.h
	functions.cpp
	Dictionary.h
	Dictionary.cpp
	DictEntry.h
	makefile
	Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd 2188HW4

    Compile the program by:
    % make

3. Run the program by:
   % ./2188HW4

4. Delete the obj files, executables, and core dump by
   %./make clean
