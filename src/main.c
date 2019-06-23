#include "main.h"
#include "queue.h"
#include "twi.h"

int main()
{
    usart_init();
    twi_init();

    //set LED as output
    DDRC |= (1 << PC0);

    //setup serial output as stream and direct to stdout, has to be in main method for some reason
    FILE usart_output = FDEV_SETUP_STREAM(usart_putchar, NULL, _FDEV_SETUP_WRITE);
    stdout = &usart_output;

    sei();

    while(1){}
    return 0;
}

