/* This file contians the logicthat is needed to use AsmRenderer. */

void render_init(void);

void bss_add(char * item);
void data_add(char * item);
void text_add(char * item);

void combine_code(void);
void export_to(char * path);

extern char ** bss;
extern char ** data;
extern char ** text;
extern char * code;

extern unsigned long bss_next;
extern unsigned long data_next;
extern unsigned long text_next;

extern unsigned long bss_alloc;
extern unsigned long data_alloc;
extern unsigned long text_alloc;
