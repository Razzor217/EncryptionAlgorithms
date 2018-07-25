#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "algorithms/ShiftCipher.h"

int main() {

	char* message = strdup("Hello, world!");
	char* ciphertext = encrypt_sc_all(message, 13, 35);
	char* plaintext = decrypt_sc_all(ciphertext, 13, 35);

	printf("Original message: %21s\n", message);
	printf("Encrypted message: %20s\n", ciphertext);
	printf("Decrypted message: %20s\n", plaintext);

	encrypt_sc(message, 13, 20);
	printf("Encrypted message: %20s\n", message);
	decrypt_sc(message, 13, 20);
	printf("Decrypted message: %20s\n", message);

	free(message);
	free(ciphertext);
	free(plaintext);
	return 0;
}