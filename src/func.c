#include <string.h>
#include "func.h"

void str_add_ch(char * str, char item) 
{
    strncat(str, &item, 1); 
}

void str_add_str(char * str, char * str2) 
{
    strcat(str, str2); 
}