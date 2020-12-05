#include <iostream>
#include <vector>
#include "librairie.h"

using namespace std;

int main() {
   int result = 0;
   Line l1     {1, 2, 3};
   Line l2     {4, 5, 6};
   Line l3     {7, 8, 9};
   Matrix m1   {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
   Matrix m2   {{1, 2, 3}, {4, 5, 6}, {7, 8, 9, 10, 11, 12, 13}};

   cout << isRegular(m2);

   cout << "Is square   ? " << isSquare(m1) << endl;

   sumDiagLR(m1, result);
   cout << "Sum \\ diag  : " << result << endl;
   sumDiagRL(m1, result);
   cout << "Sum / diag  : " << result << endl;

   cout << "Max length is " << maxCol(m1) << endl;
   cout << "Max length is " << maxCol(m2) << endl;

   cout << "blblbl" << vectSumMin(m1) << endl;
   sortMatrice(m2);
   cout << l1;
   cout << m2;

   cout << endl << endl << sumLines(m1);

   return 0;
}
