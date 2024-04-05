#include "parseTemps.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <utility>
#include <map>

/**
 * Parses raw temperature readings from the input stream and constructs CoreTempReading objects.
 *
 * @param original_temps The input stream containing raw temperature readings.
 * @param step_size The step size between consecutive temperature readings.
 * @return A vector of CoreTempReading objects.
 */
std::vector<CoreTempReading> parse_raw_temps(std::istream& original_temps, int step_size) {
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
 * Converts a vector of CoreTempReading objects to a map with core indices as keys and temperature vectors as values.
 *
 * @param readings A vector of CoreTempReading objects.
 * @return A map with core indices as keys and temperature vectors as values.
 */
std::map<int, std::vector<float>> convertToMap(const std::vector<CoreTempReading>& readings) {
    std::map<int, std::vector<float>> easierReadings;
    std::vector<float> first, second, third, fourth;
    for(const auto& reading : readings) {
        first.push_back(reading.second[0]);
        second.push_back(reading.second[1]);
        third.push_back(reading.second[2]);
        fourth.push_back(reading.second[3]);
    }
    easierReadings.emplace(0, first);
    easierReadings.emplace(1, second);
    easierReadings.emplace(2, third);
    easierReadings.emplace(3, fourth);
    return easierReadings;
}