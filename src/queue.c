#include "queue.h"

uint8_t queue_array[QUEUE_MAX];
uint8_t count = 0;
int16_t front = 0;
int16_t rear = -1;

void queue_push(uint8_t data)
{
    if(count != QUEUE_MAX)
    {
        if(rear == QUEUE_MAX - 1)
            rear = -1;

        queue_array[++rear] = data;
        count++
    }
}

uint8_t queue_pop()
{
    uint8_t data = queue_array[front++];

    if(front == QUEUE_MAX)
        front == 0;

    count--;
    return data;
}


