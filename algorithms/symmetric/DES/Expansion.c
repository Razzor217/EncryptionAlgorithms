#include "Expansion.h"

uint64_t expansion(uint32_t r) {
	uint64_t p = 0ULL;
	int e[48] = {
		32,  1,  2,  3,  4,  5,
		 4,  5,  6,  7,  8,  9,
		 8,  9, 10, 11, 12, 13,
		12, 13, 14, 15, 16, 17, 
		16, 17, 18, 19, 20, 21,
		20, 21, 22, 23, 24, 25,
		24, 25, 26, 27, 28, 29,
		28, 29, 30, 31, 32,  1
	};

	int i;
	for (i=0; i<48; i++) {
		// Get value of permutation bit
		uint64_t x = (r >> (e[i] - 1)) & 1ULL;
		// Set i-th bit to permutation bit
		p = (p & ~(1ULL << i)) | (x << i);
	}

	return p;
}