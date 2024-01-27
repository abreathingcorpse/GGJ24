#include <fstream> // for logging and debugging

// Define the functions
// Rounds up whenever a value is .5 or more, rounds down otherwise
int DivisionRounder (float numerator, float denominator) {
    // Adds 0.5, which rounds up if can be done. Then the casting to integer truncates any excess
    return (int)((numerator / denominator) + 0.5f);
}