#include <stdio.h>
#include "main.h"

/**
 * append_text_to_file - appends text to the end of a file
 * @filename: the name of the file to append to
 * @text_content: the text to append to the file
 *
 * Return: 1 on success, -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
int fd, bytes_written, index;

/* check if filename is NULL */
if (filename == NULL)
return (-1);

/* open the file in append mode */
fd = open(filename, O_WRONLY | O_APPEND);

/* check if opening the file failed */
if (fd == -1)
return (-1);

/* if text_content is not NULL, append it to the file */
if (text_content != NULL)
{
/* loop through the string until the end is reached */
for (index = 0; text_content[index] != '\0'; index++)
;

/* write the string to the file */
bytes_written = write(fd, text_content, index);

/* check if writing to the file failed */
if (bytes_written == -1)
return (-1);
}

/* close the file and return 1 on success */
close(fd);
return (1);
}

