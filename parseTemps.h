#ifndef PARSE_TEMPS_H_INCLUDED
#define PARSE_TEMPS_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <vector>
#include <iterator>
#include <algorithm>
#include <utility>
#include <map>

/**
 * @typedef CoreTempReading
 * @brief Represents a single set of temperature readings for different cores.
 *
 * This typedef defines a `CoreTempReading` as a pair, where the first element is the step number (timestamp) and the second element is a vector of core temperatures.
 */
using CoreTempReading = std::pair<int, std::vector<double>>;

/**
 * @brief Parses raw temperature readings from an input stream.
 *
 * This function reads lines of temperature readings from an input stream, parses each line into a set of core temperatures,
 * and stores the parsed readings as a vector of CoreTempReading objects.
 *
 * @param original_temps The input stream containing raw temperature readings.
 * @param step_size (Optional) The step size between readings (assumed to be consistent for all readings). Defaults to 30.
 * @return A vector of CoreTempReading objects, each containing a step number and a vector of core temperatures.
 */
std::vector<CoreTempReading> parse_raw_temps(std::istream& original_temps,int step_size=30);

/**
 * @brief Converts a vector of CoreTempReading objects into a map for easier access.
 *
 * This function takes a vector of CoreTempReading objects and creates a map where keys are core numbers (0-3)
 * and values are vectors of corresponding temperature readings.
 *
 * @param readings A vector of CoreTempReading objects.
 * @return A map with core numbers as keys and temperature readings as values.
 */
std::map<int, std::vector<float>> convertToMap(std::vector<CoreTempReading> readings);

#endif