#ifndef ShiftCipher_H
#define ShiftCipher_H

#include <stdint.h>
#include <stdlib.h>

/*
 * Implements a basic shift cipher.
 * Input is character based, as is the key for this rather trivial algorithm.
 */

/*
 * Shifts every element of the plaintext by k elements to the right.
 * Returns a pointer to a new array containing the ciphertext.
 */
char* encrypt_sc_n(char*, int, char);

/*
 * Shifts every element of the ciphertext by k elements to the left.
 * Returns a pointer to a new array containing the plaintext.
 */
char* decrypt_sc_n(char*, int, char);

/*
 * Shifts every element of the plaintext by k elements to the right.
 */
void encrypt_sc(char*, int, char);

/*
 * Shifts every element of the ciphertext by k elements to the left.
 */
void decrypt_sc(char*, int, char);

/*
 * Encryption for all printable characters.
 */
char* encrypt_sc_all(char*, int, char);

/*
 * Decryption for all printable characters.
 */
char* decrypt_sc_all(char*, int, char);

/*
 * Finds the starting value of the ASCII character to transform into alphabet
 */
char getRange_sc(char);

#endif