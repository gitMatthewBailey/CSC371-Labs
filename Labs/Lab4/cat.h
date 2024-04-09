#include <string>
#ifndef CAT_H
#define CAT_H

class Cat
{
private:
    /* data */
    std::string name;
    unsigned int lives;
public:
    //Declare default constructor.
    //Declare 2 public constructors. The first constructor accepts an std::string and
    //assigns it to the name member variable while initialising the number of lives to be
    //9. The second constructor accepts both an std::string and an unsigned int and
    //initialises both member variables to those valuescat(/* args */);
    Cat();
    Cat(std::string name);
    Cat(std::string name, unsigned int lives);

    //Declare a public destructor.
    ~Cat();

    //Declare public getter methods for the name and lives member variables. These get‑
    //ters should return “constant references” to the underlying member variables to ensure
    //that simply “getting” their values doesn’t cause a temporary duplicate to be made.
    const std::string& getName() const;
    //std::string& explained at bottom of page*.
    const unsigned int& getLives() const;
    //unsigned int& explained at bottom of page*.

    //Declare public setter methods for the name and lives member variables.
    void setName(std::string name);
    void setLives(unsigned int lives);
    
};

#endif

/**bottom of page
/* In C++, using the & symbol after a type like std::string indicates that the function
 * returns a reference to an std::string object. This means that the function returns a
 * reference to the actual object, not a copy of it.
 *
 * In C++, references are similar to pointers in C, but they have some key differences.
 * In C, pointers are explicitly manipulated using * for dereferencing and & for referencing.
 * In C++, references provide a convenient way to work with objects without the need for
 * explicit pointer manipulation.
 *
 * So, in C++, using & after a type like std::string indicates that the function
 * returns a reference to that type, not the memory address. It's a way to return
 * the actual object by reference.
 */