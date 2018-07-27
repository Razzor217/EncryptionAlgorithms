#include "KeySchedule.h"

#include "KeyPermutation.h"

uint64_t* keySchedule(uint64_t key) {
	int shifts[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
	uint64_t* k = calloc(16, sizeof(uint64_t));
	int i;
	for (i=0; i<16; i++)
		*(k+i) = 0ULL;

	key = permuted_choice_1(key);

	uint64_t c = 0ULL;
	uint64_t d = 0ULL;
	// Split k into c and d:
	for (i=0; i<28; i++) {
		// Extract bits from k
		uint64_t x = (key >> i) & 1ULL;
		uint64_t y = (key >> (i+28)) & 1ULL;
		// Write bits to c and d
		c = (c & ~(1ULL << (i+28))) | (y << (i+28));
		d = (d & ~(1ULL << i)) | (x << i);
	}

	for (i=0; i<16; i++) {
		key = 0ULL;
		c = c << shifts[i];
		d = d << shifts[i];
		key = (c << 28) | d;
		*(k+i) = permuted_choice_2(key);
	}

	return k;
}