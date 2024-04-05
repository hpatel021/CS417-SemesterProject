#ifndef LINEARINTERPOLATION_H_
#define LINEARINTERPOLATION_H_
#include <vector>
#include <map>

class LinearInterpolation {
public:
    /**
     * Performs piecewise linear interpolation for each core and writes the result to files.
     *
     * @param m A map containing data for each core.
     */
    static void performInterpolation(const std::map<int, std::vector<float>>& m);

private:
    /**
     * Calculates the slope between two consecutive points.
     *
     * @param m A map containing data for each core.
     * @param x The index of the first point.
     * @param core The core index.
     * @return The slope between the two points.
     */
    static float calcSlope(const std::map<int, std::vector<float>>& m, int x, int core);

    /**
     * Calculates the intercept of the linear equation.
     *
     * @param m A map containing data for each core.
     * @param slope The slope of the line.
     * @param x The index of the point.
     * @param core The core index.
     * @return The intercept of the linear equation.
     */
    static float calcIntercept(const std::map<int, std::vector<float>>& m, float slope, int x, int core);
};

#endif 