#include "LinearInterpolation.h"
#include <vector>
#include <math.h>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

/**
 * @class LinearInterpolation
 * @brief Performs piecewise linear interpolation on data provided in a map.
 *
 * This class takes a map as input, where the key is an integer representing the core and the value is a vector of floats representing data points.
 * It then performs piecewise linear interpolation and writes the results to separate files for each core.
 */
LinearInterpolation::LinearInterpolation(map<int, vector<float>> m) {
	for(int core = 0; core < 4; core++) {
		fstream out;
		ostringstream os;
		os << "input-core" << core << ".txt";
		string fileName = os.str();
		out.open(fileName, fstream::in | fstream::out | fstream::app);
		out << "\n|----------------------------------------------------------|\n";
		out << "\t\t\t\tPiecewise Linear Interpolation";
		out << "\n|----------------------------------------------------------|\n\n";
		int end = m.find(core)->second.size() - 1;
		for(int i = 0; i < end; i++) {
			float slope = calcSlope(m, i, core);
			float b = calcIntercept(m, slope, i, core);
			out << i * 30 <<" < x < " << (i+1) * 30 << "; y = " << b;
			if(slope >= 0)
			out << " + " << slope <<"x; Linear Interpolation\n";
			else
			out << " - " << abs(slope) <<"x; Linear Interpolation\n";
		}
		out<<"\n\n";
		out.close();
	}
}

/**
 * @brief Calculates the slope of a line segment between two data points.
 *
 * This function takes a map containing data points, an index representing the x-value, and a core number as input.
 * It calculates the slope of the line segment connecting the data points at the provided index and the next index for the specified core.
 * 
 * @param m The map containing data points.
 * @param x The index representing the x-value (data point).
 * @param core The core number.
 * @return The slope of the line segment.
 */
float LinearInterpolation::calcSlope(const map<int, vector<float>> m, int x, int core){
	float yChange = m.find(core)->second[x+1] - m.find(core)->second[x];
	float xChange = ((x+1) * 30) - (x * 30);
	return yChange / xChange;
}

/**
 * @brief Calculates the y-intercept of a line segment.
 *
 * This function takes a map containing data points, the slope of the line segment, an index representing the x-value, and a core number as input.
 * It calculates the y-intercept of the line segment using the provided slope and the data point at the specified index and core.
 * 
 * @param m The map containing data points.
 * @param slope The slope of the line segment.
 * @param x The index representing the x-value (data point).
 * @param core The core number.
 * @return The y-intercept of the line segment.
 */
float LinearInterpolation::calcIntercept(map<int, vector<float>>m, float slope, int x, int core){
	return m.find(core)->second[x] - (slope * x * 30);
}