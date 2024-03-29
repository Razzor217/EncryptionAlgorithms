#include "KeyPermutation.h"

uint64_t permuted_choice_1(uint64_t key) {
	uint64_t k = 0ULL;
	int pc1[56] = {
		57, 49, 41, 33, 25, 17,  9,
		 1, 58, 50, 42, 34, 26, 18,
		10,  2, 59, 51, 43, 35, 27,
		19, 11,  3, 60, 52, 44, 36,
		63, 55, 47, 39, 31, 23, 15,
		 7, 62, 54, 46, 38, 30, 22,
		14,  6, 61, 53, 45, 37, 29,
		21, 13,  5, 28, 20, 12,  4
	};

	int i;
	for (i=0; i<56; i++) {
		// Get value of permutation bit
		uint64_t x = (key >> (pc1[i] - 1)) & 1ULL;
		// Set i-th bit to permutation bit
		k = (k & ~(1ULL << i)) | (x << i);
	}

	return k;
}

uint64_t permuted_choice_2(uint64_t key) {
	uint64_t k = 0ULL;
	int pc2[56] = {
		14, 17, 11, 24,  1,  5,
 		 3, 28, 15,  6, 21, 10,
		23, 19, 12,  4, 26,  8,
		16,  7, 27, 20, 13,  2,
		41, 52, 31, 37, 47, 55,
		30, 40, 51, 45, 33, 48,
		44, 49, 39, 56, 34, 53, 
		46, 42, 50, 36, 29, 32
	};

	int i;
	for (i=0; i<56; i++) {
		// Get value of permutation bit
		uint64_t x = (key >> (pc2[i] - 1)) & 1ULL;
		// Set i-th bit to permutation bit
		k = (k & ~(1ULL << i)) | (x << i);
	}

	return k;
}