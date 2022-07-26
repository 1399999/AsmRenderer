/* This file contians the logic for AsmRenderer. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asm.h"
#include "func.h"

#define EMPTY ""

char ** bss;
char ** data;
char ** text;
char * code;

unsigned int bss_next = 0;
unsigned int data_next = 0;
unsigned int text_next = 0;

unsigned int bss_alloc = 0;
unsigned int data_alloc = 0;
unsigned int text_alloc = 0;

void render_init(void)
{
    bss = calloc(1, sizeof(char * ));
    data = calloc(1, sizeof(char * ));
    text = calloc(1, sizeof(char * ));

    text_add(".global _start");
    text_add("_start:");
}

void bss_add(char * item)
{
    bss_alloc += strlen(item) + 2;

    bss = realloc(bss, bss_alloc);

    bss[bss_next++] = item;
}

void data_add(char * item)
{
    data_alloc += strlen(item) + 2;

    data = realloc(data, data_alloc);

    data[data_next++] = item;
}

void text_add(char * item)
{
    text_alloc += strlen(item) + 2;

    text = realloc(text, text_alloc);

    text[text_next++] = item;
}

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

void export_to(char * path)
{
	FILE * fp;
	fp = fopen(path, "w");

	fprintf(fp, code);

	fclose(fp);
}
