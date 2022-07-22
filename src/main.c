/* This file is used for testing. */

#include <stdio.h>
#include "asm.h"

// Testing method.

int main()
{
    render_init(0, 4);

    text_add("mov r0, #1");
    text_add("ldr r1, =message");
    text_add("ldr r2, =len");
    text_add("mov r7, #4");
    text_add("swi 0");

    text_add("mov r7, #1");
    text_add("swi 0");
    
    data_add("message:");
    data_add(".asciz \"Hello, World!\\n\"");
    data_add("len = .-message");

    combine_code();
    export_to("C:\\C\\ASM\\AsmRenderer\\src\\asm.s");

    printf("%s", code);

    return 0;
}
