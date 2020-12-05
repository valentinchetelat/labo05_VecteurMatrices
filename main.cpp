#include <iostream>
#include <vector>
#include "librairie.h"

using namespace std;

void testIsSquare(const Matrix& m);


int main() {
   int result = 0;
   Line l1     {1, 2, 3};
   Line l2     {4, 5, 6};
   Line l3     {7, 8, 9};
   Line l4     {4, 4};
   Line l5     {1, 3};
   Line l6     {2};
   Line l7     {7, 8, 9, 10, 11, 12, 13};

   Matrix m1   {l1, l2, l3};
   Matrix m2   {l1, l2, l3, l4, l7};
   Matrix m3   {l4, l5, l6};

   //test function 1 "operator <<"
   cout << l1 << endl;
   cout << m1 << endl;

   testIsSquare(m1);
   testIsSquare(m2);
   testIsSquare(m3);



   return 0;
}

void testIsSquare(const Matrix& m) {
   if (isSquare(m)) {
   cout << "The matrix " << m << " is squared." <<endl;
   }
   else {
   cout << "The matrix " << m << " is not squared." <<endl;
   }
}