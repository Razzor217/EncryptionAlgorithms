#include <stdint.h>
#include <stdlib.h>

/*
 * Implements a basic shift cipher.
 * Input is character based, as is the key for this rather trivial algorithm.
 * Therefore, int8_t is used and input values should be in the range {0, ..., 25}.
 */

/*
 * Shifts every element of the plaintext by k elements to the right.
 * Returns a pointer to a new array containing the ciphertext.
 */
int8_t* encrypt_sc_n(int8_t*, int, int8_t);

/*
 * Shifts every element of the ciphertext by k elements to the left.
 * Returns a pointer to a new array containing the plaintext.
 */
int8_t* decrypt_sc_n(int8_t*, int, int8_t);

/*
 * Shifts every element of the plaintext by k elements to the right.
 */
void encrypt_sc(int8_t*, int, int8_t);

/*
 * Shifts every element of the ciphertext by k elements to the left.
 */
void decrypt_sc(int8_t*, int, int8_t);

int8_t* encrypt_sc_n(int8_t* m, int n, int8_t k) {
	int8_t* c = calloc(n, sizeof(int8_t));
	int i;
	for (i=0; i<n; i++)
		*(c+i) = (*(m+i) + k) % 26;
	return c;
}

void encrypt_sc(int8_t* m, int n, int8_t k) {
	int i;
	for (i=0; i<n; i++)
		*(m+i) = (*(m+i) + k) % 26;
}