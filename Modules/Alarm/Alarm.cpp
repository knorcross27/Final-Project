//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "Temp_Sensor.h"
#include "Gas_Sensor.h"
#include "User_Interface.h"

//=====[Declaration of private defines]========================================
#define heat_level 100 
//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============
DigitalOut Buzzer(PE_10);
DigitalOut Red_LED(D12);
DigitalOut Green_LED(D13);
//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============
bool gasDetected = false;
bool fireDetected = false;
//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void alarmSystemInit() {
Red_LED = OFF;
Green_LED = OFF;
Buzzer = ON;
}

void checkGasTemp() {
    tempReading = temperatureSensorReadCelsius()
    if ( tempReading > heat_level) {
        alarmState(true);
    }

}