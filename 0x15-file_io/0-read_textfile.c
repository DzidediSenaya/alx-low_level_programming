#include "main.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * read_textfile - Reads a text file and prints it to stdout
 * @filename: Pointer to the name of the file to read
 * @letters: Number of letters to read from the file
 *
 * Return: Number of letters read and printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
int fd; /* File descriptor */
ssize_t numread, numprinted; /* Number of bytes read and printed */
char *buffer;/* Buffer to store data read from file */

/* Check if filename is null */
if (filename == NULL)
return (0);

/* Open file in read-only mode */
fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);

/* Allocate memory for buffer */
buffer = malloc(sizeof(char) * letters);
if (buffer == NULL)
return (0);
/* Read 'letters' bytes from file into buffer */
numread = read(fd, buffer, letters);
if (numread == -1)
{
free(buffer);
close(fd);
return (0);
}

/* Write 'numread' bytes from buffer to STDOUT */
numprinted = write(STDOUT_FILENO, buffer, numread);
if (numprinted == -1 || numprinted != numread)
{
free(buffer);
close(fd);
return (0);
}

/* Free memory and close file */
free(buffer);
close(fd);
return (numprinted);
}

