OBJ = Main.o ShiftCipher.o
PATH = algorithms/

default: main

Main.o: Main.c $(PATH)ShiftCipher.h
	gcc -c Main.c

ShiftCipher.o: $(PATH)ShiftCipher.c $(PATH)ShiftCipher.h
	gcc -c $(PATH)ShiftCipher.c

main: $(OBJ)
	gcc -o main $(OBJ)

clean:
	rm -rf $(OBJ)