//=====[#include guards - begin]===============================================
#ifndef _User_Interface_h_
#define _User_Interface_h_
//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================
extern bool toasterReady;
extern bool toasterOn;
extern bool alarm;
//=====[Declarations (prototypes) of public functions]=========================
void InputsInit();
void Food_In();
void Toast_On();
void Dark_Level();
static void userInterfaceDisplay();
//=====[#include guards - end]=================================================
#endif // _User_Interface_h_