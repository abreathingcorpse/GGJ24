// Define the functions
int DivisionRounder (float numerator, float denominator) {
    float divisionResidue = (int)numerator % (int)denominator;
    int roundUpFlag = (divisionResidue >= (denominator * .5f)) ? roundUpFlag = 1 : 0;

    if(roundUpFlag) {
        return ( ((int)numerator / (int)denominator) + 1 );
    } else {
        return ( (int)numerator / (int)denominator );
    }
}