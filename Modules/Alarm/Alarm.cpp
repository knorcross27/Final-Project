//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "Temp_Sensor.h"
#include "Gas_Sensor.h"
#include "User_Interface.h"


//=====[Declaration of private defines]========================================

//defines heat threshold of 100 celcius
#define HEAT_LEVEL 100 

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalOut Buzzer(PE_10); 
DigitalOut Red_LED(D12); 

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

bool gasDetected = false;

//=====[Declarations (prototypes) of private functions]========================

void alarmState(bool state);

//=====[Implementations of public functions]===================================

//initializes alarm system outputs
void alarmSystemInit() {
Red_LED = OFF;
Buzzer = ON;
}

//controls alarm state based on sensor readings
void alarmUpdate() {
float tempReading = temperatureSensorReadCelsius();
gasDetected = gasSensorRead();

if (tempReading > HEAT_LEVEL) {
    alarmState(true);
}
if (gasDetected) {
    alarmState(true);
}
else {
    alarmState(false);
}
}

// determines outputs if sensor is on
void alarmState(bool state) {
    if (state) {
        Buzzer = OFF;
        Red_LED = ON;
    }
}