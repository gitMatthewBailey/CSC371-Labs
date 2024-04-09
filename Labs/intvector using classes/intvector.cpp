// -----------------------------------------------------
// CSC371 Advanced Object Oriented Programming (2023/24)
// Department of Computer Science, Swansea University
//
// Canvas: https://canvas.swansea.ac.uk/courses/44636
// -----------------------------------------------------

#include <iostream>
#include "intvector.h"

IntVector::IntVector(const unsigned int length) : data(NULL), pos(0), length(0) {
  // We could initialise the intvector here,
  // but why not just do this in resize to reduce malloc/free use
  // reduce risk for mistakes/errors
  resize(length);
}

IntVector::~IntVector() {
  if (data != nullptr) {
    free(data);
    //C Code: data = NULL;
    //C++ Code:
    data = nullptr;
  }
  
setPos(0);
setLength(0);
}

void IntVector::push(const int value) {
  if (getPos() > getLength() - 1) {
    resize(getLength() * 2);
  }
  
  this->data[this->pos++] = value;
}

int IntVector::pop() {
  if (getPos() <= 0) {
    printf("Cannot pop item from empty vector!\n");
    return 0;
  }
  
  return this->data[--this->pos];
}

void IntVector::resize(const unsigned int new_length) {
  // assume the struct is initialised already
  // if you are decreasing the size to zero, we should just deallocate
  //Do not need to call the destructor as we're using C++ now and not C
  this->data = (int*) realloc(this->data, sizeof(int)*new_length);
  this->length = new_length;
}

//Note about printing:
/* TODO: Overload the << operator using this function prototype in the class
declaration꞉
friend std::ostream& operator<<(std::ostream &os, const intvector &iv)
As it allows us to use free functions in this class and overload the << operator.
For the implementation of this function, we need to output information to the std::ostream
(standard output stream) reference passed in to the function. Note that in the implementa‑
tion, this function is not a member of the intvector class) and is simply an overloaded
function in the global scope.. */
std::ostream& operator<<(std::ostream& os, const IntVector& iv) {
  int i;
  for (i = 0; i < iv.getPos(); i++) {
    os << iv.getDataElement(i) << " ";
  }
  
  os << "] (used capacity = " << iv.getPos() << 
        ", spare = " << iv.getLength() - iv.getPos() << 
        ", total = " << iv.getLength() << ")\n";
  
  return os;
}

const unsigned int& IntVector::getPos() const {
  return this->pos;
}

const unsigned int& IntVector::getLength() const {
  return length;
}

const int& IntVector::getDataElement(int index) const {
        return data[index];
}

void IntVector::setPos(const unsigned int new_pos) {
  this->pos = new_pos;
}

void IntVector::setLength(const unsigned int new_length) {
  this->length = new_length;
}