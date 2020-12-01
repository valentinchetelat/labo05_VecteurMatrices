#include <ostream>
#include <iostream>
#include "librairie.h"

using namespace std;

/* **************************************************
 * OPERATORS
 * **************************************************/
ostream& operator<<(ostream& os, const Matrix& matrix){
   cout << "[";

   //For each value in the line
   for (Matrix::const_iterator it = matrix.begin(); it != matrix.end(); ++it){

      //Print the value
      std::cout << *it;

      //Print the , after each value
      if(next(it) != matrix.end())
         cout << ", ";
   }

   cout << "]";
}

ostream& operator<<(ostream& os, const Line& line){
   cout << "(";

   //For each value in the line
   for (Line::const_iterator it = line.begin(); it != line.end(); ++it){

      //Print the value
      std::cout << *it;

      //Print the , after each value
      if(next(it) != line.end())
         cout << ", ";
   }

   cout << ")";
}

/* **************************************************
 * FUNCTIONS
 * **************************************************/
bool isSquare(Matrix matrix){
   const size_t MAT_SIZE = matrix.size();

   //Check if every line in the matrix has the same length as the height of the matrix
   for(Line l : matrix){
      if(l.size() != MAT_SIZE)
         return false;
   }

   return true;
}

bool isRegular(Matrix matrix){
   //An empty matrix is regular
   if(matrix.empty())
      return true;
}

size_t maxCol(Matrix matrix){
   size_t maxLength     = 0;
   size_t currentLength;

   //For each line of the matrix
   for(Line l : matrix){
      //Get its size
      currentLength = distance(l.begin(), l.end());
      //If it's bigger than the max
      if(currentLength > maxLength)
         //Update the max
         maxLength = currentLength;
   }

   return maxLength;
}

Line sumLines(Matrix matrix){
}

Line vectSumMin(Matrix matrix){

}

void shuffleMatrice(Matrix& matrix){

}

void sortMatrice(Matrix& matrix){

}

bool sumDiagDG(Matrix matrix, int& sumResult){
   //If the matrix is not square then return false immediately
   if(!isSquare(matrix))
      return false;

   const size_t SIZE = matrix.size();

   sumResult = 0;

   //The matrix is square so i and j have the same limit (SIZE)
   for(size_t i = 0; i < SIZE; ++i){
      for(size_t j = 0; j < SIZE; ++j){
         //If the element is from the / diagonal
         if ((i + j) == (SIZE - 1)){
            //Add the value to the result
            sumResult += matrix[i][j];

            //We can skip the rest of the line
            break;
         }
      }
   }

   return true;
}

bool sumDiagGD(Matrix matrix, int& sumResult){
   //If the matrix is not square then return false immediately
   if(!isSquare(matrix))
      return false;

   const size_t SIZE = matrix.size();

   sumResult = 0;

   for(size_t i = 0; i < SIZE; ++i){
      //We can use [i][i] because the \ diagonal is defined by
      //matrix[i][j] where j is equals to i
      sumResult += matrix[i][i];
   }

   return true;
}