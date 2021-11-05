//
// Created by Robin on 2021-11-05.
//

#ifndef EMBEDDED_LAB_3_ROBIN_ELLINGSEN_BUTTON_H
#define EMBEDDED_LAB_3_ROBIN_ELLINGSEN_BUTTON_H

#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <stdbool.h>

void button_init();
void button_state();
void print_state();

#endif //EMBEDDED_LAB_3_ROBIN_ELLINGSEN_BUTTON_H
