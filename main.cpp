#include <iostream>
#include <vector>
#include "librairie.h"

using namespace std;

int main() {
   int result = 0;
   Line l1     {1, 2, 3};
   Line l2     {4, 5, 6};
   Line l3     {7, 8, 9};
   Line l4     {4, 4};
   Line l5     {1, 3};
   Line l6     {2};
   Matrix m1   {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
   Matrix m2   {{1, 2, 3}, {4, 5, 6}, {7, 8, 9, 10, 11, 12, 13}};
   Matrix m3   {{4, 4}, {1, 3}, {2}};

   cout << maxCol(m2);

   return 0;
}
