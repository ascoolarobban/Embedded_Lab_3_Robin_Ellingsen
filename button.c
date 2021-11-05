//
// Created by Robin on 2021-11-05.
//

#include "button.h"

void button_init(){
    DDRB |= (1<< PB0);
    PCICR |= (1<<PCIE0);
    PCMSK0 |= (1<<PCINT0);
}
