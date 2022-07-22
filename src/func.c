/* Ths file is used for helpful functions. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asm.h"
#include "func.h"

// Gets the length of a string array (char **).

unsigned int str_ary_len(char ** str_ary)
{
    unsigned int i = 0;

    for(; str_ary[i] != NULL; i++);

    return i;
}

// Reallocates memory for the specified string array.

void realloc_ary(char ** str_ary, sections s, unsigned int amount)
{
    if (s == BSS)
        str_ary = malloc(bss_alloc + amount);

    else if(s == DATA)
        str_ary = malloc(data_alloc + amount);

    else
        str_ary = malloc(text_alloc + amount);
}
