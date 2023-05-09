#include "main.h"
#define BUFFER_SIZE 1024

int open_files(char *src_file, char *dest_file);
void copy_file_content(int fd_from, int fd_to, char *buffer, char *filename);

/**
 * main - copies the content of a file to another file
 *  @argc: array of pointers to args
 *  @argv: number of args
 *  Return: 0 if success
 */
int main(int argc, char *argv[])
{
int fd_from, fd_to;
char buffer[BUFFER_SIZE];

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

fd_from = open_files(argv[1], argv[2]);
fd_to = open_files(argv[2], NULL);
copy_file_content(fd_from, fd_to, buffer, argv[2]);

close(fd_from);
close(fd_to);

return (0);
}

/**
 * open_files - opens the source and/or destination files
 * @src_file: the name of the source file
 * @dest_file: the name of the destination file, NULL if not applicable
 * Return: the file descriptor of the opened file
 */
int open_files(char *src_file, char *dest_file)
{
int fd;

fd = open(src_file, O_RDONLY);
if (fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src_file);
exit(98);
}

if (dest_file != NULL)
{
fd = open(dest_file, O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dest_file);
exit(99);
}
}

return (fd);
}

/**
 * copy_file_content - copies the contents of one file to another
 * @fd_from: the file descriptor of the source file
 * @fd_to: the file descriptor of the destination file
 * @buffer: a buffer to temporarily store file content
 * @filename: the name of the file being written to
 */
void copy_file_content(int fd_from, int fd_to, char *buffer, char *filename)
{
ssize_t bytes_read, bytes_written;

while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
bytes_written = write(fd_to, buffer, bytes_read);
if (bytes_written != bytes_read)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
exit(99);
}
}

if (bytes_read == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
exit(98);
}
}

