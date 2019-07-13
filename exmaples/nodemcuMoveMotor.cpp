#include <Arduino.h>
#include <Wire.h>

#define ATMEGA_I2C_ADDR 0x16

void setup()
{
    //Serial.begin(9600);
    Wire.begin();
}

void tlc_send(uint8_t channel, uint16_t value)
{
    uint8_t byte1 = channel + ((value & 0x000F) << 4);
    uint8_t byte2 = (value & 0x0FF0) >> 4;

    Wire.beginTransmission(ATMEGA_I2C_ADDR);
    Wire.write(byte1);
    Wire.write(byte2);
    Wire.write("\n");
    Wire.endTransmission();
}

void loop()
{
    //make motor spin at about half speed in opposite direction
    tlc_send(0, 0);
    tlc_send(1, 2000);
    delay(10); //this delay is important; data will corrupt if it isn't here
}

