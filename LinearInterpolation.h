#ifndef LINEARINTERPOLATION_H_
#define LINEARINTERPOLATION_H_
#include <vector>
#include <map>

/**
 * @class LinearInterpolation
 * @brief Performs linear interpolation on data provided in a map.
 *
 * This class takes a map as input, where the key is an integer representing the core and the value is a vector of floats representing data points.
 * It provides functionalities to calculate the slope and intercept of a line segment connecting two data points within the provided map for a specific core.
 */
class LinearInterpolation {
public:
	LinearInterpolation(const std::map<int, std::vector<float>> m);
	float calcSlope(const std::map<int, std::vector<float>> m, int x, int core);
	float calcIntercept(std::map<int, std::vector<float>> m, float slope, int x, int core);

private:
	float slope;
	float intercept;
};
#endif 