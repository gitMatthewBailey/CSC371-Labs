#include <iostream>
#include <string>
#include "cat.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Incorrect arguments. Usage: " << argv[0] << " name1 lives1 name2 lives2 ..." << std::endl;
        return -1;
    }
    //Since each cat requires two parameters (name and lives), we subtract 1 from argc to exclude the 
    //program name, and then divide by 2 to get the number of cats.
    //Calculate the number of cats to be parsed from the number of command line parameters
    //given and store this in a constant variable 
    //If the number of parameters passed on the command line is not an even number, then the
    //last Cat in the sequence should have 9 lives.
    if ((argc - 1) % 2 != 0) {
        //So here I'm trying to manually edit the command line arguments to set the last arg to "9"
        char extraArg[] = "9";
        argv[argc] = extraArg;
        argc++;
    }
    //Prints out the command line arguments that have been entered
    for (int i = 0; i < argc; ++i) {
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;
    }

    //Since the number of arguments is always an even number, we can just divide by 2
    const int numCats = argc / 2;
    //Print numCats
    //Allocate the correct number of Cat elements (which implicitly default constructs
    //each of them)
    //Prints out "Allocating clowder of size ", numCats
    std::cout << "Allocating clowder of size " << numCats << std::endl;
    Cat *cats = new Cat[numCats];

    //Then iterate over the clowder, assigning their values, which are to be those parsed from the
    //command line arguments.
    //Assign the values by calling the setter methods of each Cat.*
    //Command line would look like ./task3 Tom 5 Dick 6 Harry 42 or
    //                             ./task3 Lister 1 Holly 6000 Kryten 64 "The Cat"
    //Both should be valid. We increment i before entering the for loop as we aren't concerned with
    //the first argument.
    for (int i = 0; i < numCats; i++) {
        cats[i].setName(argv[i * 2 + 1]);
        //Then set the lives for the i-th cat in the cats array. Must be given an unsigned int
        //value.
        cats[i].setLives(atoi(argv[i * 2 + 2]));
    }

    //Iterate over the clowder and print the name and lives of each cat
    //Prints out "Cat ", i, ": ", cats[i].getName(), " has ", cats[i].getLives(), " lives."
    for (int i = 0; i < numCats; ++i) {
        std::cout << cats[i].getName() << " has " << cats[i].getLives() << " lives." << std::endl;
    }

    //Ensure that you safely deallocate the clowder
    delete[] cats;
    return 0;
}

//*Can also do this by invoking
    //the “move assignment” operator (which we’ll be covering in lecture 10) to assign a locally
    //constructed Cat within the loop. But that is not shown here.