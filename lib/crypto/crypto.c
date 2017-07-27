//
// Created by IanLachance on 7/26/2017.
//

#include <stdlib.h>
#include <ctype.h>

// Length of a message
int length(char* message)
{
    int count = 0;
    char* ptr = message;

    while (*ptr != '\0') {
        ptr++;
        count++;
    }
    return count;
}

// ROT13 encryption
char* rot13(char* message)
{
    int len = length(message);
    char* encrypted_message = (char *) malloc(sizeof(char) * (len+1));


    for (int i = 0; i < len; i++) {
        encrypted_message[i] = (char)((((tolower(message[i]) - 97) + 13) % 25) + 97);
    }

    encrypted_message[len] = '\0';

    return encrypted_message;
}