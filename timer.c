#include <avr/io.h>
#include "timer.h"

void timer_init() {

    TCCR0A |= _BV(WGM01);


    TCCR0B |= _BV(CS02);
    TCCR0B |= _BV(CS00);

    OCR0A = 155;

    TIMSK0 |= _BV(OCIE0A); //The corresponding interrupt is executed if a compare match in Timer/Counter0 occurs
}

