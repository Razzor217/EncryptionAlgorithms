#include "Vigenere.h"

char* encrypt_v(char* m, int n, char* k, int p) {
	char* c = calloc(n, sizeof(char));
	int i;
	for (i=0; i<n; i++) {
		*(c+i) = ((((*(m+i) - 32 
			+ (*(k + (i % p)))) % 95) + 95) % 95) + 32;
	}
	return c;
}

char* decrypt_v(char* c, int n, char* k, int p) {
	char* m = calloc(n, sizeof(char));
	int i;
	for (i=0; i<n; i++) {
		*(m+i) = ((((*(c+i) - 32 
			- (*(k + (i % p) ))) % 95) + 95) % 95) + 32;
	}
	return m;
}