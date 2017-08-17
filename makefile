all: polynomial
	gcc -c polynomial.c -o polynomial.o -lm

polynomial: polynomial.c
	gcc -c polynomial.c -o polynomial.o -lm

test: test.c polynomial
	gcc polynomial.o test.c -o test -lm

clean:
	rm -f polynomial.o test
