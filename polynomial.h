//#include <stdlib.h>
#include <stdbool.h>

//header file for polynomial.  Includes prototypes for functions.

struct term {
	int coeff;
	unsigned int exp;
	struct term *next;
};
typedef struct term polynomial;

void term_create(int coeff, unsigned int exp, polynomial **eqPtr);
void poly_print(polynomial *eqn);
char *poly_to_string(const polynomial *p);
bool poly_equal(const polynomial *a, const polynomial *b);
double poly_eval(const polynomial *p, double x);
void poly_iterate(polynomial *p, void(*transform)(struct term *));
void triple(struct term *p);

