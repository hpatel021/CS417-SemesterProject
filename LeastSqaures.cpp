#include "LeastSquares.h"
#include <vector>
#include <math.h>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

/**
 * @class LeastSquares
 * @brief Performs least squares approximation on data provided in a map.
 *
 * This class takes a map as input, where the key is an integer representing the core and the value is a vector of floats representing data points.
 * It then performs least squares approximation and prints the results to a file.
 */
LeastSquares::LeastSquares(const std::map<int, std::vector<float>>& m, std::string s) {
    for(int core = 0; core < 4; core++) {
        int numEntries = m.find(core)->second.size();
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 3; j++) {
                matrix[i][j]=0;
            }
        }
        int pi0pi0 = numEntries;
        double pi0pi1 = 0;
        double pi0f = 0;
        double pi1pi1 = 0;
        double pi1f = 0;
        for(int xVals = 0; xVals < numEntries; xVals++) {
            pi0pi1 += xVals * 30;
            pi0f += m.find(core)->second[xVals];
            pi1pi1 += (xVals * 30) * (xVals * 30);
            pi1f += (m.find(core)->second[xVals]) * (xVals * 30);
        }
        matrix [0][0] = pi0pi0;
        matrix[0][1] = pi0pi1;
        matrix [0][2] = pi0f;
        matrix [1][0] = pi0pi1;
        matrix [1][1] = pi1pi1;
        matrix [1][2] = pi1f;

        for(int i = 0; i < 2; i++) {
            reduce(matrix, i);
            eliminate(matrix, i);
        }
        c0 = matrix[0][2];
        c1 = matrix[1][2];

        printOutput(c0, c1, s, numEntries, core);
    }
}

/**
 * @brief Performs row reduction on a specific row in a matrix.
 *
 * This function takes a 2x3 matrix and an integer representing the row index as input.
 * It then divides each element in the specified row by the diagonal element (m[i][i]).
 * 
 * @param m The 2x3 matrix to be operated on.
 * @param i The index of the row to be reduced.
 */
void LeastSquares::reduce(double m[2][3], int i) {
    double factor = m[i][i];
    for(int index = i; index < 3; index++) {
        float temp = m[i][index];
        m[i][index] = temp / factor;
    }
}

/**
 * @brief Performs Gaussian elimination on a 2x3 matrix.
 *
 * This function takes a 2x3 matrix and an integer representing the row index as input.
 * It performs Gaussian elimination on the matrix to eliminate non-zero elements above or below the diagonal.
 * 
 * @param m The 2x3 matrix to be operated on.
 * @param i The index of the row to be used for elimination.
 */
void LeastSquares::eliminate(double m[2][3], int i) {
    if(i == 0) {
        double factor = m[1][0];
        for(int index = 0; index < 3; index++) {
            double temp = m[1][index];
            m[1][index] = temp - (factor * m[0][index]);
        }
    }
    if (i ==1) {
        double factor = m[0][1];
        for(int index = 1; index < 3; index++) {
            double temp = m[0][index];
            m[0][index] = temp - (factor * m[1][index]);
        }
    }
}

/**
 * @brief Prints the least squares approximation results to a file.
 *
 * This function takes five arguments:
 *   - c0: The constant coefficient in the least squares approximation equation.
 *   - c1: The linear coefficient in the least squares approximation equation.
 *   - s: A string to be included in the output file.
 *   - numEntries: The number of data points used in the calculation.
 *   - core: The core number for which the approximation was performed.
 * 
 * It then creates a file name based on the core number and opens it in append mode.
 * The function then writes the formatted least squares approximation equation and other information to the file.
 * 
 * @param c0 The constant coefficient.
 * @param c1 The linear coefficient.
 * @param s A string to be included in the output.
 * @param numEntries The number of data points used.
 * @param core The core number.
 */
void LeastSquares::printOutput(float c0, float c1, string s, int numEntries, int core) {
    fstream out;
    ostringstream os;
    os << "input-core" << core << ".txt";
    string fileName = os.str();
    out.open(fileName, fstream::in | fstream::out | fstream::app);
    out << s;
    out << "\n|----------------------------------------------------------|\n";
    out << "\t\t\t\tLeast Squares Approximation";
    out << "\n|----------------------------------------------------------|\n\n";
    out << "0 < x < "<<numEntries*30<<"; y= "<<c0;
    if(c1 >= 0)
    out << " + "<<c1<<"x; Least Squares Approximation\n";
    else
    out << " - "<<abs(c1)<<"x; Least Squares Approximation\n";
    out.close();
}