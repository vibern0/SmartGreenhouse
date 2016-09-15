#include <EEPROM.h>
#include "datatype.h"
#include "memory.h"


struct component_ component_1;



void setup()
{
    Serial.begin(9600);
    component_1 = loadData();
}

void loop()
{
    if(Serial.available() > 0)
    {
        char input[16];
        byte len = Serial.available();
        Serial.readBytes(input, 16);
        input[len] = '\0';
        
        if(!strcmp(input, "c1 on"))
        {
            byte order = 1;
            Serial.print("Time : ");
            component_1.turn_on = 0;
            while(Serial.available() == 0) { }
            while(Serial.available() > 0)
            {
                component_1.turn_on = component_1.turn_on * order + byte(Serial.read()) - 48;
                order *= 10;
            }
            Serial.println(component_1.turn_on);
            Serial.println("Turn on time changed!");
        }
        else if(!strcmp(input, "print"))
        {
            Serial.print("Stat : ");
            Serial.println(component_1.stat);
            Serial.print("Turn on : ");
            Serial.println(component_1.turn_on);
            Serial.print("Turn off : ");
            Serial.println(component_1.turn_off);
        }
        else if(!strcmp(input, "save"))
        {
            saveData(component_1);
        }
    }
}
