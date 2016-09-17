#ifndef TIME_HEADER 
#define TIME_HEADER

byte time_header_val = 0;

void count_time()
{
    static long last_millis = 0;
    if(millis() - last_millis > 1000)
    {
        last_millis = millis();
        time_header_val ++;
        if(time_header_val > 59)
        {
            time_header_val = 0;
        }
    }
}

byte get_time()
{
    return time_header_val;
}
    
#endif
