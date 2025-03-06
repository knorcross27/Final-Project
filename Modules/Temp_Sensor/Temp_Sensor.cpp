//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "Temp_Sensor.h"
#include "Toaster_Alert_System.h"

//=====[Declaration of private defines]========================================

#define Temp_Sensor_NUMBER_OF_AVG_SAMPLES    10

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

AnalogIn Temp_Sensor(A0);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

float TempC = 0.0;
float TempSensorReadingsArray[Temp_Sensor_NUMBER_OF_AVG_SAMPLES];

//=====[Declarations (prototypes) of private functions]========================

static float analogReadingScaledWithTheLM35Formula( float analogReading );

//=====[Implementations of public functions]===================================

void tempSensorInit()
{
    int i;
    
    for( i=0; i<Temp_Sensor_NUMBER_OF_AVG_SAMPLES ; i++ ) {
        TempSensorReadingsArray[i] = 0;
    }
}

void temperatureSensorUpdate()
{
    static int TempSensorSampleIndex = 0;
    float TempSensorReadingsSum = 0.0;
    float TempSensorReadingsAverage = 0.0;

    int i = 0;

    TempSensorReadingsArray[TempSensorSampleIndex] = Temp_Sensor.read();
       TempSensorSampleIndex++;
    if ( TempSensorSampleIndex >= Temp_Sensor_NUMBER_OF_AVG_SAMPLES) {
        TempSensorSampleIndex = 0;
    }
    
   TempSensorReadingsSum = 0.0;
    for (i = 0; i < Temp_Sensor_NUMBER_OF_AVG_SAMPLES; i++) {
        TempSensorReadingsSum = TempSensorReadingsSum + TempSensorReadingsArray[i];
    }
    TempSensorReadingsAverage = TempSensorReadingsSum / Temp_Sensor_NUMBER_OF_AVG_SAMPLES;
       TempC = analogReadingScaledWithTheLM35Formula ( TempSensorReadingsAverage );    
}

float temperatureSensorReadCelsius()
{
    return TempC;
}

float celsiusToFahrenheit( float tempInCelsiusDegrees )
{
    return ( tempInCelsiusDegrees * 9.0 / 5.0 + 32.0 );
}

float temperatureSensorReadFahrenheit()
{
    return celsiusToFahrenheit( TempC );
}

//=====[Implementations of private functions]==================================

static float analogReadingScaledWithTheLM35Formula( float analogReading )
{
    return ( analogReading * 3.3 / 0.01 );
}