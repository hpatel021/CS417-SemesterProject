#include "LeastSquares.h"
#include <fstream>
#include <sstream>

/**
 * Performs least squares approximation for given data and writes the result to files.
 *
 * @param m A map containing data for each core.
 * @param s A string to be written to the output files.
 */
void LeastSquares::performApproximation(const std::map<int, std::vector<float>>& m, const std::string& s) {
    for(int core = 0; core < 4; core++) {
        int numEntries = m.find(core)->second.size();
        double matrix[2][3] = {{0}};
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
        matrix [0][1] = pi0pi1;
        matrix [0][2] = pi0f;
        matrix [1][0] = pi0pi1;
        matrix [1][1] = pi1pi1;
        matrix [1][2] = pi1f;

        for(int i = 0; i < 2; i++) {
            reduce(matrix, i);
            eliminate(matrix, i);
        }
        double c0 = matrix[0][2];
        double c1 = matrix[1][2];

        std::fstream out;
        std::ostringstream os;
        os << "input-core" << core << ".txt";
        std::string fileName = os.str();
        out.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app);
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
}

/**
 * Reduces the given row of the matrix by dividing all elements by the diagonal element.
 *
 * @param m The matrix to be reduced.
 * @param i The index of the row to be reduced.
 */
void LeastSquares::reduce(double m[2][3], int i) {
    double factor = m[i][i];
    for(int index = i; index < 3; index++) {
        m[i][index] /= factor;
    }
}

/**
 * Performs elimination to make elements below the diagonal zero.
 *
 * @param m The matrix to be eliminated.
 * @param i The index of the row to be used as pivot.
 */
void LeastSquares::eliminate(double m[2][3], int i) {
    if(i == 0) {
        double factor = m[1][0];
        for(int index = 0; index < 3; index++) {
            m[1][index] -= factor * m[0][index];
        }
    }
    if (i ==1) {
        double factor = m[0][1];
        for(int index = 1; index < 3; index++) {
            m[0][index] -= factor * m[1][index];
        }
    }
}