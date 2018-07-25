#include <stdio.h>
#include <stdlib.h>

#include "algorithms/ShiftCipher.h"

int main() {

	char* message = "Hello, world!";
	char* ciphertext = encrypt_sc_n(message, 13, 35);
	char* plaintext = decrypt_sc_n(ciphertext, 13, 35);

	printf("Original message: %21s\n", message);
	printf("Encrypted message: %20s\n", ciphertext);
	printf("Decrypted message: %20s\n", plaintext);

	free(ciphertext);
	free(plaintext);
	return 0;
}