#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int is_valid_number(char *num) {
    while (*num) {
        if (!isdigit(*num)) {
            return 0;
        }
        num++;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 3 || !is_valid_number(argv[1]) || !is_valid_number(argv[2])) {
        printf("Error\n");
        return 98;
    }
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    int result = num1 * num2;
    printf("%d\n", result);
    return 0;
}
