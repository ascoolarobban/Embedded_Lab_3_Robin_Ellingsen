#include <avr/io.h>
#include "timer.h"

void timer_init() {
    //timer0
    TCCR0A |= _BV(WGM01);
    TCCR0A |= _BV(WGM00);



    TCCR0B |= _BV(CS01);
    TCCR0B |= _BV(CS00);

    TCCR0A |= (1<<COM0A1);

    //timer 2
    TCCR2A |= (1<<WGM21);

    TCNT2 = 0;

    TCCR2B |= _BV(CS20);
    TCCR2B |= _BV(CS21);
    TCCR2B |= _BV(CS22);

    OCR2A = 155;

    TIMSK2 |= _BV(OCIE2A);
}

