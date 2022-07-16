void combine_code(void);
void export(char * path);

extern char ** bss;
extern char ** data;
extern char ** text;
extern char ** code;

#define EMPTY ""