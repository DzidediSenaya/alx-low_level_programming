# ifndef MAIN_H
# define MAIN_H
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int open_files(char *src_file, char *dest_file);
void copy_file_content(int fd_from, int fd_to, char *buffer, char *filename);

# endif

