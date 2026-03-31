/*
    all angles given CONSTANTS and functions that are almost const
    BIG_R, SMALL_R, TOP_HEIGHT, BOTTOM_HEIGHT, TOTAL_TIME, getCurrTime(double time, int leg), double height (double time, int leg)
*/

double angleDif = 4*2*M_PI / 5;
double angleDifGivenLeg(int leg) {
    return angleDif*leg;
}

double topAng(double time, int leg) { // angle the leg should be at for the top side; includes displacement from original pos
    if (getCurrTime(time, leg) <= 4 * TOTAL_TIME / 5) {
        return (angleDifGivenLeg(leg) - angleDif/2 + 5*angleDif / (4 * TOTAL_TIME));
    } else {
        return (angleDifGivenLeg(leg) - angleDif/2 - 5*angleDif / (4 * TOTAL_TIME));
    }
}

double legSlopeXY(int leg) { // slope from center to base of leg
    return -1/tan(angleDifGivenLeg(leg));
}

double legSlopeXYZ(double time, int leg) {
    return (topLegCoord(time, 1, leg) - bottomLegCoord(1, leg)) / ((topLegCoord(time, 0, leg) - bottomLegCoord(0, leg)));
}
