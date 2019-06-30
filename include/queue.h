#ifndef QUEUE_H
#define QUEUE_H

#include <avr/io.h>

#define QUEUE_MAX 0xFF

void queue_push(uint8_t data);
uint8_t queue_pop(void);

extern uint8_t queue_array[];
extern uint8_t queue_count;

#endif

