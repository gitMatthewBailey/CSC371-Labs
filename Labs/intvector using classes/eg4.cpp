// -----------------------------------------------------
// CSC371 Advanced Object Oriented Programming (2023/24)
// Department of Computer Science, Swansea University
//
// Canvas: https://canvas.swansea.ac.uk/courses/44636
// -----------------------------------------------------

#include <iostream>
#include "intvector.h"

int main() {
  // create initial struct
  IntVector x(INTVECTOR_INIT_SIZE);
  std::cout << "Construct x" << std::endl;

  // can we add?
  std::cout << "\n\nPush 1 to x\n  ";
  x.push(1);

  std::cout << "\nPrint x (data is at " << x.getData(x) << ")\n  " << x << std::endl;
  
  // copy the struct
  std::cout << "\nShallow copy x to y";
  IntVector y(x);

  // can we add?
  std::cout << "\n\nPush 2 to x\n  ";
  x.push(2);

  // print original struct
  std::cout << "\nPrint x (data is at " << x.getData(x) << ")\n  " << x << std::endl;

  // print new struct
  std::cout << "\nPrint y (data is at " << y.getData(y) << ")\n  " << y << std::endl;

  // destroy original struct
  std::cout << "\nDestruct y" << std::endl;
  y.~IntVector();

  // print original struct
  std::cout << "\n\nPrint x (data is at " << x.getData(x) << ")\n  " << x << std::endl;
  
  // print new struct
  std::cout << "\nPrint y (data is at " << y.getData(y) << ")\n  ";
  std::cout << "ERROR: Attempting to print a destructed struct!" << std::endl;

  // destroy original struct
  std::cout << "\nDestruct x\n" << std::endl;
  x.~IntVector();
}
