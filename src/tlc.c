#include "tlc.h"

volatile uint8_t tlc_need_xlat = 0; //keeps track of if xlat needs to be sent
uint8_t tlc_data[24]; //24 byte array for grayscale data

void tlc_init()
{
    //==I/O INIT==
    TLC_SCLK_DDR |= (1 << TLC_SCLK_PIN);
    TLC_MOSI_DDR |= (1 << TLC_MOSI_PIN);
    TLC_XLAT_DDR |= (1 << TLC_XLAT_PIN);
    TLC_BLANK_DDR |= (1 << TLC_BLANK_PIN);
    TLC_GSCLK_DDR |= (1 << TLC_GSCLK_PIN);

    TLC_SCLK_PORT &= ~(1 << TLC_SCLK_PIN); //ensure SCLK is 0
    TLC_BLANK_PORT |= (1 << TLC_BLANK_PIN); //make BLANK high before timer starts

    //==SPI INIT==
    SPCR |= (1 << SPE); //enable SPI
    SPCR |= (1 << MSTR); //SPI master mode
    SPSR |= (1 << SPI2x); //double speed

    //==TIMER1 INIT==
    //TIMER1 used for timing the XLAT and BLANK pulses
    
    //enable pwm output on BLANK pin (pwm on XLAT pin is disabled at init so we don't shift in random crap)
    TCCR1A |= (1 << COM1B1); 

    //set to phase/freq correct pwm mode with ICR1 as TOP
    TCCR1B |= (1 << WGM13);

    //set output compare registers to change duty cycles of XLAT and BLANK
    OCR1A = TLC_XLAT_DUTY_FACTOR;
    OCR1B = TLC_BLANK_DUTY_FACTOR;

    //set frequency of TIMER1
    ICR1 = TLC_TIMER1_PERIOD;

    //==TIMER2 INIT==
    //TIMER2 used for GSCLK timing
    
    //enable pwm output on GSCLK pin
    TCCR2A |= (1 << COM2B1);

    //set to fast pwm mode with OCR2A as TOP
    TCCR2B |= (1 << WGM22);

    OCR2B = 0; //very short pulse
    OCR2A = TLC_GSCLK_PERIOD;

    //==START TIMERS==
    //set to enabled, no prescale
    TCCR1B |= (1 << CS10);
    TCCR2B |= (1 << CS20);
}

void tlc_send()
{
}

void tlc_set(uint8_t channel, uint16_t value)
{
}

void tlc_shift(uint8_t byte)
{
}

ISR(TIMER1_OVF_vect)
{
}

