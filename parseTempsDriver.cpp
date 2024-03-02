#include "parseTemps.h"
#include "LeastSquares.h"
#include "LinearInterpolation.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

/**
 * @brief Main function of the program.
 *
 * This function takes an input file name as an argument, parses the raw temperature readings from the file,
 * and creates instances of LeastSquares and LinearInterpolation classes for further analysis.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return 0 on success, non-zero on error.
 */
int main(int argc, char** argv)
{
    // Input validation
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " input_file_name" << "\n";
        return 1;
    }
    
    for(int i = 1; i < argc; i++) {
    	ifstream input_temps(argv[i]);
    	if (!input_temps) {
            cout << "ERROR: " << argv[i] << " could not be opened" << "\n";
            return 2;
    	}
    	// End Input Validation
        vector<CoreTempReading> readings = parse_raw_temps(input_temps);

        // Convert the readings to a map (easier for me to manipulate)
        map<int, vector<float>> easierReadings = convertToMap(readings);

        LeastSquares least(easierReadings, argv[i]);
        LinearInterpolation linInterp(easierReadings);
    }
    return 0;
}