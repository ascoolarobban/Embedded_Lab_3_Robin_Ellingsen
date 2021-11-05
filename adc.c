//
// Created by Robin on 2021-11-05.
//

#include "adc.h"


 void adc_init(void) {

    DDRC &= ~(1<<PC0);
    /* By setting the ADLAR bit in the ADMUX register,
     * we can left align the ADC value.
     * This puts the highest 8 bits of the measurement in the ADCH register,
     * with the rest in the ADCL register. If we then read the ADCH register,
     * we get an 8 bit value that represents our 0 to 5 volt measurement as a number from 0 to 255.
     * We're basically turning our 10 bit ADC measurement into an 8 bit one.
     */
    ADMUX |= (1 << ADLAR) | (1 << REFS0);
    /*
    Set ADEN bit in ADCSRA to enable ADC
    Set ADIE bit in ADCSRA to enable ADC interrupt
    */
    ADCSRA |= (1 << ADPS0) | (1 << ADPS1);
    ADCSRA |= (1 << ADEN) | (1 << ADIE);
}