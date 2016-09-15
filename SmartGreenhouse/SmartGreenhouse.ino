#include <EEPROM.h>
#include "datatype.h"
#include "memory.h"
#include "components.h"
#include "input.h"

struct components_ components;

void setup()
{
    Serial.begin(9600);
    components = loadData();
}

void loop()
{
    if(Serial.available() > 0)
    {
        components = checkInput(components);
    }
}
