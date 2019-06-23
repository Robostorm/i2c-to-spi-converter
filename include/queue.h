#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_MAX 0xFF

uint8_t queue_is_full(void);
void queue_push(uint8_t data);
uint8_t queue_pop(void);

extern uint8_t queue_array[];

#endif

