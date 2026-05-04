/*
    using esp32 with internal timer
    1000us-2000us -> 0 - 180deg
    credit to: https://github.com/madhephaestus/ESP32Servo/blob/master/examples/Multiple-Servo-Example-Arduino/Multiple-Servo-Example-Arduino.ino
*/
#include <ESP32Servo.h>
#include <angles.h>
// create four servo objects
#DEFINE ROWS = 5; // which leg?
#define COLUMNS = 3; // which motor?
Servo allMotors[5][3]; // does this work? idk otherwise name 15 seperate pins in array-like names

// Published values for SG90 servos; to be adjusted
int minUs = 1000;
int maxUs = 2000;
int timerWidth = 50;


// These are all GPIO pins on the ESP32
// Recommended pins include 2,4,12-19,21-23,25-27,32-33
// for the ESP32-S2 the GPIO pins are 1-21,26,33-42
// for the ESP32-S3 the GPIO pins are 1-21,35-45,47-48
// for the ESP32-C3 the GPIO pins are 1-10,18-21

FIXME: add pins for motors
int pinoutConfig[ROWS][COLUMNS] = {
    { , , ,},
    { , , ,},
    { , , ,},
    { , , ,},
    { , , ,},
};

#if !defined(CONFIG_IDF_TARGET_ESP32S2) && !defined(CONFIG_IDF_TARGET_ESP32S3)
    #error uh-oh! the board isn't an esp32-s2/esp32-s3;
#endif

int pos = 0;      // position in degrees
ESP32PWM pwm;








void setup() {
	// Allow allocation of all timers
	ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
	Serial.begin(115200);
    for (int i = 0; i < 5; i++) { // nested loop for getting all 15 motors ready
        for (int z = 0; z < 3; z++) {
            allMotors[i][z].setPeriodHertz(50); // once every 20us
        }
    }
    FIXME: to delete? should be same as above
	// servo1.setPeriodHertz(50);      // Standard 50hz servo
	// servo2.setPeriodHertz(50);      // Standard 50hz servo
	// servo3.setPeriodHertz(50);      // Standard 50hz servo
	// servo4.setPeriodHertz(50);      // Standard 50hz servo
	// xservo5.setPeriodHertz(50);      // Standard 50hz servo

    unsigned long myTime = millis(); // time to input into angles
    unsigned long timeDif;
}

void loop() {
    for (int i = 0; i < 5; i++) { // nested loop for getting all 15 motors ready
        for (int z = 0; z < 3; z++) {
            allMotors[i][z].attach(servo1Pin, minUs, maxUs);
        }
    }
#if defined(CONFIG_IDF_TARGET_ESP32S2) || defined(CONFIG_IDF_TARGET_ESP32C3)
	pwm.attachPin(37, 10000);//10khz
#elif defined(CONFIG_IDF_TARGET_ESP32C3)
	pwm.attachPin(7, 10000);//10khz
#else
	pwm.attachPin(27, 10000);//10khz
#endif
	servo3.attach(servo3Pin, minUs, maxUs);
	servo4.attach(servo4Pin, minUs, maxUs);

	//servo5.attach(servo5Pin, minUs, maxUs);
    todo: number thingys here from desmos
    for (int i = 0; i < 5; i++) {
        for (int z = 0; z < 3; z++) { 
        	for (pos = 0; pos <= 180; pos += 1) { // sweep from 0 degrees to 180 degrees
        		// in steps of 1 degree
        		servo1.write(pos);
        		delay(1);             // waits 20ms for the servo to reach the position
        	}
            
        	for (pos = 180; pos >= 0; pos -= 1) { // sweep from 180 degrees to 0 degrees
        		servo1.write(pos);
        		delay(1);
        	}
        }
    }
	servo1.detach();
	servo2.detach();;
	servo3.detach();
	servo4.detach();
	pwm.detachPin(27);

	delay(5000); // change to speed value at some poin

}