#include "main.h"
#include "queue.h"
#include "usart.h"
#include "twi.h"
#include "tlc.h"

int main()
{
    usart_init();
    twi_init();
    tlc_init();

    //set LED as output
    DDRC |= (1 << PC0);

    //setup serial output as stream and direct to stdout, has to be in main method for some reason
    FILE usart_output = FDEV_SETUP_STREAM(usart_putchar, NULL, _FDEV_SETUP_WRITE);
    stdout = &usart_output;

    sei();

    while(1)
    {
        if(queue_count >= TLC_NUM_TRANSMISSION_BYTES)
            tlc_send();
    }

    return 0;
}


