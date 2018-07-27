#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "algorithms/symmetric/TripleDEA.h"
#include "algorithms/symmetric/ShiftCipher.h"
#include "algorithms/symmetric/Vigenere.h"

int main() {
	uint64_t message = 0xFFFFFFFF;
	uint64_t key_1 = 0xFFAFB9FF;
	uint64_t key_2 = 0xAABBACDE;
	uint64_t key_3 = 0xFEDCBA98;
	uint64_t ciphertext = encrypt_TDEA(message, key_1, key_2, key_3);
	uint64_t plaintext = decrypt_TDEA(ciphertext, key_1, key_2, key_3);

	printf("Message: %23llx\n", message);
	printf("Ciphertext: %20llx\n", ciphertext);
	printf("Plaintext: %21llx\n", plaintext);
	return 0;
}