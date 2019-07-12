#include <Arduino.h>
#include <Wire.h>
#include "SparkFun_Tlc5940.h"
#include "queue.h"

#define I2C_ADDR 0x16

void setup()
{
    Serial.begin(9600);
    Wire.begin(I2C_ADDR);
    Tlc.init();
}

void loop()
{
    Tlc.set(0,4000);
    Tlc.set(1,4095);
    Tlc.update();
}

