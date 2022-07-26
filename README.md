# AsmRenderer
## Project Description
> #### This is a library for Assembly Rendering. This library is used in some compilers.
## Examples
> #### This is an ARM example that prints "Hello, World!"

```
render_init();

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

export_to("C:\\ASM\\asm.s");

printf("%s", code);
```

## Function Description

- The render_init function initializes AsmRenderer for use.
- The text_add function adds the specified text to the assembly text section.
- The data_add function adds the specified text to the assembly data section.
- The bss_add function adds the specified text to the assembly bss section.
- The combine_code function combines the text, data and bss sections into one code block.
- The export_to function exports the combined code and exports it to the specified file.
