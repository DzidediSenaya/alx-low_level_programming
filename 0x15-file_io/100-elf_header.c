#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <elf.h>

/**
 * display_error - display an error message and exit the program
 * @message: the error message to display
 */
void display_error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(98);
}

/**
 * display_elf_header - display information contained in an ELF header
 * @header: pointer to the ELF header structure
 */
void display_elf_header(Elf64_Ehdr *header)
{
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++)
        printf("%02x ", header->e_ident[i]);
    printf("\n");

    printf("  Class:                             ");
    switch (header->e_ident[EI_CLASS]) {
        case ELFCLASSNONE: printf("none\n"); break;
        case ELFCLASS32: printf("ELF32\n"); break;
        case ELFCLASS64: printf("ELF64\n"); break;
        default: printf("<unknown>\n");
    }

    printf("  Data:                              ");
    switch (header->e_ident[EI_DATA]) {
        case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
        case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
        default: printf("<unknown>\n");
    }

    printf("  Version:                           %d\n", header->e_ident[EI_VERSION]);

    printf("  OS/ABI:                            ");
    switch (header->e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
        case ELFOSABI_HPUX: printf("UNIX - HP-UX\n"); break;
        case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
        case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
        case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
        case ELFOSABI_IRIX: printf("UNIX - IRIX\n"); break;
        case ELFOSABI_FREEBSD: printf("UNIX - FreeBSD\n"); break;
        case ELFOSABI_TRU64: printf("UNIX - TRU64\n"); break;
        case ELFOSABI_ARM: printf("ARM\n"); break;
        case ELFOSABI_STANDALONE: printf("Standalone (embedded) application\n"); break;
        default: printf("<unknown>\n");
    }

    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);

    printf("  Type:                              ");
    switch (header->e_type) {
        case ET_NONE: printf("NONE (Unknown type)\n"); break;
        case ET_REL: printf("REL (Relocatable file)\n"); break;
        case ET_EXEC: printf("EXEC (Executable file)\n"); break;
        case ET_DYN: printf("DYN (Shared object file)\n"); break;
        case ET_CORE: printf("CORE (Core file)\n"); break;
        default: printf("<unknown>\n");
    }

    printf("  Entry point address:               %#lx\n", header->e_entry);
}

int main(int argc, char **argv)
{
    int fd;
    Elf64_Ehdr header;

    if (argc != 2)
        display_error("Usage: elf_header elf_filename");

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        display_error("Error opening file");

    if (read(fd, &header, sizeof(header)) != sizeof(header))
        display_error("Error reading ELF header");

    if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
        display_error("Not an ELF file");

    printf("Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++)
        printf("%02x ", header.e_ident[i]);
    printf("\n");

    printf("Class:                             %s\n",
           header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" :
           header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
           "Invalid");

    printf("Data:                              %s\n",
           header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
           header.e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" :
           "Invalid");

    printf("Version:                           %d\n",
           header.e_ident[EI_VERSION]);

    printf("OS/ABI:                            ");
    switch (header.e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
        case ELFOSABI_HPUX: printf("UNIX - HP-UX\n"); break;
        case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
        case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
        case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
        case ELFOSABI_IRIX: printf("UNIX - IRIX\n"); break;
        case ELFOSABI_FREEBSD: printf("UNIX - FreeBSD\n"); break;
        case ELFOSABI_TRU64: printf("UNIX - TRU64\n"); break;
        case ELFOSABI_ARM: printf("ARM\n"); break;
        case ELFOSABI_STANDALONE: printf("Standalone App\n"); break;
        default: printf("Unknown\n");
    }

    printf("ABI Version:                       %d\n",
           header.e_ident[EI_ABIVERSION]);

    printf("Type:                              ");
    switch (header.e_type) {
        case ET_NONE: printf("NONE (No file type)\n"); break;
        case ET_REL: printf("REL (Relocatable file)\n"); break;
        case ET_EXEC: printf("EXEC (Executable file)\n"); break;
        case ET_DYN: printf("DYN (Shared object file)\n"); break;
        case ET_CORE: printf("CORE (Core file)\n"); break;
        default: printf("Unknown\n");
    }

    printf("Entry point address:               %#lx\n",
           (unsigned long)header.e_entry);

    close(fd);
    return (0);
}
