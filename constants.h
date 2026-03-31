/*
    all constants I think
    change as needed
*/

#define BIG_R 140 // radii top circle 
#define SMALL_R 89.622 // radius base
#define TOP_HEIGHT 130 // heights are relative and must be changed over time
#define BOTTOM_HEIGHT 100
#define TOTAL_TIME 20000 // in seconds


TODO: reset the size
#define LEG1_SIZE 100
#define LEG2_SIZE 100
/*
    rotating numbers and stuff
    close enough to constants IMO
*/

double getCurrTime(double time, int leg) {
    if (t + leg*TOTAL_TIME <= TOTAL_TIME) {
        return time + leg*TOTAL_TIME/5;
    } else {
        return time + leg*TOTAL_TIME/5 - TOTAL_TIME;
    }
}

double height(double time, int leg) {
    if (time < TOTAL_TIME*4/5)
        return TOP_HEIGHT*1.0;
    else {
        return ((100*(TOP_HEIGHT - BOTTOM_HEIGHT) / pow(TOTAL_TIME, 2)) * pow((getCurrTime(time, leg) - (9/10)*TOTAL_TIME), 2) + BOTTOM_HEIGHT);
    }
}
