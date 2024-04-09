// -----------------------------------------------------
// CSC371 Advanced Object Oriented Programming (2023/24)
// Department of Computer Science, Swansea University
//
// Canvas: https://canvas.swansea.ac.uk/courses/44636
// -----------------------------------------------------

#include <iostream>
#ifndef INTVECTOR_H_
#define INTVECTOR_H_

#define INTVECTOR_INIT_SIZE 10

//struct intvector {
//	int *data;
//	unsigned int pos;
//	unsigned int length;
//};

class IntVector 
{
private:
  /* Data */
  int *data;
  unsigned int pos;
  unsigned int length;
public:
    //Need to pass in the structure we're using
    //in object oriented languages you have access to this through self
    //or this->
  IntVector(const unsigned int length);
  ~IntVector();

  void push(const int value);

  int pop();

  void resize(const unsigned int new_length);

  void print() const;

  //These get‑
  //ters should return “constant references” to the underlying member variables to ensure
  //that simply “getting” their values doesn’t cause a temporary duplicate to be made.
  const unsigned int& getPos() const;
  const unsigned int& getLength() const;
  const int& getDataElement(int index) const;

  void setPos(unsigned int pos);
  void setLength(unsigned int lives);

  friend std::ostream& operator<<(std::ostream& os, const IntVector &iv);

  int* getData(const IntVector& vec) { return const_cast<int*>(vec.data); }

};

#endif // INTVECTOR_H_

// =====================================================
// Old C code left here as a comment
// =====================================================

/*
void intvector_construct(
  struct intvector * const iv, 
  const unsigned int length) {
  
  // always clear data
  iv->data   = NULL;
  iv->pos    = 0;
  iv->length = 0;
  
  // We could initialise the intvector here,
  // but why not just do this in resize to reduce malloc/free use
  // reduce risk for mistakes/errors
  intvector_resize(iv, length);
}

void intvector_destruct(struct intvector * const iv) {
  if (iv->data != NULL) {
    free(iv->data);
    iv->data = NULL;
  }
  
  iv->pos = 0;
  iv->length = 0;
}

void intvector_push(struct intvector * const iv, const int value) {
  if (iv->pos > iv->length - 1) {
    intvector_resize(iv, iv->length * 2);
  }
  
  iv->data[iv->pos++] = value;
}

int intvector_pop(struct intvector * const iv) {
  if (iv->pos <= 0) {
    printf("Cannot pop item from empty vector!\n");
    return 0;
  }
  
  return iv->data[--(iv->pos)];
}

void intvector_resize(
  struct intvector * const iv,
  const unsigned int new_length) {
  // assume the struct is initialised already
  // if you are decreasing the size to zero, we should just dellocate
  
  if (new_length > 0) {
    iv->data = (int*) realloc(iv->data, sizeof(int)*new_length);
    iv->length = new_length;
  } else {
    intvector_destruct(iv);
  }
}

void intvector_print(const struct intvector * const iv) { 
  printf("%p [ ", iv->data);
  int i;
  for (i = 0; i < iv->pos; i++) {
    printf("%d ", iv->data[i]);
  }
  printf(
    "] (used capacity = %d, spare = %d, total = %d)\n",
    iv->pos,
    iv->length - iv->pos,
    iv->length);
}

  void intvector_copy_construct(
      struct intvector * const x,
      const struct intvector * const x_other) {
    intvector_construct(x, x_other->length);
    memcpy(x->data, x_other->data, x->length * sizeof(int));
    
    // remember our pointer to the next available position needs setting!
    x->pos = x_other->pos;
  }

  void intvector_copy_assign(
      struct intvector * const x,
      const struct intvector * const x_other) {
    intvector_resize(x, x_other->length); 
    memcpy(x->data, x_other->data, x->length * sizeof(int));
      x->pos = x_other->pos;
  }

*/
