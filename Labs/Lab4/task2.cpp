#include <iostream>
#include "cat.h"

int main(int argc, char* argv[]) {
    Cat a("Garfield");
    
    std::cout << a.getName() << " has "
              << a.getLives() << " lives." << std::endl;
              
    Cat b("Mog" , 10);
    std::cout << b.getName() << " has "
              << b.getLives() << " lives." << std::endl;
    
    //Extend the code to call the following operations on the second cat, who is currently
    //named “Mog” and has 10 lives. After each enumerated operation print the name and
    //lives of the cat again to demonstrate how it has changed.
    //(a) Set the cat’s lives to be 42 (Mog currently has 10 lives so this should not have any
    //effect)
    //(b) Set the cat’s name to “Prince”
    //(c) Set the cat’s lives to 8 (Prince currently has 10 lives so this should succeed)
    //(d) Set the cat’s lives to 0 (this should change Prince’s name)
    //(e) Set the cat’s lives to 0 again (this not change the cat’s name a second time)

    b.setLives(42);
    std::cout << b.getName() << " has "
              << b.getLives() << " lives." << std::endl;
    b.setName("Prince");
    std::cout << b.getName() << " has "
              << b.getLives() << " lives." << std::endl;
    b.setLives(8);
    std::cout << b.getName() << " has "
              << b.getLives() << " lives." << std::endl;
    b.setLives(0);
    std::cout << b.getName() << " has "
              << b.getLives() << " lives." << std::endl;
    b.setLives(0);
    std::cout << b.getName() << " has "
              << b.getLives() << " lives." << std::endl;
              
    return 0;
}