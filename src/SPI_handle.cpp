

#include "TempSensor.h"
#include "SPI_handle.h"


// ------------------------------------------------
// Initializes the SPI pins, mode, and CS

void init_SPI()
{

    SPI.begin();
    
    SPI.beginTransaction(SPISettings(9600, MSBFIRST, SPI_MODE0));

    pinMode(CHIPSELECT, OUTPUT);

}


// -------------------------------------------------
// Sends through SPI. Maybe this works?

void send_SPI(uint32_t id, uint8_t buf[])
{

    SPI_message_t msg;

    msg.id = id;

    // Load buffer with Temperature array 

    for (int i = 0; i < CHANNELS; i++)
    {

        msg.buf[i] = buf[i];

    }

    // enable CAN controller to recieve data

    digitalWrite(CHIPSELECT, HIGH);

    // transfer data

    for (int i = msg.len; i > 0; i--)
    {

        SPI.transfer(msg.buf[i - 1]);

    }

    for (int i = 0; i < msg.len; i++)
    {

        Serial.print("buffer ");
        Serial.print(i);
        Serial.print(": ");
        Serial.println(msg.buf[i]);

    }

    // transfer identity

    SPI.transfer(msg.len);
    SPI.transfer(msg.id);

    digitalWrite(CHIPSELECT, LOW);

}

