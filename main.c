#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>


#include "led.h"
#include "serial.h"
#include "timer.h"
#include "button.h"
#include "adc.h"

volatile uint8_t adcValue = 0;

int main (void) {

	LED_init();
	uart_init();
	timer_init();
    button_init();
    adc_init();
    sei();

	while (1) {
	}
	return 0;
}
ISR(ADC_vect){
    adcValue = ADCH;
}
ISR(TIMER2_COMPA_vect){
    ADCSRA |= (1<<ADSC);
    OCR0A = adcValue;
}


