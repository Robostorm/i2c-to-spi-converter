#ifndef TWI_H
#define TWI_h

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

#define TWI_SLAVE_ADDR 0x16 //doesn't really matter
#define TWI_SR_SLA_ACK 0x60
#define TWI_SR_DATA_ACK 0x80
#define TWI_SR_STOP 0xA0

void TWI_init();
uint8_t TWI_get_data();
ISR(TWI_vect);

#define 

#endif
