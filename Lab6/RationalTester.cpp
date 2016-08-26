#include "RationalArray.h"
#include "Rational.h"
#include <iostream>
using namespace std;

Rational CalculateMean(RationalArray &numbers);

int main(int argc, char* argv[]) {
   RationalArray arr(5);

   arr[0].SetNumerator(5);
   arr[0].SetDenominator(3);
   cout << "arr[0] = " << arr[0] << endl; // what should this print?

   arr[1] = Rational(3, -5);
   cout << "arr[1] = " << arr[1] << endl << endl;

   arr[2] = Rational(8, -2);
   arr[3] = Rational(12, 9);
   arr[4] = Rational(22, 14);

   RationalArray copy(arr);
   copy[0].SetNumerator(10);
   cout << "copy[0] = " << copy[0] << endl;
   cout << "arr[0] = " << arr[0] << endl;

   try {
      cout << "Accessing arr out of bounds " << endl;
      cout << arr[5] << endl;
   }
   catch (std::out_of_range &ex) {
      cout << "Caught the exception" << endl << endl;
   }

   RationalArray larger(100);
   cout << "Remember, all objects in an array are default constructed." << endl;
   cout << "So larger[10] should = ... " << larger[10] << endl << endl;

   larger = arr;
   cout << "Now that arr has been deep-assigned into larger, larger's size is "
      << "...  " << larger.Size() << ";" << endl
      << "   and its index 0 is " << larger[0] << endl << endl;

   larger[0].SetNumerator(15);
   cout << "larger[0] = " << larger[0] << endl;
   cout << "arr[0] = " << arr[0] << endl << endl;



   // TO FINISH THIS ASSIGNMENT, you must implement the CalculateMean function
   // below, so that this code correctly outputs the mean value of the five
   // numbers in arr.
   Rational average = CalculateMean(arr);
   cout << "The average of ";
   for (int i = 0; i < arr.Size(); i++) {
      cout << arr[i];
      if (i < arr.Size() - 1)
         cout << ", ";
   }
   cout << " is " << average << endl;
}

Rational CalculateMean(RationalArray &numbers) {
   // Finish this method according to the requirements. The return below is
   // just so the code compiles.
   return Rational();
}