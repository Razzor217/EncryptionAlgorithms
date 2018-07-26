#include "Permutation.h"

uint32_t permutation(uint32_t r) {
	uint32_t p = 0UL;
	int per[32] = {
		16,  7, 20, 21,
		29, 12, 28, 17,
 		 1, 15, 23, 26,
 		 5, 18, 31, 10,
 		 2,  8, 24, 14,
		32, 27,  3,  9,
		19, 13, 30,  6,
		22, 11,  4, 25
	};

	int i;
	for (i=0; i<32; i++) {
		// Get value of permutation bit
		uint32_t x = (r >> (per[i] - 1)) & 1ULL;
		// Set i-th bit to permutation bit
		p = (p & ~(1ULL << i)) | (x << i);
	}

	return p;
}