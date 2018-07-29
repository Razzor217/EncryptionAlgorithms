#include "Blockcipher.h"

uint64_t* getInputBlocks_64(char* m, int n, int* p) {
	if (n % 8 == 0)
		*p = n / 8;
	else 
		*p = (n / 8) + 1;
	int diff = n - (n / 8)*8;
	uint64_t* c = calloc(*p, sizeof(uint64_t));

	int i;
	for (i=0; i<(*p); i++)
		if (i == *(p)-1 && diff > 0)
			memcpy(c+i, m+(8*i), diff);
		else
			memcpy(c+i, m+(8*i), 8);

	return c;
}

char* getOutputBlocks_64(uint64_t* c, int p) {
	char* m = calloc(p*8, sizeof(char*));
	int i;
	for (i=0; i<p; i++)
		memcpy(m+(8*i), c+i, 8);

	return m;
}

uint64_t* encrypt_TDEA_ECB(char* m, int n, int* p, 
	uint64_t key_1, uint64_t key_2, uint64_t key_3) {

	uint64_t* c = getInputBlocks_64(m, n, p);

	int i;
	for (i=0; i<(*p); i++)
		*(c+i) = encrypt_TDEA(*(c+i), key_1, key_2, key_3);

	return c;
}

char* decrypt_TDEA_ECB(uint64_t* c, int p,
	uint64_t key_1, uint64_t key_2, uint64_t key_3) {

	int i;
	for (i=0; i<p; i++)
		*(c+i) = decrypt_TDEA(*(c+i), key_1, key_2, key_3);

	char* m = getOutputBlocks_64(c, p);

	return m;
}

/*
uint64_t* encrypt_TDEA_CBC(char* m, int n, int* p, uint64_t iv,
	uint64_t key_1, uint64_t key_2, uint64_t key_3) {

	uint64_t* c = getInputBlocks_64(m, n, p);

	int i;
	for (i=0; i<(*p); i++)
		if (i == 0)
			*(c+i) = encrypt_TDEA(*(c+i) ^ iv, key_1, key_2, key_3);
		else
			*(c+i) = encrypt_TDEA(*(c+i) ^ (*(c+(i-1))), key_1, key_2, key_3);

	return c;
}

char* decrypt_TDEA_CBC(uint64_t* c, int p, uint64_t iv,
	uint64_t key_1, uint64_t key_2, uint64_t key_3) {
	
	int i;
	for (i=0; i<p; i++)
		if (i == 0)
			*(c+i) = decrypt_TDEA(*(c+i), key_1, key_2, key_3) ^ iv;
		else
			*(c+i) = decrypt_TDEA(*(c+i), key_1, key_2, key_3) ^ (*(c+(i-1)));

	char* m = getOutputBlocks_64(c, p);

	return m;
}

char* encrypt_TDEA_CTR(char* m, int n, uint64_t key_1, uint64_t key_2, uint64_t key_3) {

}

char* decrypt_TDEA_CTR(char* m, int n, uint64_t key_1, uint64_t key_2, uint64_t key_3) {

}*/
