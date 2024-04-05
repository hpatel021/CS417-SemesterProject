#include "LinearInterpolation.h"
#include <fstream>
#include <sstream>

/**
 * Performs piecewise linear interpolation for each core and writes the result to files.
 *
 * @param m A map containing data for each core.
 */
void LinearInterpolation::performInterpolation(const std::map<int, std::vector<float>>& m) {
    for(int core = 0; core < 4; core++) {
        std::fstream out;
        std::ostringstream os;
        os << "input-core" << core << ".txt";
        std::string fileName = os.str();
        out.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app);
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
 * Calculates the slope between two consecutive points.
 *
 * @param m A map containing data for each core.
 * @param x The index of the first point.
 * @param core The core index.
 * @return The slope between the two points.
 */
float LinearInterpolation::calcSlope(const std::map<int, std::vector<float>>& m, int x, int core) {
    float yChange = m.find(core)->second[x+1] - m.find(core)->second[x];
    float xChange = ((x+1) * 30) - (x * 30);
    return yChange / xChange;
}

/**
 * Calculates the intercept of the linear equation.
 *
 * @param m A map containing data for each core.
 * @param slope The slope of the line.
 * @param x The index of the point.
 * @param core The core index.
 * @return The intercept of the linear equation.
 */
float LinearInterpolation::calcIntercept(const std::map<int, std::vector<float>>& m, float slope, int x, int core){
    return m.find(core)->second[x] - (slope * x * 30);
}