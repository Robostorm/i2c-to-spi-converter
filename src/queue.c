#include "queue.h"

uint8_t queue_array[QUEUE_MAX];
uint8_t count = 0;
int16_t front = 0;
int16_t rear = -1;

uint8_t queue_is_full()
{
    if(count == QUEUE_MAX)
        return 1;
    else
        return 0;
}

void queue_push(uint8_t data)
{
    if(count != QUEUE_MAX)
    {
        if(rear == MAX - 1)
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


