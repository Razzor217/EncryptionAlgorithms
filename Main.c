#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "algorithms/symmetric/Blockcipher.h"
#include "algorithms/symmetric/TripleDEA.h"
#include "algorithms/symmetric/ShiftCipher.h"
#include "algorithms/symmetric/Vigenere.h"

void int64ToChar(char a[], uint64_t n);
uint64_t charTo64bitNum(char a[]);

int main() {
	
	uint64_t msg = 0b01000011011011110110110001101111011100100110011001110101011011000;
	uint64_t key_1 = 0xFFAFB9FF;
	uint64_t key_2 = 0xAABBACDE;
	uint64_t key_3 = 0xFEDCBA98;
	/*
	uint64_t ciphertext = encrypt_TDEA(msg, key_1, key_2, key_3);
	uint64_t plaintext = decrypt_TDEA(ciphertext, key_1, key_2, key_3);

	printf("Message: %23llx\n", msg);
	printf("Ciphertext: %20llx\n", ciphertext);
	printf("Plaintext: %21llx\n", plaintext);

	char* str = "Dies werden 24 Zeichen!!";

	printf("Message: %s\n", str);
	printf("Char to uint64_t (1): %llx\n", charTo64bitNum(str));
	printf("Char to uint64_t (2): %llx\n", charTo64bitNum(str+8));
	printf("Char to uint64_t (3): %llx\n", charTo64bitNum(str+16));
	char* c = calloc(8, sizeof(char));
	int64ToChar(c, charTo64bitNum(str));
	printf("uint64_t to char (1): %s\n", c);
	int64ToChar(c, charTo64bitNum(str+8));
	printf("uint64_t to char (2): %s\n", c);
	int64ToChar(c, charTo64bitNum(str+16));
	printf("uint64_t to char (3): %s\n", c);

	int n = 123;
	printf("%d / 8 = %d; (%d / 8) * 8 = %d. Differenz: %d\n", 
		n, n/8, n, (n/8)*8, n - (n/8)*8);
	*/

	char* str = "Das Denken ist zwar allen Menschen erlaubt, \
aber vielen bleibt es erspart.";

	printf("--------------------------------------------------------------------\n");
	printf("Message:\n");
	printf("%s\n", str);
	int p;
	uint64_t* cipher = encrypt_TDEA_ECB(str, strlen(str), &p, key_1, key_2, key_3);
	char* plain = decrypt_TDEA_ECB(cipher, p, key_1, key_2, key_3);

	printf("Ciphertext:\n");
	int i;
	for (i=0; i<p; i++) {
		printf("%llx\n", *(cipher+i));
	}
	printf("Plaintext:\n");
	printf("%s\n", plain);

	//free(c);
	free(cipher);
	free(plain);
	return 0;
}

void int64ToChar(char a[], uint64_t n) {
  memcpy(a, &n, 8);
}

uint64_t charTo64bitNum(char a[]) {
  uint64_t n = 0;
  memcpy(&n, a, 8);
  return n;
}