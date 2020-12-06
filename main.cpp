/*
 ---------------------------------------------------------------------------
 File            : main.cpp
 Laboratory name : Vecteur
 Authors         : Sarah Jallon & Valentin Chételat
 Date            : 06.12.2020
 Purpose         : This program's purpose is to prove the good operation of library.cpp.
                   This program displays the properties of chosen Matrices, and also does
                   a bunch of operations on Matrices.
 Comment(s)      : This program does not include interactions with the user.
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

   // ----------------------------------------------------------------------------------------------

   cout << "-------------- functions operator <<, isSquare,  is Regular --------------" << endl << endl;
   displayMatrixProperties(m1);
   displayMatrixProperties(m2);
   displayMatrixProperties(m3);
   cout << endl;

   // ----------------------------------------------------------------------------------------------

   cout << "-------------- function maxCol--------------" << endl << endl;
   displayMaxCol(m1);
   displayMaxCol(m2);
   displayMaxCol(m3);
   cout << endl;

   // ----------------------------------------------------------------------------------------------

   cout << "-------------- function sumLines--------------" << endl << endl;
   displaySumLines(m1);
   displaySumLines(m2);
   displaySumLines(m3);
   cout << endl;

   // ----------------------------------------------------------------------------------------------
   // init of the sum variables

   int sumResultLeftToRightDiagM1;
   int sumResultLeftToRightDiagM2;

   int sumResultRightToLeftDiagM1;
   int sumResultRightToLeftDiagM2;

   cout << "-------------- functions SumDiag--------------" << endl << endl;
   displaySumDiagLR(m1, sumResultLeftToRightDiagM1);
   displaySumDiagLR(m2, sumResultLeftToRightDiagM2);
   cout << endl;

   displaySumDiagRL(m1, sumResultRightToLeftDiagM1);
   displaySumDiagRL(m2, sumResultRightToLeftDiagM2);
   cout << endl;

   // ----------------------------------------------------------------------------------------------

   cout << "-------------- function VectSumMin--------------" << endl << endl;
   displayVectSumMin(m1);
   displayVectSumMin(m2);
   displayVectSumMin(m3);
   cout << endl;

   // ----------------------------------------------------------------------------------------------

   cout << "-------------- function shuffleMatrix--------------" << endl << endl;
   displayShuffledMatrix(m1);
   displayShuffledMatrix(m2);
   displayShuffledMatrix(m3);
   cout << endl;

   // ----------------------------------------------------------------------------------------------

   cout << "-------------- function sortMatrix--------------" << endl << endl;
   displaySortedMatrix(m1);
   displaySortedMatrix(m2);
   displaySortedMatrix(m3);
   cout << endl;

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
      cout << "The matrix " << m << " has no diagonal." << endl;
   }
}
void displaySumDiagRL(const Matrix& m, int& sumResult){
   if(sumDiagRL(m, sumResult)){
      cout << "The right to left diagonal sum of " << m << " is: " <<  sumResult << endl;
   }
   else {
      cout << "The matrix " << m << " has no diagonal." << endl;
   }

}