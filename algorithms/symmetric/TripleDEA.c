#include "TripleDEA.h"

#include "DES/DataEncryptionStandard.h"

uint64_t encrypt_TDEA(uint64_t m, uint64_t key_1, uint64_t key_2, uint64_t key_3) {
	return encrypt_DES(decrypt_DES(encrypt_DES(m, key_1), key_2), key_3);
}

uint64_t decrypt_TDEA(uint64_t c, uint64_t key_1, uint64_t key_2, uint64_t key_3) {
	return decrypt_DES(encrypt_DES(decrypt_DES(c, key_3), key_2), key_1);
}