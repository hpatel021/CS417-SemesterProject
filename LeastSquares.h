#ifndef LEASTSQUARES_H_
#define LEASTSQUARES_H_
#include <vector>
#include <map>
#include <string>

class LeastSquares {
public:
    /**
     * Performs least squares approximation for given data and writes the result to files.
     *
     * @param m A map containing data for each core.
     * @param s A string to be written to the output files.
     */
    static void performApproximation(const std::map<int, std::vector<float>>& m, const std::string& s);

private:
    /**
     * Reduces the given row of the matrix by dividing all elements by the diagonal element.
     *
     * @param m The matrix to be reduced.
     * @param i The index of the row to be reduced.
     */
    static void reduce(double m[2][3], int i);

    /**
     * Performs elimination to make elements below the diagonal zero.
     *
     * @param m The matrix to be eliminated.
     * @param i The index of the row to be used as pivot.
     */
    static void eliminate(double m[2][3], int i);
};

#endif 