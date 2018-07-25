#ifndef Vigenere_H
#define Vigenere_H

#include <stdlib.h>
#include <stdio.h>

/*
 * Encryption and Decryption exactly as in shift cipher. Only difference:
 * Key is now a sequence of characters which is cycled.
 */

char* encrypt_v(char*, int, char*, int);

char* decrypt_v(char*, int, char*, int);

#endif