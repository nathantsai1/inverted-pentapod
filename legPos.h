#include <constants.h>

double baseLegCoord(int coord, int leg) {
    // coord num mapping
    // 1 = x
    if (coord == 0) { // 1 = x
        return SMALL_R*cos(angleDifGivenLeg(leg));
    } else if (coord == 1) { // 2 = y
        return SMALL_R*sin(angleDifGivenLeg(leg));
    } else { // z
        return 0;
    }
}

double topLegCoord(double time, int coord, int leg) {
    // same coord num mapping as top
    if (coord == 0) { // 1 = x
        return BIG_R*cos(topAng(time, leg));
    } else if (coord == 1) { // 2 = y
        return BIG_R*sin(topAng(time, leg));
    } else { // z
        return height(time, leg);
    }
}