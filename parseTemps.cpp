#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <utility>
#include <map>

#include "parseTemps.h"

/**
 * @brief Parses raw temperature readings from an input stream.
 *
 * This function reads lines of temperature readings from an input stream, parses each line into a set of core temperatures,
 * and stores the parsed readings as a vector of CoreTempReading objects.
 *
 * @param original_temps The input stream containing raw temperature readings.
 * @param step_size The step size between readings.
 * @return A vector of CoreTempReading objects, each containing a step number and a vector of core temperatures.
 */
std::vector<CoreTempReading> parse_raw_temps(std::istream& original_temps,int step_size) {
    std::vector<CoreTempReading> allTheReadings;
    int step = 0;
    std::string line;
    while (getline(original_temps, line)) {
        std::istringstream input(line);
        std::vector<double> next_temperature_set;
        std::transform(std::istream_iterator<std::string>(input),
                       std::istream_iterator<std::string>(),
                       std::back_inserter(next_temperature_set),
                       [](const std::string& raw_reading) -> double {
                        return stod(raw_reading); 
                    });
        allTheReadings.emplace_back(step, next_temperature_set);
        step += step_size;
    }
    return allTheReadings;
}

/**
 * @brief Converts a vector of CoreTempReading objects into a map for easier access.
 *
 * This function takes a vector of CoreTempReading objects and creates a map where keys are core numbers (0-3)
 * and values are vectors of corresponding temperature readings.
 *
 * @param readings A vector of CoreTempReading objects.
 * @return A map with core numbers as keys and temperature readings as values.
 */
std::map<int, std::vector<float>> convertToMap(std::vector<CoreTempReading> readings) {
    std::map<int, std::vector<float>> easierReadings;
    std::vector<float> first, second, third, fourth;
    for(auto it = readings.begin(); it != readings.end(); it++) {
        first.push_back(it->second[0]);
        second.push_back(it->second[1]);
        third.push_back(it->second[2]);
        fourth.push_back(it->second[3]);
    }
    easierReadings.insert(std::pair<int, std::vector<float>>(0, first));
    easierReadings.insert(std::pair<int, std::vector<float>>(1, second));
    easierReadings.insert(std::pair<int, std::vector<float>>(2, third));
    easierReadings.insert(std::pair<int, std::vector<float>>(3, fourth));
    return easierReadings;
}