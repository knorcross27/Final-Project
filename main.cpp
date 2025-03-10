//=====[Libraries]=============================================================

#include "Toaster_Alert_System.h"
//=====[Main function, the program entry point after power on or reset]========

int main()
{
    toasterAlertSystemInit();
    while (true) {
        toasterAlertSystemUpdate();
    }
}