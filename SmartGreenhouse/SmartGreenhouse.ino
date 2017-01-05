#include <EEPROM.h>
#include "datatype.h"
#include "memory.h"
#include "time.h"
#include "components.h"
#include "input.h"

struct components_ components;

void setup()
{
    Serial.begin(9600);
    components = load_data();
    init_components(components);
}

//fix bug at cfg command
//reload components when change info

void loop()
{
    if(Serial.available() > 0)
    {
        components = check_input(components);
    }
    check_components(components);
    count_time();
}
