#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

/**
* create_file - creates a new file and writes text content to it
* @filename: name of the file to be created
* @text_content: text to be written to the file
* Return: 1 on success, -1 on failure
*/

int create_file(const char *filename, char *text_content)
{
int fd, len = 0;
/* Check if filename is null or text_content is empty */
if (!filename || (!text_content && text_content[0] != '\0'))
{
return (-1);
}

/* Open file for writing, create it if it doesn't exist */
fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
if (fd == -1)
{
return (1);
}

/* Find the length of text_content */
while (text_content && text_content[len])
{
len++;
}

/* Write text_content to file */
if (write(fd, text_content, len) == -1)
{
close(fd);
return (-1);
}

/* Change file permissions to read/write for owner only */
if (chmod(filename, 0600) == -1)
{
close(fd);
return (-1);
}

/* Close file descriptor and return success */
close(fd);
return (1);
}
