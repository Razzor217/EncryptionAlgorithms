#include "DataEncryptionStandard.h"

#include "Feistel.h"
#include "InitialPermutation.h"
#include "KeySchedule.h"

uint64_t encrypt_DES(uint64_t m, uint64_t key) {
	uint64_t c = initialPermutation(m);
	uint32_t l = (c >> 32) & 0xFFFFFFFF;
	uint32_t r = c & 0xFFFFFFFF;
	uint64_t* k = keySchedule(key);

	uint32_t l_1;
	uint32_t r_1;

	int i;
	for (i=0; i<16; i++) {
		l_1 = r;
		r_1 = l ^ feistel(r, *(k+i));
		
		l = l_1;
		r = r_1;
	}

	c = ((uint64_t) r << 32) | (uint64_t) l;
	c = initialPermutation_inv(c);

	return c;
}

uint64_t decrypt_DES(uint64_t c, uint64_t key) {
	uint64_t m = initialPermutation(c);
	uint32_t l = (m >> 32) & 0xFFFFFFFF;
	uint32_t r = m & 0xFFFFFFFF;
	uint64_t* k = keySchedule(key);

	uint32_t l_1;
	uint32_t r_1;

	int i;
	for (i=0; i<16; i++) {
		l_1 = r;
		r_1 = l ^ feistel(r, *(k+15-i));
		
		l = l_1;
		r = r_1;
	}

	m = ((uint64_t) r << 32) | (uint64_t) l;
	m = initialPermutation_inv(m);

	return m;
}