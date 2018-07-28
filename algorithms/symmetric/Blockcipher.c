#include "Blockcipher.h"

uint64_t* getInputBlocks_64(char* m, int n, int* p) {
	if (n % 8 == 0)
		*p = (n / 8);
	else
		*p = (n / 8) + 1;
	uint64_t* c = calloc(*p, sizeof(uint64_t));

	int i;
	int j;
	for (i=0; i<(*p); i++) {
		*(c+i) = 0ULL;
		for (j=0; j<8; j++) {
			if (i*8+j < n)
				*(c+i) = (*(c+i) << 8) | (uint64_t) *(m+(i*8+j));
			else
				*(c+i) = *(c+i) << 8;
		}
	}

	return c;
}

char* getOutputBlocks_64(uint64_t* c, int p) {
	char* m = calloc(p*8, sizeof(char));
	
	int i;
	int j;

	for (i=0; i<p; i++) {
		for (j=0; j<8; j++) {
			*(m+(i*8+j)) = (*(c+i) >> (56-8*j)) & 0xFF;
		}
	}

	return m;
}

char* encrypt_TDEA_ECB(char* m, int n, uint64_t key_1, uint64_t key_2, uint64_t key_3) {
	int p;
	uint64_t* c = getInputBlocks_64(m, n, &p);

	int i;
	for (i=0; i<p; i++) {
		*(c+i) = encrypt_TDEA(*(c+i), key_1, key_2, key_3);
	}

	char* out = getOutputBlocks_64(c, p);
	free(c);
	return out;
}

char* decrypt_TDEA_ECB(char* m, int n, uint64_t key_1, uint64_t key_2, uint64_t key_3) {
	int p;
	uint64_t* c = getInputBlocks_64(m, n, &p);

	int i;
	for (i=0; i<p; i++) {
		*(c+i) = decrypt_TDEA(*(c+i), key_1, key_2, key_3);
	}
	char* out = getOutputBlocks_64(c, p);
	free(c);
	return out;
}

/*
char* encrypt_TDEA_CBC(char* m, int n, uint64_t key_1, uint64_t key_2, uint64_t key_3) {

}

char* decrypt_TDEA_CBC(char* m, int n, uint64_t key_1, uint64_t key_2, uint64_t key_3) {

}

char* encrypt_TDEA_CTR(char* m, int n, uint64_t key_1, uint64_t key_2, uint64_t key_3) {

}

char* decrypt_TDEA_CTR(char* m, int n, uint64_t key_1, uint64_t key_2, uint64_t key_3) {

}
*/