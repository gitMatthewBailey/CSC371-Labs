#include "cat.h"
#include <iostream>

/*Implement the two constructors with their behaviour as previously described.
– You should make use of the “constructor initialisation list” syntax to ensure that
by the time the body of the constructors are entered, the member variables have
already been initialised with the values passed as parameters (or defaulted in the
case of lives = 9).
– In the constructor bodies you should use std::cout from the <iostream> header
to print out “Constructor called with name...” and “Constructor called with name and
lives...” respectively. These print statements when executed will demonstrate the
order of implicit function execution that occurs when the program is run*/

//Default constructor
Cat::Cat() : name("Tom"), lives(9) {
    //Prints out "Default constructor called..."
    std::cout << "Default constructor called..." << std::endl;
}
Cat::Cat(std::string name) : name(name), lives(9) {
    //Prints out "Constructor called with name..."
    std::cout << "Constructor called with name..." << std::endl;
}
Cat::Cat(std::string name, unsigned int lives) : name(name), lives(lives) {
    //Prints out "Constructor called with name and lives..."
    std::cout << "Constructor called with name and lives..." << std::endl;
}

//Implement the destructor. As this class does not own any manually allocated resources
//the destructor does not need to do anything to ensure the class is safely destructed.
Cat::~Cat() {
    //Prints out "Destructor called..." to demonstrate at runtime the order of execution 
    //for the destructors
    std::cout << "Destructor called..." << std::endl;
}

//Implement the two getter methods with their behaviour as previously described.
const std::string& Cat::getName() const {
    return name;
}
const unsigned int& Cat::getLives() const {
    return lives;
}

//Implement the two setter methods with their behaviour as previously described.
void Cat::setName(std::string name) {
    //Prints out "setName called..."
    std::cout << "setName called..." << std::endl;
    this->name = name;
}
//1. A cat can lose lives, but not gain them.
//2. If the cat currently has a positive number of lives and set_lives is called setting
//the lives to 0,then the name of the cat should be modified to become “The Cat
//formerly known as X”, where X is the current name of the cat. To implement this
//functionality you should call both get_name and set_name. The + operator can be
//used to concatenate an std꞉꞉string with a string literal or another std::string.
void Cat::setLives(unsigned int lives) {
    //Prints out "setLives called..."
    std::cout << "setLives called..." << std::endl;
    //1.
    if(lives > getLives()) return;
    //2.
    if(lives == 0 && this->lives > 0) {
        setName("The Cat formerly known as " + this->name);
    }
    this->lives = lives;
}