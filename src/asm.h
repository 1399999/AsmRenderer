void render_init(unsigned int bss_len, unsigned int data_len);
void render_finish(void);

void bss_add(char * item);
void data_add(char * item);
void text_add(char * item);

void combine_code(void);
void export_to(char * path);

extern char ** bss;
extern char ** data;
extern char ** text;
extern char * code;

extern unsigned int bss_next;
extern unsigned int data_next;
extern unsigned int text_next;

extern unsigned int bss_alloc;
extern unsigned int data_alloc;
extern unsigned int text_alloc;
