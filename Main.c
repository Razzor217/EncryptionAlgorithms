#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "algorithms/symmetric/DES/DataEncryptionStandard.h"
#include "algorithms/symmetric/ShiftCipher.h"
#include "algorithms/symmetric/Vigenere.h"

int main() {

	uint64_t message = 0xFFFFFFFF;
	uint64_t key = 0xFFAFB9FF;
	uint64_t ciphertext = encrypt_DES(message, key);
	uint64_t plaintext = decrypt_DES(ciphertext, key);

	printf("Message: %23llx\n", message);
	printf("Ciphertext: %20llx\n", ciphertext);
	printf("Plaintext: %21llx\n", plaintext);
	return 0;
}