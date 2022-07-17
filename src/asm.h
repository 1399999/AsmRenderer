void render_init(void);

void bss_add(char * item);
void data_add(char * item);
void text_add(char * item);

void combine_code(void);
void export(char * path);

extern char ** bss;
extern char ** data;
extern char ** text;
extern char ** code;

#define EMPTY ""