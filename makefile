OBJ = ShiftCipher.o
PATH = algorithms/

#default: main

ShiftCipher.o: $(PATH)ShiftCipher.c
	gcc -c $(PATH)ShiftCipher.c

clean:
	rm -rf $(OBJ)