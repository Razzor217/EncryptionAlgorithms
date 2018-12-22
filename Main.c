#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include "algorithms/symmetric/Blockcipher.h"
#include "algorithms/symmetric/TripleDEA.h"
#include "algorithms/symmetric/ShiftCipher.h"
#include "algorithms/symmetric/Vigenere.h"

void int64ToChar(char a[], uint64_t n);

uint64_t charTo64bitNum(char a[]);

char displayMenu();

//void displayShiftMenu();

void displayTDEAMenu();

//void displayVigenereMenu();

void enterMessage();

int main() {
	char input;
	do {
		input = displayMenu();
		
		switch (input) {
			case 's':
			case 'S':
				//displayShiftMenu();
			break;
			case 't':
			case 'T':
				displayTDEAMenu();
			break;
			case 'v':
			case 'V':
				//displayVigenereMenu();
			break;
		}
	} while (input != 'q' && input != 'Q');
	return 0;
}

void uint64ToChar(char a[], uint64_t n) {
  memcpy(a, &n, 8);
}

uint64_t charToUint64(char a[]) {
  uint64_t n = 0;
  memcpy(&n, a, 8);
  return n;
}

char displayMenu() {
	printf("Select encryption method:\n");
	printf("(Press 'q' to quit)\n");
	printf("\n");
	printf("(S)hift Cipher (i.e. Caesar's Cipher)\n");
	printf("(T)riple Data Encryption Algorithm (ECB mode)\n");
	printf("(V)igenere Cipher\n");

	return getchar();
}

/*
void displayShiftMenu() {
	char input;
	do {
		printf("Please ")
	} while (input != 'b' && input != 'B');
}
*/

void displayTDEAMenu() {
	char input;
	do {
		printf("Triple Data Encryption Algorithm:\n");
		printf("(Press 'b' to go back to the main menu)\n");
		printf("\n");
		printf("Please provide three keys for encryption\n");
		printf("(64 bit, 16 hexadecimal digits):\n");

		char conf;
		char ckey[16];
		do {
			fgets(ckey, 16, stdin);
			printf("Set key no. 1? (Y/N)\n");
			conf = getchar();
		} while (conf == 'n' || conf == 'N');

		uint64_t key_1 = strtoull(ckey, NULL, 16);

		do {
			fgets(ckey, 16, stdin);
			printf("Set key no. 2? (Y/N)\n");
			conf = getchar();
		} while (conf == 'n' || conf == 'N');

		uint64_t key_2 = strtoull(ckey, NULL, 16);

		do {
			fgets(ckey, 16, stdin);
			printf("Set key no. 3? (Y/N)\n");
			conf = getchar();
		} while (conf == 'n' || conf == 'N');

		uint64_t key_3 = strtoull(ckey, NULL, 16);

		printf("Please enter the plaintext you wish to encrypt\n");
		printf("(max. 256 characters9:\n");

		char* plaintext;
		do {
			fgets(plaintext, 256, stdin);
			printf("Set plaintext? (Y/N)\n");
			conf = getchar();
		} while (conf == 'n' || conf == 'N');

		uint64_t* ciphertext = encrypt_TDEA_ECB(charTo64bitNum(plaintext),
			key_1, key_2, key_3);

		printf("Encrypted plaintext:\n");
		printf("\n");


	} while (input != 'b' && input != 'B');
}

/*
void displayVigenereMenu() {
	char input;
	do {

	} while (input != 'b' && input != 'B');
}
*/