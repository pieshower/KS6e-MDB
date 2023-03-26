

#include "TempSensor.h"
#include "SPI_handle.h"
// #include "MDB_Labels.h"



void init_SPI()
{

    SPI.begin();
    SPI.beginTransaction(SPISettings(9600, MSBFIRST, SPI_MODE0));

    pinMode(CHIPSELECT, OUTPUT);

}


void send_SPI(uint32_t id, uint8_t buf[])
{

    SPI_message_t msg;

    msg.id = id;


    for (int i = 0; i < msg.len; i++)
    {

        msg.buf[i] = buf[i];

    }

    digitalWrite(CHIPSELECT, HIGH);

    for (int i = msg.len; i > 0; i--)
    {

        SPI.transfer(msg.buf[i - 1]);

    }

    SPI.transfer(msg.len);
    SPI.transfer(msg.id);

    digitalWrite(CHIPSELECT, LOW);

}

