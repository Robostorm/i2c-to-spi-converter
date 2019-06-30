#include "twi.h"
#include "queue.h"

void twi_init()
{
    //set address register shifted left 1 because the address is the highest 7 bits of TWAR
    TWAR = (TWI_SLAVE_ADDR << 1);

    //enable interrupt, enable TWI, send ACK, and clear TWINT
    TWCR |= (1 << TWIE) | (1 << TWEN) | (1 << TWEA) | (1 << TWINT);
}

//runs right after whenever TWI does something
ISR(TWI_vect)
{
    //got the slave address and receive bit
    if((TWSR & 0xF8) == TWI_SR_SLA_ACK)
    {
        //re-enable interrupt, re-enable TWI, send ACK, and clear TWINT
        TWCR |= (1 << TWIE) | (1 << TWEN) | (1 << TWEA) | (1 << TWINT);
    }
    //got data
    else if((TWSR & 0xF8) == TWI_SR_DATA_ACK)
    {
        queue_push(TWDR);

        //re-enable interrupt, re-enable TWI, send ACK, and clear TWINT
        TWCR |= (1 << TWIE) | (1 << TWEN) | (1 << TWEA) | (1 << TWINT);
    }
    //got stop condition
    else if((TWSR & 0xF8) == TWI_SR_STOP)
    {
        //re-enable interrupt, set it to respond to future addressings, and clear TWINT
        TWCR |= (1 << TWIE) | (1 << TWEA) | (1 << TWINT);
    }
}

