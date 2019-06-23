#include "queue.h"

uint8_t queue_array[MAX];
uint8_t count = 0;
int16_t front = 0;
int16_t rear = -1;

uint8_t is_full()
{
    if(count == MAX)
        return 1;
    else
        return 0;
}

void push(uint8_t data)
{
    if(is_full == 0)
    {
        if(rear == MAX - 1)
            rear = -1;

        queue_array[++rear] = data;
        count++
    }
}

uint8_t pop()
{
    uint8_t data = queue_array[front++];

    if(front == MAX)
        front == 0;

    count--;
    return data;
}


