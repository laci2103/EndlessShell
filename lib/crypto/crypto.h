//
// Created by IanLachance on 7/26/2017.
//

#ifndef ENDLESSSHELL_CRYPTO_H
#define ENDLESSSHELL_CRYPTO_H

#include <stdlib.h>
#include <ctype.h>

#define ASCII_SHIFT 97
#define ALPHABET 26
#define ROT13 13

int length(char* message);
char* ceasar_cipher(char* message, int shift);

#endif //ENDLESSSHELL_CRYPTO_H
