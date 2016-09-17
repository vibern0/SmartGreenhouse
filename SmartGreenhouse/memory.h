#ifndef MEMORY_HEADER 
#define MEMORY_HEADER

#define MEMORY_VERSION            4

#define MEMORY_ADRESS_STATUS      0
#define MEMORY_ADRESS_COMPONENT   1

void save_data(struct components_ components)
{
    EEPROM.put(MEMORY_ADRESS_COMPONENT, components);
    if(EEPROM.read(MEMORY_ADRESS_STATUS) != MEMORY_VERSION)
    {
        EEPROM.write(MEMORY_ADRESS_STATUS, MEMORY_VERSION);
    }
    Serial.println("Components data saved!");
}
struct components_ load_data()
{
    struct components_ components;
    if(EEPROM.read(MEMORY_ADRESS_STATUS) == MEMORY_VERSION)
    {
        EEPROM.get(MEMORY_ADRESS_COMPONENT, components);
        EEPROM.write(MEMORY_ADRESS_STATUS, MEMORY_VERSION);
        Serial.println("Components data loaded!");
    }
    else
    {
        for(byte i = 0; i < TOTAL_COMPONENTS; i++)
        {
            components.comp[i].is_input = false;
            components.comp[i].is_digital = false;
            components.comp[i].port_no = 255;
            strcpy(components.comp[i].c_name, "");
            components.comp[i].status = false;
            components.comp[i].turn_on = 0;
            components.comp[i].turn_off = 0;
        }
    }
    return components;
}
    
#endif
