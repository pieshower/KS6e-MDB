

#include "TempSensor.h"
#include "MDB_Labels.h"
#include "AnalogRead.h"


// ------------------------------------------------
// Input pins for the NANO

//                 A   B   C   D
int tempPins[] = {18, 19, 20, 21};


// ---------------------------------------------------
// Input pins for the uno

// int tempPins[] = {PC0, PC1, PC2, PC3};


// -----------------------------------------------------
// Object and Type creation

temperature tempSenor;

AnalogRead data;


// ------------------------------------------------
// Updates the temps from each pins into an array

void TempSensor::updateTemp()
{

    for (int i = 0; i < CHANNELS; i++)
    {

        tempSenor.temp[i] = data.read(tempPins[i]);

    }

}


// ----------------------------------------------------
// Returns the temperture of a channel (A B C D)

uint8_t TempSensor::getTemp(int channel)
{

    return tempSenor.temp[channel];

}


// ------------------------------------------------------
// Averages all channels into one temperature reading

void TempSensor::AvgTemp()
{

    uint8_t minTemp[CHANNELS] = { 0 };
    uint8_t maxTemp[CHANNELS] = { 0 };

    for (int i = 0; i < CHANNELS; i++)
    {

        minTemp[i] = this->getTemp(i); 

    }

    this->updateTemp();

    for (int i = 0; i < CHANNELS; i++)
    {

        maxTemp[i] = this->getTemp(i);

    }

    for (int i = 0; i < CHANNELS; i++)
    {

        tempSenor.avgTemp[i] = (minTemp[i] + maxTemp[i]) / 2;

    }

}


// ------------------------------------------------------
// Returns an array of average temperatures

uint8_t *TempSensor::getAvgTemp()
{

    return tempSenor.avgTemp;

}

