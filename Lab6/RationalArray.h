// this is a LAB ASSIGNMENT

#ifndef __RationalArray_H
#define __RationalArray_H

// Implement a class representing an array of Rationals with a size determined
// at *run-time*. This array will be bounds-checked when indexing.
#include "Rational.h"

class RationalArray {
private:
   // The size of the array.
   int mSize;

   // A pointer to the actual array of values on the heap.
   Rational *mArray;

public:
   // Construct an array with the specified size, which is not known until
   // runtime. 
   RationalArray(int size);

   // Destructor: clean up any memory placed on the heap by this object.
   ~RationalArray();

   // Copy constructor: make a deep copy of the parameter's array.
   RationalArray(const RationalArray &other);

   // Assignment operator: make a deep copy of the rhs parameter. This will 
   // override any array currently held by this object; do not leak the old
   // array!
   RationalArray& operator=(const RationalArray& rhs);

   // Indexing operator: given an index, return the value at that index in 
   // mArray. Should throw std::out_of_range from <stdexcept> if the rhs index
   // is not in bounds of the array.
   Rational& operator[](int rhs);


   // Return the size of the array.
   inline int Size() const {
      return mSize;
   }
};

#endif