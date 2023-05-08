#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <elf.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

int main(int argc, char **argv)
{
 int fd, res;
 Elf64_Ehdr elf_hdr;

 if (argc != 2)
 {
 printf("Usage: %s \n", argv[0]);
 exit(1);
 }

 if ((fd = open(argv[1], O_RDONLY)) == -1)
 {
 perror("open");
 exit(1);
 }

 if ((res = read(fd, &elf_hdr, sizeof(Elf64_Ehdr))) == -1)
 {
 perror("read");
 close(fd);
 exit(1);
 }
 else if (res == 0)
 {
 fprintf(stderr, "Error: Empty file\n");
 close(fd);
 exit(98);
 }

 check_elf(elf_hdr.e_ident);
 print_magic(elf_hdr.e_ident);
 print_class(elf_hdr.e_ident);
 print_data(elf_hdr.e_ident);
 print_version(elf_hdr.e_ident);
 print_abi(elf_hdr.e_ident);
 print_osabi(elf_hdr.e_ident);
 print_type(elf_hdr.e_type);
 print_entry(elf_hdr.e_entry, elf_hdr.e_ident);

 close_elf(fd);

 return 0;
}

void check_elf(unsigned char *e_ident)
{
 if (!(e_ident[0] == ELFMAG0 && e_ident[1] == ELFMAG1 &&
 e_ident[2] == ELFMAG2 && e_ident[3] == ELFMAG3))
 {
 fprintf(stderr, "Error: Not an ELF file\n");
 exit(98);
 }
}

void print_magic(unsigned char *e_ident)
{
 int i;
 printf(" Magic: ");
 for (i = 0; i < EI_NIDENT; i++)
 printf("%02x ", e_ident[i]);
 printf("\n");
}

void print_class(unsigned char *e_ident)
{
 printf(" Class: ");
 switch (e_ident[EI_CLASS])
 {
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
printf("\n");
}

}
/**
 * print_data - Prints the data of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_data(unsigned char *e_ident)
{
 printf(" Data: ");

 switch (e_ident[EI_DATA])
 {
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
 printf("\n");
}

}

/**
 * print_version - Prints the version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void print_version(unsigned char *e_ident)
{
 printf(" Version: %d",
 e_ident[EI_VERSION]);

 switch (e_ident[EI_VERSION])
 {
 case EV_CURRENT:
 printf(" (current)\n");
 break;
 default:
 printf("\n");
 break;
 }
}

/**
 * print_osabi - Prints the OS/ABI of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void print_osabi(unsigned char *e_ident)
{
 printf(" OS/ABI: ");

 switch (e_ident[EI_OSABI])
 {
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
printf("\n");
 }
}

/**
 * print_abi - Prints the ABI version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF ABI version.
 */
void print_abi(unsigned char *e_ident)
{
 printf(" ABI Version: %d\n",
 e_ident[EI_ABIVERSION]);
}

void print_type(unsigned int e_type)
{
 printf("/n");

 if (e_type == ET_REL) {
 printf("Relocatable file\n");
 } else if (e_type == ET_EXEC) {
 printf("Executable file\n");
 } else if (e_type == ET_DYN) {
 printf("Shared object file\n");
 } else if (e_type == ET_CORE) {
 printf("Core file\n");
 } else {
 printf("Unknown type\n");
 }
}
/*
 print_entry - prints the entry point of the ELF file
 @e_entry: entry point of the ELF file
 @e_ident: pointer to the ELF identification bytes
*/
void print_entry(unsigned long int e_entry, unsigned char *e_ident) {
 if (e_ident[EI_CLASS] == ELFCLASS32) {
 printf("Entry point: 0x%lx\n", (unsigned long int)e_entry);
 } else if (e_ident[EI_CLASS] == ELFCLASS64) {
 printf("Entry point: 0x%lx\n", e_entry);
 } else {
 fprintf(stderr, "Invalid ELF class\n");
 }
}


/*
 close_elf - closes the ELF file descriptor
 @elf: the ELF file descriptor
*/
void close_elf(int elf) {
 if (close(elf) == -1) {
 perror("Failed to close ELF file descriptor");
 exit(EXIT_FAILURE);
 }
}
