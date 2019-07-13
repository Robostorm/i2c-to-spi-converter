#include <Arduino.h>
#include <Wire.h>
#include "SparkFun_Tlc5940.h"
#include "queue.h"

#define I2C_ADDR 0x16

void i2c_receive_event(int num)
{
    while(1 < Wire.available())
    {
        char byte = Wire.read();
        //Serial.println(byte);
        queue_push(byte);
    }
    int x = Wire.read();
}

void setup()
{
    Serial.begin(9600);
    Tlc.init();
    Wire.begin(I2C_ADDR);
    Wire.onReceive(i2c_receive_event);
}

void loop()
{
    Serial.println(queue_count);
    if(queue_count >= 2)
    {
        //  byte 2    byte 1
        // 00000000 0000 0000
        //      value   | ch

        uint8_t byte1 = queue_pop();
        uint8_t byte2 = queue_pop();

        uint8_t channel = byte1 & 0x0F;
        uint16_t value = ((byte1 & 0xF0) >> 4) + (byte2 << 4);

        //Serial.println(channel);
        //Serial.println(value);

        Tlc.set(channel, value);
        Tlc.update();
    }
}

