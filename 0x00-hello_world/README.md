 0-preprocessor: This script runs a C file saved in the variable $CFILE through the preprocessor and saves the result in the file c.

1-compiler: This script compiles a C file saved in the variable $CFILE that does not link; saves the result in an output file of the same name but with a .o extension.Example: If the C file is main.c, the output is main.o.

2-assembler: This script generates the assembly code of a C code saved in the variable $CFILE; saves the result in an output file of the same name but with a .s extension.Example: If the C file is main.c, the result is main.s.

 3-name: This script compiles a C file saved in the variable $CFILE and creates an executable cisfun.

 4-puts.c: This C program prints exactly "Programming is like building a multilingual puzzle, followed by a new line, using the function puts.

5-printf.c: This C program prints exactly "with proper grammer, but the outcome is a piece of art,, followed by a new line, using the function printf.

6-size.c:This C program prints the size of various types on the computer it is compiled and run on.

100-intel: Tis script generates the assembly code in Intel syntax of a C file saved in the variable $CFILE; saves the result in an output file of the same name but with a .s extension.Example: If the C file is main.c, the output is main.s.

101-quote.c: This C program prints exactly and that piece of art is useful" - Dora Korpar, 2015-10-19, followed by a new line, to the standard error, without using any functions listed in the NAME sesction of the man(3) printf or man(3) puts.
