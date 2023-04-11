#ifndef ELF_H
#define ELF_H 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define ELFMAG0 0x7f
#define ELFMAG1 'E'
#define ELFMAG2 'L'
#define ELFMAG3 'F'
#define SELFMAG 4 
 
void check_elf(unsigned char *e_ident);
 void display_magic(unsigned char *e_ident);
 void display_class(unsigned char *e_ident);
 void display_data(unsigned char *e_ident);
 void display_version(unsigned char *e_ident);
 void display_osabi(unsigned char *e_ident);
 void display_abi(unsigned char *e_ident); 

 #endif


#include "elf.h"

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
/* Function to check if the given file is an ELF file*/
void check_elf(unsigned char *e_ident) {
    if (memcmp(e_ident, ELFMAG, SELFMAG) != 0) {
        fprintf(stderr, "Error: Not an ELF file\n");
        exit(98);
    }
}

/* Function to print the magic numbers of the given ELF file*/
void display_magic(unsigned char *e_ident) 
{
int i;

    printf("  Magic:   ");
    
for (i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", e_ident[i]);
    }
    printf("\n");
}

/*Function to print the class of the given ELF file*/
void display_class(unsigned char *e_ident) {
    printf("  Class:                             ");
    switch (e_ident[EI_CLASS]) {
        case ELFCLASSNONE:
            printf("none\n");
            break;
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("<unknown: %x>\n", e_ident[EI_CLASS]);
    }
}

/* Function to print the data encoding of the given ELF file*/
void display_data(unsigned char *e_ident) {
    printf("  Data:                              ");
    switch (e_ident[EI_DATA]) {
        case ELFDATANONE:
            printf("none\n");
            break;
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("<unknown: %x>\n", e_ident[EI_DATA]);
    }
}

/* Function to print the version of the given ELF file*/
void display_version(unsigned char *e_ident) {
    printf("  Version:                           %d", e_ident[EI_VERSION]);
    switch (e_ident[EI_VERSION]) {
        case EV_CURRENT:
            printf(" (current)\n");
            break;
        default:
            printf("\n");
            break;
    }
}

/* Function to print the operating system and ABI of the given ELF file*/
void display_osabi(unsigned char *e_ident) {
    printf("  OS/ABI:                            ");
    switch (e_ident[EI_OSABI]) {
        case ELFOSABI_NONE:
            printf("UNIX - System V\n");
 break;
        case ELFOSABI_HPUX:
            printf("UNIX - HP-UX\n");
            break;
        case ELFOSABI_NETBSD:
            printf("UNIX - NetBSD\n");
            break;
        case ELFOSABI_LINUX:
            printf("UNIX - Linux\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("UNIX - Solaris\n");
            break;
        case ELFOSABI_IRIX:
            printf("UNIX - IRIX\n");
            break;
        case ELFOSABI_FREEBSD:
            printf("UNIX - FreeBSD\n");
            break;
        case ELFOSABI_TRU64:
            printf("UNIX - TRU64\n");
            break;
        case ELFOSABI_ARM:
            printf("ARM\n");
            break;
        case ELFOSABI_STANDALONE:
            printf("Standalone App\n");
            break;
        default:
            printf("<unknown: %x>\n", e_ident[EI_OSABI]);
    }
}

/*Function to print the ABI version of the given ELF file*/
void display_abi(unsigned char *e_ident) {
    printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}

