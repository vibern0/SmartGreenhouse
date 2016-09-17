#ifndef COMPONENTS_HEADER 
#define COMPONENTS_HEADER

component changeStatus(component comp, bool s)
{
    comp.status = s;
    return comp;
}

component changeTurnOn(component comp, byte h)
{
    comp.turn_on = h;
    return comp;
}

component changeTurnOff(component comp, byte h)
{
    comp.turn_off = h;
    return comp;
}

component changeConfig(component comp, bool i, bool d, byte p, char n[4])
{
    comp.is_input = i;
    comp.is_digital = d;
    comp.port_no = p;
    strcpy(comp.c_name, n);
    return comp;
}

void init_components(struct components_ comps)
{
    for(byte c = 0; c < TOTAL_COMPONENTS; c++)
    {
        pinMode(comps.comp[c].port_no, ((comps.comp[c].is_input) ? (INPUT) : (OUTPUT)));
    }
}

int read_component(component comp)
{
    if(!comp.is_input)
        return 0;
        
    if(comp.is_digital)
    {
        return ((digitalRead(comp.port_no) == HIGH) ? (1) : (0));
    }
    else
    {
        return analogRead(comp.port_no);
    }
}

void write_component(component comp, byte w)
{
    if(comp.is_input)
        return;

    if(comp.is_digital)
    {
        digitalWrite(comp.port_no, ((w == 1) ? (HIGH) : (LOW)));
    }
    else
    {
        analogWrite(comp.port_no, w);
    }
}

void check_components(struct components_ comps)
{
    //this here is completly dynamic.
    //need to check every component individually
    
    int read_pot = read_component(comps.comp[2]);
    byte t_time = get_time();
    if(read_pot > comps.comp[0].turn_on && read_pot < comps.comp[0].turn_off)
    {
        write_component(comps.comp[0], 1);
    }
    else
    {
        write_component(comps.comp[0], 0);
    }

    if(t_time > comps.comp[1].turn_on && t_time < comps.comp[1].turn_off)
    {
        write_component(comps.comp[1], 1);
    }
    else
    {
        write_component(comps.comp[1], 0);
    }
}
    
#endif
