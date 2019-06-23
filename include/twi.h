#ifndef TWI_H
#define TWI_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

#define TWI_SLAVE_ADDR 0x16
#define TWI_SR_SLA_ACK 0x60
#define TWI_SR_DATA_ACK 0x80
#define TWI_SR_STOP 0xA0

void twi_init(void);
ISR(TWI_vect);

#endif

