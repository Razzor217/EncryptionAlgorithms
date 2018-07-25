OBJ = Main.o ShiftCipher.o Vigenere.o
PATH = algorithms/

default: main

Main.o: Main.c $(PATH)ShiftCipher.h
	gcc -c Main.c

ShiftCipher.o: $(PATH)ShiftCipher.c $(PATH)ShiftCipher.h
	gcc -c $(PATH)ShiftCipher.c

Vigenere.o: $(PATH)Vigenere.c $(PATH)Vigenere.h
	gcc -c $(PATH)Vigenere.c

main: $(OBJ)
	gcc -o main $(OBJ)

clean:
	rm -rf main $(OBJ)