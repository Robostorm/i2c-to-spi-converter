#ifndef TLC_H
#define TLC_H

#include <avr/io.h>
#include <avr/interrupt.h>

#define TLC_SCLK_PIN PB5
#define TLC_SCLK_PORT PORTB
#define TLC_SCLK_DDR DDRB

#define TLC_MOSI_PIN PB3
#define TLC_MOSI_PORT PORTB
#define TLC_MOSI_DDR DDRB

#define TLC_XLAT_PIN PB1
#define TLC_XLAT_PORT PORTB
#define TLC_XLAT_DDR DDRB

#define TLC_BLANK_PIN PB2
#define TLC_BLANK_PORT PORTB
#define TLC_BLANK_DDR DDRB

#define TLC_GSCLK_PIN PD3
#define TLC_GSCLK_PORT PORTD
#define TLC_GSCLK_DDR DDRD

#define TLC_XLAT_DUTY_FACTOR 1
#define TLC_BLANK_DUTY_FACTOR 2
#define TLC_TIMER1_PERIOD 8192
#define TLC_GSCLK_PERIOD 3
#define TLC_NUM_TRANSMISSION_BYTES 24

void tlc_init(void);
void tlc_send();
void tlc_shift(uint8_t byte);

#endif

