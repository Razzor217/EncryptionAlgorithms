#include "ShiftCipher.h"

char* encrypt_sc_n(char* m, int n, char k) {
	char* cipher = calloc(n, sizeof(char));
	int i;
	for (i=0; i<n; i++) {
		char c = *(m+i);
		char start = getRange_sc(c);
		if (start>0)
			*(cipher+i) = ((c-start+k) % 26) + start;
		else
			*(cipher+i) = c;
	}
	return cipher;
}

char* decrypt_sc_n(char* cipher, int n, char k) {
	char* m = calloc(n, sizeof(char));
	int i;
	for (i=0; i<n; i++) {
		char c = *(cipher+i);
		char start = getRange_sc(c);
		if (start>0)
			*(m+i) = ((c-start-k) % 26) + start;
		else
			*(m+i) = c;
	}
	return m;
}

void encrypt_sc(char* m, int n, char k) {
	int i;
	for (i=0; i<n; i++) {
		char c = *(m+i);
		char start = getRange_sc(c);
		if (start>0)
			*(m+i) = ((c-start+k) % 26) + start;
	}
}

void decrypt_sc(char* cipher, int n, char k) {
	int i;
	for (i=0; i<n; i++) {
		char c = *(cipher+i);
		char start = getRange_sc(c);
		if (start>0)
			*(cipher+i) = ((c-start-k) % 26) + start;
	}
}

char* encrypt_sc_all(char* m, int n, char k) {
	char* c = calloc(n, sizeof(char));
	int i;
	for (i=0; i<n; i++)
		*(c+i) = ((*(m+i) - 32 + k) % 95) + 32;
	return c;
}

char* decrypt_sc_all(char* c, int n, char k) {
	char* m = calloc(n, sizeof(char));
	int i;
	for (i=0; i<n; i++)
		*(m+i) = ((*(c+i) - 32 - k) % 95) + 32;
	return m;
}

char getRange_sc(char c) {
	if (c >= 'A' && c <= 'Z')
		return 'A';
	else if (c >= 'a' && c <= 'z')
		return 'a';
	else
		return 0;
}