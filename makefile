OBJ = Expansion.o Feistel.o InitialPermutation.o KeyPermutation.o KeySchedule.o \
	Permutation.o Selection.o ShiftCipher.o Vigenere.o Main.o
PATH = algorithms/symmetric/
PATH_DES = algorithms/symmetric/DES/

default: main

Expansion.o: $(PATH_DES)Expansion.c $(PATH_DES)Expansion.h
	gcc -c $(PATH_DES)Expansion.c

Feistel.o: $(PATH_DES)Feistel.c $(PATH_DES)Feistel.h
	gcc -c $(PATH_DES)Feistel.c

InitialPermutation.o: $(PATH_DES)InitialPermutation.c $(PATH_DES)InitialPermutation.h
	gcc -c $(PATH_DES)InitialPermutation.c

KeyPermutation.o: $(PATH_DES)KeyPermutation.c $(PATH_DES)KeyPermutation.h
	gcc -c $(PATH_DES)KeyPermutation.c

KeySchedule.o: $(PATH_DES)KeySchedule.c $(PATH_DES)KeySchedule.h
	gcc -c $(PATH_DES)KeySchedule.c

Permutation.o: $(PATH_DES)Permutation.o $(PATH_DES)Permutation.h
	gcc -c $(PATH_DES)Permutation.c

Selection.o: $(PATH_DES)Selection.c $(PATH_DES)Selection.h
	gcc -c $(PATH_DES)Selection.c

ShiftCipher.o: $(PATH)ShiftCipher.c $(PATH)ShiftCipher.h
	gcc -c $(PATH)ShiftCipher.c

Vigenere.o: $(PATH)Vigenere.c $(PATH)Vigenere.h
	gcc -c $(PATH)Vigenere.c

Main.o: Main.c
	gcc -c Main.c

main: $(OBJ)
	gcc -o main $(OBJ)

clean:
	rm -rf main $(OBJ)