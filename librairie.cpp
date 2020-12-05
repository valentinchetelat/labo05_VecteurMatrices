#include <ostream>
#include <iostream>
#include <chrono>
#include <random>
#include "librairie.h"

using namespace std;

/* **************************************************
 * PROTOTYPES
 * **************************************************/
int      sumLine(const Line& line);
bool     compare(Line& a, Line& b);
size_t   sizeOfVector(const Line& line);
size_t   compareSizeVectors(const Line& l1, const Line& l2);

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
   return matrix.empty() ||
          isRegular(matrix) && matrix[0].size() == matrix.size();
}

bool isRegular(Matrix matrix){
   //An empty matrix is regular
   if(matrix.empty())
      return true;

   Line result(matrix.size());

   transform(matrix.begin(), matrix.end(), result.begin(), sizeOfVector);

   return count(result.begin(), result.end(), result[0]) == matrix.size();
}

size_t maxCol(const Matrix& matrix){
   return (*max_element(matrix.begin(), matrix.end(), compareSizeVectors)).size();
}

Line sumLines(const Matrix& matrix){
   Line result(matrix.size());

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

/* **************************************************
 * UTILITIES
 * **************************************************/
int sumLine(const Line& line){
   return accumulate(line.begin(), line.end(), 0);
}

bool compare(Line& a, Line& b){
   return max_element(a.begin(), a.end()) > max_element(b.begin(), b.end());
}

size_t sizeOfVector(const Line& line){
   return line.size();
}

size_t compareSizeVectors(const Line& l1, const Line& l2){
   return l1.size() < l2.size();
}