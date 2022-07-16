#include "asm.h"

int main()
{
    test_add("mov r0, #1");
    test_add("ldr r1, =message");
    test_add("ldr r2, =len");
    test_add("mov r7, #4");
    test_add("swi 0");

    test_add("mov r7, #1");
    test_add("swi 0");

    data_add("message:");
    data_add(".asciz \"hello world\n\"");
    data_add("len = .-message");

    combine_code();
    export_to("C:\Asm\asm.S");
}