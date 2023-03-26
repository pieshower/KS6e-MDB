

#include <Arduino.h>
#include "TempSensor.h"
#include "SPI_handle.h"
#include "MDB_Labels.h"


TempSensor batteryTemp;


int main(void)
{

    Serial.begin(9600);

    init_SPI();

    while(true)
    {

        batteryTemp.updateTemp();
        batteryTemp.AvgTemp();

        send_SPI(0xFAFAFBF, batteryTemp.getAvgTemp());

    }

}



