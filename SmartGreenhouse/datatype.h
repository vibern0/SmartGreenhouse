#ifndef DATATYPE_HEADER 
#define DATATYPE_HEADER

#define TOTAL_COMPONENTS    3

struct component_
{
    bool status;
    byte turn_on;
    byte turn_off;
};
typedef component_ component;
struct components_
{
    component comp[TOTAL_COMPONENTS];    
};

#endif
