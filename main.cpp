/*
 ---------------------------------------------------------------------------
 File            : main.cpp
 Laboratory name : Vecteur
 Authors         : Sarah Jallon & Valentin Chételat
 Date            : 06.12.2020
 Purpose         : This program's purpose is to prove the good operation of library.cpp.
                   This program displays the properties of a chosen Matrix, and also does
                   a bunch of operations on Matrices.
 Comment(s)      :
 Compiler        : MinGW-W64 g++ 8.1.0
 ---------------------------------------------------------------------------
*/

#include <iostream>
#include "librairie.h"

using namespace std;

void displayMatrixProperties(const Matrix& m);
void displayMaxCol(const Matrix& m);
void displaySumLines(const Matrix& m);
void displayVectSumMin(const Matrix& m);
void displayShuffledMatrix(Matrix& m);
void displaySortedMatrix(Matrix& m);
void displaySumDiagLR(const Matrix& m, int& sumResult);
void displaySumDiagRL(const Matrix& m, int& sumResult);



int main() {
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

   //test functions "operator <<", isSquare,  is Regular
   displayMatrixProperties(m1);
   displayMatrixProperties(m2);
   displayMatrixProperties(m3);

   displayMaxCol(m1);

   displaySumLines(m2);

   displayVectSumMin(m1);

   displayShuffledMatrix(m2);

   displaySortedMatrix(m2);

   int sumResultLeftToRightDiagM1;
   int sumResultRightToLeftDiagM2;
   displaySumDiagLR(m1, sumResultLeftToRightDiagM1);
   displaySumDiagRL(m2, sumResultRightToLeftDiagM2);

   // ----------------------------------------------------------------------------------------------
   //end of program
   return EXIT_SUCCESS;
}

void displayMatrixProperties(const Matrix& m){
   if (isRegular(m)) {
      cout << "The matrix " << m << " is regular ";
      if (isSquare(m)) {
         cout << "and square." <<endl;
      }
      else {
         cout << "and not square." <<endl;
      }
   }
   else {
      cout << "The matrix " << m << " is neither regular nor square." <<endl;
   }
}
void displayMaxCol(const Matrix& m){
   cout << "The longest vector length of " << m << " is: " << maxCol(m) << endl;
}
void displaySumLines(const Matrix& m){
   cout << "The lines sums of " << m << " is the vector: " << sumLines(m) << endl;
}
void displayVectSumMin(const Matrix& m){
   cout << "The lowest vector sum of " << m << " is the vector: " << vectSumMin(m) << endl;
}
void displayShuffledMatrix(Matrix& m){
   cout << "The shuffled version of " << m << " is: " << endl;
   shuffleMatrix(m);
   cout << m << endl;
}
void displaySortedMatrix(Matrix& m){
   cout << "The sorted version of " << m << " is: " << endl;
   sortMatrix(m);
   cout << m << endl;
}
void displaySumDiagLR(const Matrix& m, int& sumResult){
   if (sumDiagLR(m, sumResult)){
      cout << "The left to right diagonal sum of " << m << " is: " << sumResult << endl;
   }
   else {
      cout << "The matrix " << m << " has no diagonal.";
   }
}
void displaySumDiagRL(const Matrix& m, int& sumResult){
   if(sumDiagRL(m, sumResult)){
      cout << "The right to left diagonal sum of " << m << " is: " <<  sumResult << endl;
   }
   else {
      cout << "The matrix " << m << " has no diagonal.";
   }

}