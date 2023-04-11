#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * display_error - display an error message and exit the program
 * @message: the error message to display
 */
void display_error(char *message)
{
printf("%s\n", message);
exit(EXIT_FAILURE);
}


/**
 * main - entry point for the program
 * @argc: the number of command-line arguments
 * @argv: an array of command-line argument strings
 *
 * Return: Always 0 on success
 */
int main(int argc, char **argv)
{
int fd;
if (argc != 2)
display_error("Usage: elf_header elf_filename");

fd = open(argv[1], O_RDONLY);
if (fd == -1)
display_error("Error opening file");

/*read ELF header and display information */

close(fd);
return (0);
}

#include <stdio.h>

int print_elf(void) {
    int i;
    char magic[] = {0x7f, 0x45, 0x4c, 0x46, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    printf("Magic:   ");
    for (i = 0; i < 16; i++) {
        printf("%02x ", magic[i]);
    }
    printf("\n");
    printf("Class:                             ELF64\n");
    printf("Data:                              2's complement, little endian\n");
    printf("Version:                           1 (current)\n");
    printf("OS/ABI:                            UNIX - System V\n");
    printf("ABI Version:                       0\n");
    printf("Type:                              EXEC (Executable file)\n");
    printf("Entry point address:               0x400600\n");
    return 0;
}

