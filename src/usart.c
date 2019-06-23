#include "usart.h"

//UART Serial - used only for debugging, may be removed later
void usart_init()
{
    //set baud; _VALUEs are from util/setbaud.h
    UBRR0H = UBRRH_VALUE;
    UBRR0L = UBRRL_VALUE;

#if USE_2X
    UCSR0A |= (1 << U2X0);
#else
    UCSR0A &= ~(1 << U2X0);
#endif

    //enable tx 
    UCSR0B |= (1 << TXEN0);

    //set frame: 8 bits, 1 stop bit
    UCSR0B &= ~(1 << UCSZ02);
    UCSR0C |= (1 << UCSZ01);
    UCSR0C |= (1 << UCSZ00);
}

/*
 * Pushes characters to the serial buffer for transmission.
 * After pushing a char, it waits for the char to leave the buffer (reg UDR0) by reading the UCSR0A flag before
 * sending the next one.
*/
void usart_putchar(char c, FILE *stream)
{
    if(c == '\n')
        usart_putchar('\r', stream);

    loop_until_bit_is_set(UCSR0A, UDRE0);
    UDR0 = c;
}

