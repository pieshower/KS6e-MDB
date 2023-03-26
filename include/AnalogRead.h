#ifndef AnalogRead_h
#define AnalogRead_h

#include <avr/io.h>

class AnalogRead
{
public:

    AnalogRead() 
    {
        // Set the ADC reference voltage to AVCC
        ADMUX |= (1 << REFS0);
        // Enable the ADC and set the prescaler to 128
        ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
    }

    ~AnalogRead() {};

    int read(int pin)
    {
        // Set the ADC input channel
        ADMUX = (ADMUX & 0xF0) | (pin & 0x0F);

        // Start the ADC conversion
        ADCSRA |= (1 << ADSC);

        // Wait for the conversion to complete
        while (ADCSRA & (1 << ADSC));

        // Return the ADC value
        return ADC;
    }

};

#endif