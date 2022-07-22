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

// Used to initialize a rendering process.

void render_init(unsigned int bss_len, unsigned int data_len)
{
    bss = calloc(sizeof(char * ), bss_len);
    data = calloc(sizeof(char * ), data_len);
    text = calloc(sizeof(char * ), 0);

    text_add(".global _start");
    text_add("_start:");
}

// Adds text to bss.

void bss_add(char * item)
{
    realloc_ary(bss, BSS, strlen(item));

    bss[bss_next++] = item;
}

// Adds text to data.

void data_add(char * item)
{
    realloc_ary(bss, BSS, strlen(item));

    data[data_next++] = item;
}

// Adds text to text.

void text_add(char * item)
{
    realloc_ary(bss, BSS, strlen(item));

    text[text_next++] = item;
}

// Combines BSS, DATA, and TEXT into the code variable.

void combine_code(void)
{
    code = malloc((sizeof(char * ) * sizeof(bss)) + (sizeof(char * ) * sizeof(data)) + (sizeof(char * ) * sizeof(text)));

    strcpy(code, EMPTY);

    if (str_ary_len(bss) > 0)
    {
        strcat(code, ".bss\n");

        for(int i = 0; i < str_ary_len(bss); i++)
        {
            strcat(code, bss[i]);
            strcat(code, "\n");
        }
    }

    if (str_ary_len(data) > 0)
    {
        strcat(code, ".data\n");

        for(int i = 0; i < str_ary_len(data); i++)
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
