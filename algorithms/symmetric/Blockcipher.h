#ifndef Blockcipher_H
#define Blockcipher_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "TripleDEA.h"

uint64_t* getInputBlocks_64(char*, int, int*);

char* getOutputBlocks_64(uint64_t*, int);

uint64_t* encrypt_TDEA_ECB(char*, int, int*, uint64_t, uint64_t, uint64_t);

char* decrypt_TDEA_ECB(uint64_t*, int, uint64_t, uint64_t, uint64_t);

uint64_t* encrypt_TDEA_CBC(char*, int, int*, uint64_t, uint64_t, uint64_t, uint64_t);

char* decrypt_TDEA_CBC(uint64_t*, int, uint64_t, uint64_t, uint64_t, uint64_t);

uint64_t* encrypt_TDEA_CTR(char*, int, uint64_t, uint64_t, uint64_t);

char* decrypt_TDEA_CTR(char*, int, uint64_t, uint64_t, uint64_t);

#endif