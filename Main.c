#include <stdio.h>
#include <stdlib.h>

#include "algorithms/ShiftCipher.h"

int main() {

	char* message = "Hello, world!";
	// Classic caesar
	char* ciphertext = encrypt_sc_all(message, 13, 5);
	char* plaintext = decrypt_sc_all(ciphertext, 13, 5);

	printf("Original message: %s\n", message);
	printf("Encrypted message: %s\n", ciphertext);
	printf("Decrypted message: %s\n", plaintext);

	return 0;
}