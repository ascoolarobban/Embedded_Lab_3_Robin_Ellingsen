//
// Created by Robin on 2021-11-05.
//

#include "button.h"

bool pushed= false;
bool released= false;
bool buttonInterrupted = false;
bool timerInterrupted = false;



void button_init(){
    DDRB |= (1<< PB0);
    PCICR |= (1<<PCIE0);
    PCMSK0 |= (1<<PCINT0);
}
ISR(PCINT0_vect){ //isr for interrupt
    buttonInterrupted = true;
}

ISR(TIMER0_COMPA_vect){ //isr for timer0 interrupt
    timerInterrupted = true;
}

void button_state(){
    if(buttonInterrupted){

        if (PINB & (1 << PB0)) {
            pushed = true;
        }
        else if(!(PINB & (1 << PB0))){
            released = true;
        }
        TCNT0 = 0;
        buttonInterrupted = false;

    }
}


void print_state(){
    if(timerInterrupted){
        if(pushed){
            if(PINB & _BV(PB0)){
                printf_P(PSTR("pushed\r\n"));
            }
            pushed = false;
        }else if(released){
            if(!(PINB & _BV(PB0))){
                printf_P(PSTR("released\r\n"));
            }
            released = false;
        }
    }
}