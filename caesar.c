#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
    if (argc != 2) {
        printf("Usage: ./caesar n\n");
        return 1;
    }
    int delta = atoi(argv[1]);

    printf("plaintext:  ABCDE \n");
    char * str = "ABCDE";

    printf("ciphertext: ");
    for (int i = 0, len = strlen(str); i < len; i++)
    {
        char c = str[i];
        char new_c;
        if (c >= 'A' && c <= 'Z')
        {
            new_c = 'A' + (c -'A' + delta) % 26;
        }
        else if (c >= 'a' && c <= 'z')
        {
            new_c = 'a' + (c - 'a' + delta) % 26;
        }
        else
        {
            new_c = c;
        }
        printf("%c", new_c);
    }

    printf("\n");
    return 0;
}
