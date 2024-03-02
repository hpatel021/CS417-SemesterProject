#ifndef LEASTSQUARES_H_
#define LEASTSQUARES_H_

#include <vector>
#include <map>
#include <string>

/**
 * @class LeastSquares
 * @brief Performs least squares approximation on data provided in a map.
 *
 * This class takes a map as input, where the key is an integer representing the core and the value is a vector of floats representing data points.
 * It then performs least squares approximation and provides methods to access the results and print them to a file.
 */
class LeastSquares {
public:
    LeastSquares(const std::map<int, std::vector<float>>& m, std::string s);  

    void reduce(double m[2][3], int i);
    void eliminate(double m[2][3], int i);

    double getC0() const {
        return c0;
    }

    double getC1() const {
        return c1;
    }

    void printOutput(float c0, float c1, std::string s, int numEntries, int core); 

private:
    double matrix[2][3];
    double c0;
    double c1;
};
#endif 
