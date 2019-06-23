#ifndef QUEUE_H
#define QUEUE_H

#define MAX 0xFF

void push(uint8_t data);
uint8_t pop(void);

extern uint8_t queue_array[];

#endif

