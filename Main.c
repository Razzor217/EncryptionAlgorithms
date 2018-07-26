#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "algorithms/symmetric/DES/InitialPermutation.h"
#include "algorithms/symmetric/DES/Selection.h"
#include "algorithms/symmetric/ShiftCipher.h"
#include "algorithms/symmetric/Vigenere.h"

int main() {

	/*
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
	*/

	// 15 = 0000 1111; change 4th bit to 0, i.e. 0000 0111 = 7
	uint64_t number = 15U;
	printf("Number: %llu\n", number);
	number = (number & ~(1ULL << 63)) | (1ULL << 63);
	printf("Change bit 4 of number to 0: %llu\n", number);

	number = 0ULL;
	number = (number & ~(1ULL << 57)) | (1ULL << 57);
	number = (number & ~(1ULL << 49)) | (1ULL << 49);
	number = (number & ~(1ULL << 41)) | (1ULL << 41);
	printf("Number: %llu\n", number);
	uint64_t ip = initialPermutation(number);
	printf("Permutate bits 58 and 1 of number: %llu\n", ip);
	uint64_t ip_inv = initialPermutation_inv(ip);
	printf("Change it back: %llu\n", ip_inv);

	printf("Selection function S1:\n");
	uint8_t input = 0b101111;
	printf("Input: %d\n", input);
	printf("Expected output: 7\n");
	uint8_t output = selection_1(input);
	printf("Actual output: %d\n", output);

	return 0;
}