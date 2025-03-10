//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "Timer.h"
#include "User_Interface.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

Timer countdownTimer;
int timeRemaining = 0;

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

//intializes timer
void timerInit() {
countdownTimer.stop();
countdownTimer.reset();
timeRemaining = 0;
}

// defines timer values and starts timer based on toastLevel 
void timerStart() {
if (toastLevel == 1) {
    timeRemaining = 10;
}
if (toastLevel == 2) {
    timeRemaining = 20;
}
if (toastLevel == 3) {
    timeRemaining = 30;
}
else {
    timeRemaining = 0;
}

countdownTimer.start();
}

// updates timer every second
void timerUpdate() {
if (timeRemaining > 0 && countdownTimer.read() >= 1.0) {
    timeRemaining--;
    countdownTimer.reset();
}
}

// checks if the timer is done
bool isTimerDone() {
    return timeRemaining <= 0;
}

//returns remaining time
int getTimeRemaining() {
    return timeRemaining;
}