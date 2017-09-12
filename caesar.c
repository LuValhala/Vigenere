#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>

int prepare_key(char * key, int keylen);
char rotate(char c, char delta);

int main(int argc, char * argv[])
{
    printf("Vigenere Program \n");
    if (argc != 2) {
        printf("Usage: ./caesar n\n");
        return 1;
    }

    char * key = argv[1];
    int keylen = strlen(key);
    if (!prepare_key(key, keylen))
    {
        printf("Please use valid key!\n");
        return 1;
    }

    printf("plaintext: ABCDE \n");
    char * str = "ABCDE";

    printf("ciphertext: ");
    int char_count = 0;
    for (int i = 0, len = strlen(str); i < len; i++)
    {
        if (isalpha(str[i]))
        {
            int delta = key[char_count % keylen];
            int encoded = rotate(str[i], delta);
            printf("%c", encoded);

            char_count++;
        }
        else
        {
            printf("%c", str[i]);
        }
    }

    printf("\n");
    return 0;
}

int prepare_key(char * key, int keylen)
{
    for (int i = 0 ; i < keylen; i++) {
        if (!isalpha(key[i]))
        {
            return 0;
        }

        key[i] = toupper(key[i]) - 'A';
    }

    return 1;
}

char rotate(char c, char delta)
{
    if (c >= 'A' && c <= 'Z')
    {
        return 'A' + (c -'A' + delta) % 26;
    }
    else if (c >= 'a' && c <= 'z')
    {
        return 'a' + (c - 'a' + delta) % 26;
    }
    else
    {
        return c;
    }
}
