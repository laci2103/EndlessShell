//
// Created by IanLachance on 7/26/2017.
//

#include "crypto.h"

// TODO: More crypto functions :D

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

// Ceasar cipher encryption
char* ceasar_cipher(char* message, int shift)
{
    int len = length(message);
    char* encrypted_message = (char *) malloc(sizeof(char) * (len+1));


    for (int i = 0; i < len; i++) {
        encrypted_message[i] = (char)((((tolower(message[i]) - ASCII_SHIFT) + shift) % (ALPHABET - 1)) + ASCII_SHIFT);
    }

    encrypted_message[len] = '\0';

    return encrypted_message;
}