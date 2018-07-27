#ifndef TripleDEA_H
#define TripleDEA_H

#include <stdint.h>

uint64_t encrypt_TDEA(uint64_t, uint64_t, uint64_t, uint64_t);

uint64_t decrypt_TDEA(uint64_t, uint64_t, uint64_t, uint64_t);

#endif