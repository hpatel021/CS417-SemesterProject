#include "parseTemps.h"
#include "LeastSquares.h"
#include "LinearInterpolation.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

/**
 * The main function of the program.
 * Reads temperature data from input files, performs least squares approximation and linear interpolation,
 * and writes the results to output files.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of C-style strings containing the command-line arguments.
 * @return An integer representing the exit status of the program.
 */
int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " input_file_name" << "\n";
        return 1;
    }
    for(int i = 1; i < argc; i++) {
        std::ifstream input_temps(argv[i]);
        if (!input_temps) {
            std::cout << "ERROR: " << argv[i] << " could not be opened" << "\n";
            return 2;
        }
        std::vector<CoreTempReading> readings = parse_raw_temps(input_temps);
        std::map<int, std::vector<float>> easierReadings = convertToMap(readings);

        LeastSquares::performApproximation(easierReadings, argv[i]);
        LinearInterpolation::performInterpolation(easierReadings);
    }
    return 0;
}