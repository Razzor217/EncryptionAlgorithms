#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "algorithms/ShiftCipher.h"
#include "algorithms/Vigenere.h"

int main() {

	char* message = strdup("Hello, world!");
	char* key = "bzarf";

	char* ciphertext_sc_all = encrypt_sc_all(message, 13, 'q');
	char* plaintext_sc_all = decrypt_sc_all(ciphertext_sc_all, 13, 'q');

	char* ciphertext_v = encrypt_v(message, 13, key, 5);
	char* plaintext_v = decrypt_v(ciphertext_v, 13, key, 5);

	char* ciphertext_sc_n = encrypt_sc_n(message, 13, 'R');
	char* plaintext_sc_n = decrypt_sc_n(ciphertext_sc_n, 13, 'R');

	printf("Shift cipher (ASCII):\n");
	printf("Original message: %21s\n", message);
	printf("Encrypted message: %20s\n", ciphertext_sc_all);
	printf("Decrypted message: %20s\n", plaintext_sc_all);

	
	printf("Vigenere:\n");
	printf("Original message: %21s\n", message);
	printf("Encrypted message: %20s\n", ciphertext_v);
	printf("Decrypted message: %20s\n", plaintext_v);

	printf("Shift cipher (alphabet):\n");
	printf("Original message: %21s\n", message);
	printf("Encrypted message: %20s\n", ciphertext_sc_n);
	printf("Decrypted message: %20s\n", plaintext_sc_n);

	free(message);
	free(ciphertext_sc_all);
	free(ciphertext_v);
	free(ciphertext_sc_n);
	free(plaintext_sc_all);
	free(plaintext_v);
	free(plaintext_sc_n);
	return 0;
}