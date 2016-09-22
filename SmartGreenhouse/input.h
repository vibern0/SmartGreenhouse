#ifndef INPUT_HEADER 
#define INPUT_HEADER

struct components_ check_input(struct components_ comps)
{
    char o_input[16];
    char input[7][4];
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
    if(!strcmp(input[0], "help"))
    {
        Serial.println("COMMANDS AREA:");
        Serial.println("- help");
        Serial.println("- print");
        Serial.println("- save");
        Serial.println("- c [component-id] [options]");
        Serial.println("OPTIONS:");
        Serial.println("input   [is-input]");
        Serial.println("digital [is-digital]");
        Serial.println("port    [port-no]");
        Serial.println("cname   [component-name]");
        Serial.println("status  [status]");
        Serial.println("min     [turn-min]");
        Serial.println("max     [turn-max]");
        Serial.println("cfg     [is-input] [is-digital] [port-no] [component-name] [status] [turn-min] [turn-max]");
    }
    else if(!strcmp(input[0], "c"))
    {
        byte component_id = byte(atoi(input[1]));
        if(!strcmp(input[2], "input"))
        {
            comps.comp[component_id] = changeIsInput(comps.comp[component_id], bool(atoi(input[3])));
            Serial.print("Is input in COMPONENT ");
            Serial.print(component_id);
            Serial.print(" changed to ");
            Serial.println(comps.comp[component_id].is_input);
        }
        else if(!strcmp(input[2], "digital"))
        {
            comps.comp[component_id] = changeIsDigital(comps.comp[component_id], bool(atoi(input[3])));
            Serial.print("Is digital in COMPONENT ");
            Serial.print(component_id);
            Serial.print(" changed to ");
            Serial.println(comps.comp[component_id].is_digital);
        }
        else if(!strcmp(input[2], "port"))
        {
            comps.comp[component_id] = changePortNo(comps.comp[component_id], byte(atoi(input[3])));
            Serial.print("Port no in COMPONENT ");
            Serial.print(component_id);
            Serial.print(" changed to ");
            Serial.println(comps.comp[component_id].port_no);
        }
        else if(!strcmp(input[2], "cname"))
        {
            comps.comp[component_id] = changeCName(comps.comp[component_id], input[3]);
            Serial.print("Component name in COMPONENT ");
            Serial.print(component_id);
            Serial.print(" changed to ");
            Serial.println(comps.comp[component_id].c_name);
        }
        else if(!strcmp(input[2], "status"))
        {
            comps.comp[component_id] = changeStatus(comps.comp[component_id], bool(atoi(input[3])));
            Serial.print("Status in COMPONENT ");
            Serial.print(component_id);
            Serial.print(" changed to ");
            Serial.println(comps.comp[component_id].status);
        }
        else if(!strcmp(input[2], "min"))
        {
            comps.comp[component_id] = changeTurnMin(comps.comp[component_id], byte(atoi(input[3])));
            Serial.print("Turn min in COMPONENT ");
            Serial.print(component_id);
            Serial.print(" changed to ");
            Serial.println(comps.comp[component_id].turn_min);
        }
        else if(!strcmp(input[2], "max"))
        {
            comps.comp[component_id] = changeTurnMax(comps.comp[component_id], byte(atoi(input[3])));
            Serial.print("Turn max in COMPONENT ");
            Serial.print(component_id);
            Serial.print(" changed to ");
            Serial.println(comps.comp[component_id].turn_max);
        }
        else if(!strcmp(input[2], "cfg"))
        {
            comps.comp[component_id] = changeConfig(comps.comp[component_id], bool(atoi(input[3])), bool(atoi(input[4])), byte(atoi(input[5])), input[6], bool(atoi(input[7])), byte(atoi(input[8])), byte(atoi(input[9])));
            Serial.print("Config in COMPONENT ");
            Serial.print(component_id);
            Serial.print(" changed to [ ");
            Serial.print(comps.comp[component_id].is_input);
            Serial.print(" | ");
            Serial.print(comps.comp[component_id].is_digital);
            Serial.print(" | ");
            Serial.print(comps.comp[component_id].port_no);
            Serial.print(" | ");
            Serial.print(comps.comp[component_id].c_name);
            Serial.print(" | ");
            Serial.print(comps.comp[component_id].status);
            Serial.print(" | ");
            Serial.print(comps.comp[component_id].turn_min);
            Serial.print(" | ");
            Serial.print(comps.comp[component_id].turn_max);
            Serial.println(" ]");
        }
    }
    else if(!strcmp(input[0], "print"))
    {
        for(byte i = 0; i < TOTAL_COMPONENTS; i++)
        {
            Serial.print("-- COMPONENT : ");
            Serial.println(i);
            Serial.print("Is Input : ");
            Serial.println(comps.comp[i].is_input);
            Serial.print("Is Digit : ");
            Serial.println(comps.comp[i].is_digital);
            Serial.print("Port No : ");
            Serial.println(comps.comp[i].port_no);
            Serial.print("Name : ");
            Serial.println(comps.comp[i].c_name);
            Serial.print("Stat : ");
            Serial.println(comps.comp[i].status);
            Serial.print("Turn on : ");
            Serial.println(comps.comp[i].turn_min);
            Serial.print("Turn off : ");
            Serial.println(comps.comp[i].turn_max);
            Serial.println();
        }
    }
    else if(!strcmp(input[0], "save"))
    {
        save_data(comps);
    }
    return comps;
}
    
#endif
