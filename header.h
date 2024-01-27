#include <fstream> // for logging and debugging

// Define the functions

// Logs whenever it finds a small position when drawing the nodes
void logger(Vector2 nodePositionsArray, int i) {
    std::ofstream log;
    log.open ("log.txt", std::ios_base::app);
    log << "index: " << i << "\n";
    log << "vector: (" << nodePositionsArray.x << "," << nodePositionsArray.y << ")\n";
    log.close();
}

// Rounds up whenever a value is .5 or more, rounds down otherwise
int DivisionRounder (float numerator, float denominator) {
    float divisionResidue = (int)numerator % (int)denominator;
    int roundUpFlag = (divisionResidue >= (denominator * .5f)) ? roundUpFlag = 1 : 0;

    if(roundUpFlag) {
        return ( ((int)numerator / (int)denominator) + 1 );
    } else {
        return ( (int)numerator / (int)denominator );
    }
}