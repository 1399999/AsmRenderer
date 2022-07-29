#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "asm.h"

#define EMPTY ""

char * output;

unsigned short gnu_e = 0;

gnu_t gnu_i;
masm_t masm_i;

void render_init(asm_enum asm_e)
{
    if (asm_e == GNU)
    {
        gnu_e = 1;

        gnu_i.bss = calloc(1, sizeof(char * ));
        gnu_i.data = calloc(1, sizeof(char * ));
        gnu_i.text = calloc(1, sizeof(char * ));

        text_add(".global _start");
        text_add("_start:");
    }
    
    else
    {
        masm_i.code = calloc(1, sizeof(char * ));
        masm_i.data = calloc(1, sizeof(char * ));
        masm_i.dataq = calloc(1, sizeof(char * ));
        masm_i.stack = calloc(1, sizeof(char * ));

        code_add("Start PROC");
    }
}

void bss_add(char * item)
{
    if (gnu_e)
    {
        gnu_i.bss_alloc += strlen(item) + 2;
        gnu_i.bss = realloc(gnu_i.bss, gnu_i.bss_alloc);
        gnu_i.bss[gnu_i.bss_next++] = item;
    }
}

void code_add(char * item)
{
    if (!gnu_e)
    {
        masm_i.code_alloc += strlen(item) + 2;
        masm_i.code = realloc(masm_i.code, masm_i.code_alloc);
        masm_i.code[masm_i.code_next++] = item;
    }
}

void data_add(char * item)
{
    if (gnu_e)
    {
        gnu_i.data_alloc += strlen(item) + 2;
        gnu_i.data = realloc(gnu_i.data, gnu_i.data_alloc);
        gnu_i.data[gnu_i.data_next++] = item;
    }
    
    else
    {
        masm_i.data_alloc += strlen(item) + 2;
        masm_i.data = realloc(masm_i.data, masm_i.data_alloc);
        masm_i.data[masm_i.data_next++] = item;
    }
}

void dataq_add(char * item)
{
    if (!gnu_e)
    {
        masm_i.dataq_alloc += strlen(item) + 2;
        masm_i.dataq = realloc(masm_i.dataq, masm_i.dataq_alloc);
        masm_i.dataq[masm_i.dataq_next++] = item;
    }
}

void text_add(char * item)
{
    if (gnu_e)
    {
        gnu_i.text_alloc += strlen(item) + 2;
        gnu_i.text = realloc(gnu_i.text, gnu_i.text_alloc);
        gnu_i.text[gnu_i.text_next++] = item;
    }
}

void stack_add(char * item)
{
    if (!gnu_e)
    {
        masm_i.stack_alloc += strlen(item) + 2;
        masm_i.stack = realloc(masm_i.stack, masm_i.stack_alloc);
        masm_i.stack[masm_i.stack_next++] = item;
    }
}

void combine_code(char * before)
{
    if (gnu_e)
    {
        output = calloc(gnu_i.bss_next + 
        gnu_i.data_next + 
        gnu_i.text_next + 1, 
        gnu_i.bss_alloc + 
        gnu_i.data_alloc + 
        gnu_i.text_alloc + 
        strlen(before));

        strcpy(output, before);

        if (gnu_i.bss_next > 0) 
        {
            strcat(output, ".bss\n");

            for(int i = 0; i < gnu_i.bss_next; i++)
            {
                strcat(output, gnu_i.bss[i]);
                strcat(output, "\n");
            }
        }

        if (gnu_i.data_next > 0)
        {
            strcat(output, ".data\n");

            for(int i = 0; i < gnu_i.data_next; i++)
            {
                strcat(output, gnu_i.data[i]);
                strcat(output, "\n");
            }
        }

        if (gnu_i.text_next > 0) 
        {
            strcat(output, ".text\n");

            for(int i = 0; i < gnu_i.text_next; i++)
            {
                strcat(output, gnu_i.text[i]);
                strcat(output, "\n");
            }
        }
    }
    
    else
    {
        output = calloc(masm_i.code_next + 
            masm_i.data_next + 
            masm_i.dataq_next + 
            masm_i.stack_next + 1, 
            masm_i.code_alloc + 
            masm_i.data_alloc + 
            masm_i.dataq_alloc + 
            masm_i.stack_alloc +
            strlen(before));

        strcpy(output, before);


        if (masm_i.code_next > 0) 
        {
            strcat(output, ".CODE\n");

            for(int i = 0; i < masm_i.code_next; i++)
            {
                strcat(output, masm_i.code[i]);
                strcat(output, "\n");
            }
        }

        if (masm_i.data_next > 0)
        {
            strcat(output, ".DATA\n");

            for(int i = 0; i < masm_i.data_next; i++)
            {
                strcat(output, (masm_i.data[i]));
                strcat(output, "\n");
            }
        }

        if (masm_i.dataq_next > 0) 
        {
            strcat(output, ".DATA?\n");

            for(int i = 0; i < masm_i.dataq_next; i++)
            {
                strcat(output, (masm_i.dataq[i]));
                strcat(output, "\n");
            }
        }

        if (masm_i.stack_next > 0) 
        {
            strcat(output, ".STACK\n");

            for(int i = 0; i < masm_i.stack_next; i++)
            {
                strcat(output, (masm_i.stack[i]));
                strcat(output, "\n");
            }
        }

        strcat(output, "END main");
    }
}

void export_to(char * path)
{
	FILE * fp;
	fp = fopen(path, "w");

	fprintf(fp, output);

	fclose(fp);
}
