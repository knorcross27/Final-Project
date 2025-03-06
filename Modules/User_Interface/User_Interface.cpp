//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "User_Interface.h"
#include "LCD.h"
#include <string>

//=====[Declaration of private defines]========================================
#define light 0.3
#define dark 0.7
//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalIn Button(D14);
DigitalIn Switch(D15);
AnalogIn Potentiometer(A1);


//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============
bool toasterReady = false;
bool toasterOn = false;
//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================
void InputsInIt() {
Button.mode(PullDown);
Switch.mode(PullDown);
}



void Food_In() {
if (Button) {
    toasterReady = true;
}
else {
    toasterReady = false;
}
}



void Toast_On() {
if (toasterReady == true ) {
    if (Switch) {
        toasterOn = true;
    }
    else {
        toasterOn = false;
    }
}
}


std::string Dark_Level() {   
if (toasterOn == true) {
    float levelselect = Potentiometer.read();
    if (levelselect < light) {
       return "light";
    }
    if ((levelselect > light) && (levelselect < dark)) {
        return "medium";
    }
    if (levelselect > dark) {
        return "dark";
    }
}
return "N/A";
}

static void userInterfaceDisplay() {
displayModeWrite(DISPLAY_MODE_CHAR);
displayClear();

displayCharPositionWrite ( 0,0 );
displayStringWrite( "Level:" );

displayCharPositionWrite ( 0,1 );
displayStringWrite( "Time:" );

displayCharPositionWrite ( 8,1 );
if (*****alarm==ON******){
    displayStringWrite("DANGER")
}

std::string toastLevel = Dark_Level();
displayCharPositionWrite ( 8,0 );
displayStringWrite(toastLevel);
}