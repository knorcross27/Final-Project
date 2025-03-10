//=====[#include guards - begin]===============================================

#ifndef _Timer_h_
#define _Timer_h_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================
void timerInit();
void startTimer(int toastLevel);
void timerUpdate();
bool isTimerDone();
int getTimeRemaining();
//=====[#include guards - end]=================================================

#endif // _Timer_h_