/*
 ---------------------------------------------------------------------------
 File            : librairie.h
 Laboratory name : Vecteur
 Authors         : Sarah Jallon & Valentin Chételat
 Date            : 06.12.2020
 Purpose         : This file is the header of our library
 Comment(s)      : The functions explanations are in this file
 Compiler        : MinGW-W64 g++ 8.1.0
 ---------------------------------------------------------------------------
*/


#ifndef LABO_05_VECTEURMATRICES_LIBRAIRIE_H
#define LABO_05_VECTEURMATRICES_LIBRAIRIE_H

/* **************************************************
 * INCLUDES
 * **************************************************/
#include <vector>
#include <algorithm>
#include <numeric>
#include <ostream>

/* **************************************************
 * USINGS
 * **************************************************/
using Line     = std::vector<int>;
using Matrix   = std::vector<Line>;

/* **************************************************
 * PROTOTYPES
 * **************************************************/
/**
 * Operator << to display Matrices
 * @param os
 * @param matrix
 * @return
 */
std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

/**
 * Operator << to display Lines of matrices
 * @param os
 * @param line
 * @return
 */
std::ostream& operator<<(std::ostream& os, const Line& line);

/**
 * Return true if the matrix is square
 * A matrix is square if the number of columns and number of rows are equals
 * @param matrix
 * @return
 */
bool isSquare(Matrix matrix);

/**
 * Return true if the Matrix is empty
 * @param matrix
 * @return
 */
bool isRegular(Matrix matrix);

/**
 * Return the length of the line with the most elements in the matrix
 * @param matrix
 * @return
 */
size_t maxCol(const Matrix& matrix);

/**
 * Return a vector with the sum of all the lines of the matrix
 * @param matrix
 * @return
 */
Line sumLines(const Matrix& matrix);

/**
 * Return the line of the matrix for which the sum of all elements is the smallest of the matrix
 * @param matrix
 * @return
 */
Line vectSumMin(Matrix matrix);

/**
 * Shuffle the order of the lines in the matrix
 * @param matrix
 */
void shuffleMatrix(Matrix& matrix);

/**
 * Sort the matrix depending on the biggest element of each line
 * ex: [(4, 4), (1, 3), (2)] -> [(4,4), (1, 3), (2)]
 * @param matrix
 */
void sortMatrix(Matrix& matrix);

/**
 * Sum all elements of the / (top right to bottom left) diagonal of a matrix
 * @param matrix
 * @param sumResult
 * @return
 */
bool sumDiagRL(Matrix matrix, int& sumResult);

/**
 * Sum all elements of the \ (top left to bottom right) diagonal of a matrix
 * @param matrix
 * @param sumResult
 * @return
 */
bool sumDiagLR(Matrix matrix, int& sumResult);

#endif //LABO_05_VECTEURMATRICES_LIBRAIRIE_H