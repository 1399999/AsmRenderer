/* This file contians the logic for AsmRenderer. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asm.h"

#define EMPTY ""

char ** bss;
char ** data;
char ** text;
char * code;

unsigned long bss_next = 0;
unsigned long data_next = 0;
unsigned long text_next = 0;

unsigned long bss_alloc = 0;
unsigned long data_alloc = 0;
unsigned long text_alloc = 0;

// Used to initialize a rendering process.

void render_init(void)
{
    bss = calloc(1, sizeof(char * ));
    data = calloc(1, sizeof(char * ));
    text = calloc(1, sizeof(char * ));

    text_add(".global _start");
    text_add("_start:");
}

// Adds the specified text to bss.

void bss_add(char * item)
{
    bss_alloc += strlen(item) + 2;

    bss = realloc(bss, bss_alloc);

    bss[bss_next++] = item;
}

// Adds the specified text to data.

void data_add(char * item)
{
    data_alloc += strlen(item) + 2;

    data = realloc(data, data_alloc);

    data[data_next++] = item;
}

// Adds the specified text to text.

void text_add(char * item)
{
    text_alloc += strlen(item) + 2;

    text = realloc(text, text_alloc);

    text[text_next++] = item;
}

// Combines BSS, DATA, and TEXT into the code variable.

void combine_code(void)
{
    code = calloc(bss_next + data_next + text_next, bss_alloc + data_alloc + text_alloc);

    strcpy(code, EMPTY);

    if (bss_next > 0) 
    {
        strcat(code, ".bss\n");

        for(int i = 0; i < bss_next; i++)
        {
            strcat(code, bss[i]);
            strcat(code, "\n");
        }
    }

    if (data_next > 0)
    {
        strcat(code, ".data\n");

        for(int i = 0; i < data_next; i++)
        {
            strcat(code, data[i]);
            strcat(code, "\n");
        }
    }

    if (text_next > 0) 
    {
        strcat(code, ".text\n");

        for(int i = 0; i < text_next; i++)
        {
            strcat(code, text[i]);
            strcat(code, "\n");
        }
    }
}

// Exports the code to the specified path.

void export_to(char * path)
{
	FILE * fp;
	fp = fopen(path, "w");

	fprintf(fp, code);

	fclose(fp);
}
