#ifndef DATATYPE_HEADER 
#define DATATYPE_HEADER

#define TOTAL_COMPONENTS    3

struct component_
{
    bool is_input;
    bool is_digital;
    byte port_no;
    char c_name[4];
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
