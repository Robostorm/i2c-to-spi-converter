#ifndef USART_H
#define USART_H

#include <avr/io.h>
#include <stdio.h>

#define F_CPU 16000000UL
#define BAUD 9600
#include <util/setbaud.h>

void usart_init(void);
void usart_putchar(char c, FILE *stream);

#endif


