typedef enum
{
    BSS,
    DATA,
    TEXT
} sections;

unsigned int str_ary_len(char ** str_ary);
void aalloc_ary(char ** str_ary, sections s, unsigned int amount);
