#ifndef MEMORY_HEADER 
#define MEMORY_HEADER

#define MEMORY_VERSION            1

#define MEMORY_ADRESS_STATUS      0
#define MEMORY_ADRESS_COMPONENT   1

void saveData(struct component_ component)
{
    EEPROM.put(MEMORY_ADRESS_COMPONENT, component);
    if(EEPROM.read(MEMORY_ADRESS_STATUS) != MEMORY_VERSION)
    {
        EEPROM.write(MEMORY_ADRESS_STATUS, MEMORY_VERSION);
    }
    Serial.println("Data saved!");
}
struct component_ loadData()
{
    struct component_ component;
    if(EEPROM.read(MEMORY_ADRESS_STATUS) == MEMORY_VERSION)
    {
        EEPROM.get(MEMORY_ADRESS_COMPONENT, component);
        EEPROM.write(MEMORY_ADRESS_STATUS, MEMORY_VERSION);
    }
    return component;
}
    
#endif
