#ifndef INPUT_HEADER 
#define INPUT_HEADER

struct components_ checkInput(struct components_ comps)
{
    char o_input[16];
    char input[4][4];
    byte order = 0;
    char *token;
    byte len;
    
    len = Serial.available();
    Serial.readBytes(o_input, 16);
    o_input[len] = '\0';

    token = strtok(o_input, " ");
    while( token != NULL ) 
    {
        strcpy(input[order], token);
        token = strtok(NULL, " ");
        order ++;
    }
    if(!strcmp(input[0], "c"))
    {
        byte component_id = byte(atoi(input[1]));
        if(!strcmp(input[2], "status"))
        {
            comps.comp[component_id] = changeStatus(comps.comp[component_id], bool(atoi(input[3])));
            Serial.print("Status in COMPONENT 1 changed to ");
            Serial.println(comps.comp[component_id].turn_on);
        }
        else if(!strcmp(input[2], "on"))
        {
            comps.comp[component_id] = changeTurnOn(comps.comp[component_id], byte(atoi(input[3])));
            Serial.print("Turn on in COMPONENT 1 changed to ");
            Serial.println(comps.comp[component_id].turn_on);
        }
        else if(!strcmp(input[2], "off"))
        {
            comps.comp[component_id] = changeTurnOff(comps.comp[component_id], byte(atoi(input[3])));
            Serial.print("Turn off in COMPONENT 1 changed to ");
            Serial.println(comps.comp[component_id].turn_on);
        }
    }
    else if(!strcmp(input[0], "print"))
    {
        for(byte i = 0; i < TOTAL_COMPONENTS; i++)
        {
            Serial.print("-- COMPONENT : ");
            Serial.println(i);
            Serial.print("Stat : ");
            Serial.println(comps.comp[i].status);
            Serial.print("Turn on : ");
            Serial.println(comps.comp[i].turn_on);
            Serial.print("Turn off : ");
            Serial.println(comps.comp[i].turn_off);
            Serial.println();
        }
    }
    else if(!strcmp(input[0], "save"))
    {
        saveData(comps);
    }
    return comps;
}
    
#endif
