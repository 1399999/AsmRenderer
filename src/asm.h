typedef enum
{
    GNU,
    MASM
} asm_enum;

void render_init(asm_enum asm_e);

void bss_add(char * item);
void data_add(char * item);
void text_add(char * item);

void code_add(char * item);
void data_add(char * item);
void dataq_add(char * item);
void stack_add(char * item);

void combine_code(char * before);
void export_to(char * path);

extern unsigned short gnu_e;

extern char * output;

typedef struct gnu
{
    char ** bss;
    char ** data;
    char ** text;

    unsigned long bss_next;
    unsigned long data_next;
    unsigned long text_next;

    unsigned long bss_alloc;
    unsigned long data_alloc;
    unsigned long text_alloc;
} gnu_t;

typedef struct masm
{
    char ** code;
    char ** data;
    char ** dataq;
    char ** stack;

    unsigned long data_next;
    unsigned long dataq_next;
    unsigned long stack_next;
    unsigned long code_next;

    unsigned long data_alloc;
    unsigned long dataq_alloc;
    unsigned long stack_alloc;
    unsigned long code_alloc;

} masm_t;

extern gnu_t gnu_i;
extern masm_t masm_i;
