OBJ = InitialPermutation.o Main.o Selection.o ShiftCipher.o Vigenere.o
PATH = algorithms/symmetric/
PATH_DES = algorithms/symmetric/DES/

default: main

InitialPermutation.o: $(PATH_DES)InitialPermutation.c $(PATH_DES)InitialPermutation.h
	gcc -c $(PATH_DES)InitialPermutation.c

Main.o: Main.c
	gcc -c Main.c

Selection.o: $(PATH_DES)Selection.c $(PATH_DES)Selection.h
	gcc -c $(PATH_DES)Selection.c

ShiftCipher.o: $(PATH)ShiftCipher.c $(PATH)ShiftCipher.h
	gcc -c $(PATH)ShiftCipher.c

Vigenere.o: $(PATH)Vigenere.c $(PATH)Vigenere.h
	gcc -c $(PATH)Vigenere.c

main: $(OBJ)
	gcc -o main $(OBJ)

clean:
	rm -rf main $(OBJ)