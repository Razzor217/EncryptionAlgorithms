#ifndef Blockcipher_H
#define Blockcipher_H

#include <stdint.h>
#include <stdlib.h>

#include "TripleDEA.h"

uint64_t* getInputBlocks_64(char*, int, int*);

char* getOutputBlocks_64(uint64_t*, int);

char* encrypt_TDEA_ECB(char*, int, uint64_t, uint64_t, uint64_t);

char* decrypt_TDEA_ECB(char*, int, uint64_t, uint64_t, uint64_t);

char* encrypt_TDEA_CBC(char*, int, uint64_t, uint64_t, uint64_t);

char* decrypt_TDEA_CBC(char*, int, uint64_t, uint64_t, uint64_t);

char* encrypt_TDEA_CTR(char*, int, uint64_t, uint64_t, uint64_t);

char* decrypt_TDEA_CTR(char*, int, uint64_t, uint64_t, uint64_t);

#endif