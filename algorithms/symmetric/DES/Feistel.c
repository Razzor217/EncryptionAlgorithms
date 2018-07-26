#include "Feistel.h"

#include "Expansion.h"
#include "Permutation.h"
#include "Selection.h"

#include <stdlib.h>

uint32_t feistel(uint32_t r, uint64_t k) {
	uint64_t e = expansion(r);
	uint32_t f = 0UL;
	
	e = e ^ k;

	uint8_t* b = calloc(8, sizeof(uint8_t));
	int i;
	int j;
	// Initialize blocks with zeroes
	for (i=0; i<8; i++)
		*(b+i) = 0U;

	// Divide 48 bit block into 8 6 bit blocks
	for (i=0; i<8; i++) {
		 for (j=0; j<6; j++) {
		 	uint8_t x = (e >> (i*6+j)) & 1ULL;
		 	*(b+i) = ((*(b+i)) & ~(1ULL << (i*6+j))) | (x << (i*6+j));
		 }
	}

	// Select 4 bits from each block
	*b = selection_1(*b);
	*(b+1) = selection_2(*(b+1));
	*(b+2) = selection_3(*(b+2));
	*(b+3) = selection_4(*(b+3));
	*(b+4) = selection_5(*(b+4));
	*(b+5) = selection_6(*(b+5));
	*(b+6) = selection_7(*(b+6));
	*(b+7) = selection_8(*(b+7));

	// Concatenate all 8 blocks
	f = ((uint32_t) *(b+7) << 4) | (uint32_t) *(b+6);
	f = (f << 4) | (uint32_t) *(b+5);
	f = (f << 4) | (uint32_t) *(b+4);
	f = (f << 4) | (uint32_t) *(b+3);
	f = (f << 4) | (uint32_t) *(b+2);
	f = (f << 4) | (uint32_t) *(b+1);
	f = (f << 4) | (uint32_t) *b;

	// Apply permutation to concatenated blocks
	f = permutation(f);

	return f;
}