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

