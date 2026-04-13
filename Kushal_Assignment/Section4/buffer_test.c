#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[16];

    printf("Enter input: ");
    gets(buffer);

    printf("You entered: %s\n", buffer);

    return 0;
}

/*
1. Long input overflows buffer
2. Dangerous: memory corruption
3. Fix: use fgets()
*/
