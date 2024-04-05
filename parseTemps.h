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
 * A type representing a core temperature reading.
 * It consists of a step number and a vector of temperature readings.
 */
using CoreTempReading = std::pair<int, std::vector<double>>;

/**
 * Parses raw temperature readings from the input stream and constructs CoreTempReading objects.
 *
 * @param original_temps The input stream containing raw temperature readings.
 * @param step_size The step size between consecutive temperature readings (default is 30).
 * @return A vector of CoreTempReading objects.
 */
std::vector<CoreTempReading> parse_raw_temps(std::istream& original_temps, int step_size=30);

/**
 * Converts a vector of CoreTempReading objects to a map with core indices as keys and temperature vectors as values.
 *
 * @param readings A vector of CoreTempReading objects.
 * @return A map with core indices as keys and temperature vectors as values.
 */
std::map<int, std::vector<float>> convertToMap(const std::vector<CoreTempReading>& readings);

#endif