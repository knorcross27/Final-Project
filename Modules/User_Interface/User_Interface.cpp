//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "User_Interface.h"
#include "LCD.h"

//=====[Declaration of private defines]========================================

// defines potentiometer levels
#define light 0.3
#define dark 0.7
//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============


DigitalIn Button(D14);
DigitalIn Switch(D15);
AnalogIn Potentiometer(A1);

DigitalOut Green_LED(D13);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============
bool toasterReady = false;
bool toasterOn = false;
int toastLevel = 0;
//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

// button configurations and initializations 
void InputsInIt() {
Button.mode(PullDown);
Switch.mode(PullDown);
Green_LED = OFF;
}

// determines if food is in toaster
void Food_In() {
if (Button) {
    toasterReady = true;
    Green_LED = ON;
}
else {
    toasterReady = false;
}
}

// determines if toaster is on
void Toast_On() {
if (toasterReady == true ) {
    if (Switch) {
        toasterOn = true;
        Green_LED = OFF:
    
    }
    else {
        toasterOn = false;
    }
}
}

// determines desired darkness level of toast 
// corresponds with timer
void Dark_Level() {   
if (toasterOn == true) {
    float levelselect = Potentiometer.read();
    if (levelselect < light) {
       toastLevel = 1;
    }
    if ((levelselect > light) && (levelselect < dark)) {
        toastLevel = 2;
    }
    if (levelselect > dark) {
        toastLevel = 3;
    }
    else {
        toastLevel = 0;
    }
}
}

//updates interface based on inputs
//updates display 
void user_InterfaceUpdate() {
Food_In();
Toast_On();
Dark_Level();

displayModeWrite(DISPLAY_MODE_CHAR);
displayClear();

displayCharPositionWrite ( 0,0 );
displayStringWrite( "Level:" );

displayCharPositionWrite ( 0,1 );
displayStringWrite( "Time:" );

if (alarmState(true)){
    displayCharPositionWrite ( 8,1 );
    displayStringWrite( "DANGER" );
}
else {
    displayCharPositionWrite ( 8,1 );
    displayStringWrite( "SAFE" );
}

 std::string levelString = getToastLevelString();
    displayCharPositionWrite(8, 0);
    displayStringWrite(levelString.c_str());
}






