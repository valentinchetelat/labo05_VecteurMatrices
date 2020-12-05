#include <ostream>
#include <iostream>
#include <chrono>
#include <random>
#include "librairie.h"

using namespace std;

/* **************************************************
 * PROTOTYPES
 * **************************************************/
int sumLine(const Line& line);

/* **************************************************
 * OPERATORS
 * **************************************************/
ostream& operator<<(ostream& os, const Matrix& matrix){
   cout << "[";

   //For each value in the line
   for (Matrix::const_iterator it = matrix.begin(); it != matrix.end(); ++it){

      //Print the value
      cout << *it;

      //Print the , after each value
      if(next(it) != matrix.end())
         cout << ", ";
   }

   cout << "]";
}

ostream& operator<<(ostream& os, const Line& line){
   cout << "(";

   for (Line::const_iterator it = line.begin(); it != line.end(); ++it){

      //Print the value
      cout << *it;

      //Print the , after each value except the last
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

   for (int i = 0; i < matrix.size(); i++){
      if(matrix[i].size() != matrix[1].size())
         return false;
   }
   return true;

}

size_t maxCol(const Matrix& matrix){
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

Line sumLines(const Matrix& matrix){
   Line result(matrix.size());

   //For each line
   transform(matrix.begin(), matrix.end(), result.begin(), sumLine);

   return result;
}

Line vectSumMin(Matrix matrix){
   int somme = 0;
   Line vector;
   for(Line l : matrix){
         if( somme > accumulate(l.begin(),l.end(),0) || somme == 0){
            somme = accumulate(l.begin(),l.end(),0);
            vector = l;
         }
         else if (somme == accumulate(l.begin(),l.end(),0) && vector.size() > l.size()){
            vector = l;
         }
      }
   return vector;
}


void shuffleMatrix(Matrix& matrix){
   unsigned seed = chrono::system_clock::now().time_since_epoch().count();
   shuffle (matrix.begin(), matrix.end(), default_random_engine(seed));
}

bool compare(Line& a, Line& b){
    return max_element(a.begin(), a.end()) > max_element(b.begin(), b.end());
}

void sortMatrix(Matrix& matrix){
   sort(matrix.begin(), matrix.end(), compare);
}


bool sumDiagRL(Matrix matrix, int& sumResult){
   //If the matrix is not square then return false immediately
   if(!isSquare(matrix))
      return false;

   const size_t SIZE = matrix.size();

   sumResult = 0;

   //The matrix is square so i and j have the same limit (SIZE)
   for(size_t i = 0; i < SIZE; ++i){
      sumResult += matrix[i][matrix.size() - i - 1];
   }

   return true;
}

bool sumDiagLR(Matrix matrix, int& sumResult){
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

int sumLine(const Line& line){
   return accumulate(line.begin(), line.end(), 0);
}