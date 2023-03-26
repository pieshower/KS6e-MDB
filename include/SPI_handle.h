

#ifndef SPI_HANDLE_H
#define SPI_HANDLE_H


#include <Arduino.h>
#include <SPI.h>


#define CHIPSELECT 9


typedef struct SPI_message_t
{

    uint32_t id = 0;

    uint8_t len = 8;

    uint8_t buf[8] = { 0 };


} SPI_message_t;


void init_SPI();

void send_SPI(uint32_t id, uint8_t buf[]);


#endif