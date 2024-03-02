## CPU Temperature Parser
-  This C++ program is designed to parse CPU temperature data from an input file and organize it into a structured format.
-  The program provides flexibility by allowing the use of different container types for storing the parsed data. 

## Features
-  Flexible Container Type:
-  Core Temperature Reading Structure:

## Usage
  To use this program, follow these steps:
1.  Compile the code: Use a C++ compiler to compile the provided code. For example, you can use the following command:
    ```
    g++ -o parseTempsDriver parseTempsDriver.cpp
    ```
    ```
    make
    ```
-  This will use the `makefile` to compile the source code and generate the executable.

2.  Run the Program: Execute the compiled program with the input file name as a command-line argument. For example:
    ```
    ./parseTemps sample-input.txt
    ```

## Cleaning
-  To remove the compiled files and clean the project directory, you can use the following command:
    ```
    make clean
    ```

## Input File Format
-  Ensure that your input file follows the expected format, where each line contains space-separated temperature readings for each CPU core.

## Sample Input
    ```
    61.0 63.0 50.0 58.0
    80.0 81.0 68.0 77.0
    62.0 63.0 52.0 60.0
    83.0 82.0 70.0 79.0
    68.0 69.0 58.0 65.0
    ```

## Example Output
    ```
    sample-input.txt
    |----------------------------------------------------------|
				     Least Squares Approximation
    |----------------------------------------------------------|
    
    0 < x < 150; y= 67.4 + 0.0566667x; Least Squares Approximation
    
    |----------------------------------------------------------|
				     Piecewise Linear Interpolation
    |----------------------------------------------------------|
    
    0 < x < 30; y = 61 + 0.633333x; Linear Interpolation
    30 < x < 60; y = 98 - 0.6x; Linear Interpolation
    60 < x < 90; y = 20 + 0.7x; Linear Interpolation
    90 < x < 120; y = 128 - 0.5x; Linear Interpolation
    ```
