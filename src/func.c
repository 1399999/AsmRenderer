#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asm.h"
#include "func.h"

unsigned int str_ary_len(char ** str_ary)
{
    unsigned int i = 0;

    for(; str_ary[i] != NULL; i++);

    return i;
}

void aalloc_ary(char ** str_ary, sections s, unsigned int amount)
{
    if (s == BSS)
        str_ary = malloc(bss_alloc + amount);

    else if(s == DATA)
        str_ary = malloc(data_alloc + amount);

    else
        str_ary = malloc(text_alloc + amount);
}
