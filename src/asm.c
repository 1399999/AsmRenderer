#include <stdio.h>
#include <string.h>
#include "func.h"

char ** bss;
char ** data;
char ** text;
char ** code;

void render_init(void)
{
    text[0] = ".global _start";
    text[1] = "_start:";
}

void bss_add(char * item)
{
    str_add_str(bss, item);
}

void data_add(char * item)
{
    str_add_str(data, item);
}

void text_add(char * item)
{
    str_add_str(text, item);
}

void combine_code(void)
{
    char * temp;

    if (!strcmp(bss, EMPTY))
    {
	str_add_str(temp, ".bss\n");

	for (int i = 0; bss[i]; i++)
    	    str_add_str(temp, str_add_ch(bss[i], '\n'));
    }

    if (!strcmp(data, EMPTY))
    {
	str_add_str(temp, ".data\n");

	for (int i = 0; data[i]; i++)
    	    str_add_str(temp, str_add_ch(data[i], '\n'));
    }

    if (!strcmp(text, EMPTY))
    {
	str_add_str(temp, ".text\n");

	for (int i = 0; text[i]; i++)
    	    str_add_str(temp, str_add_ch(text[i], '\n'));
    }

    strcpy(temp, code);
}

void export_to(char * path)
{
    FILE * fp = fopen(path, "a");
    fprintf(fp, code);
    fclose(fp);
}
