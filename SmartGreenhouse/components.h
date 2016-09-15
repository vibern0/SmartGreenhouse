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
    
#endif
