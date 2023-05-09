#include "main.h"
#define BUFFER_SIZE 1024

int open_file_read(char *filename);
int open_file_write(char *filename, mode_t mode);
void copy_file_content(int fd_from, int fd_to, char *buffer, char *filename);
void close_file(int fd);

/**
 * main - copies the content of a file to another file
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 * Return: 0 on success, otherwise an error code
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

fd_from = open_file_read(argv[1]);
fd_to = open_file_write(argv[2], 0664);

copy_file_content(fd_from, fd_to, buffer, argv[2]);

close_file(fd_from);
close_file(fd_to);

return (0);
}

/**
 * open_file_read - opens a file for reading
 * @filename: the name of the file to open
 * Return: the file descriptor of the opened file
 */
int open_file_read(char *filename)
{
int fd;

fd = open(filename, O_RDONLY);
if (fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
exit(98);
}

return (fd);
}

/**
 * open_file_write - opens a file for writing
 * @filename: the name of the file to open
 * @mode: the file permission mode
 * Return: the file descriptor of the opened file
 */
int open_file_write(char *filename, mode_t mode)
{
int fd;

fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, mode);
if (fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
exit(99);
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

/**
 * close_file - closes a file
 * @fd: the file descriptor of the file to be closed
 * Return: void
 */
void close_file(int fd)
{
if (close(fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}

