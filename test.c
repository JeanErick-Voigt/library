#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "polynomial.h"

void main ()
{
	double y = 3;
	polynomial * poly1 = NULL;
	polynomial * poly2 = NULL;
	polynomial * poly3 = NULL;
	term_create(1, 3, &poly1);
	term_create(5, 6, &poly1);
	term_create(1, 1, &poly2);
	term_create(5, 6, &poly2);
	term_create(2, 1, &poly3);
	term_create(2, 4, &poly3);
//	poly_print(poly1);
	printf("THIS IS POLY STRING---->\n");
	printf("%s\n", poly_to_string(poly1));
	printf("THIS IS THE BOOL---->\n");
	bool value = poly_equal(poly1, poly2);
	printf("%d\n", value);
	poly_equal(poly1, poly2);
	printf("THIS IS POLY EVAL\n");
	printf("sum %lf\n", poly_eval(poly1, y));
	triple(poly1);
	printf("The transform function next line: \n");
//	transform = triple;
	printf("THIS IS POLY ITERATE\n");
	poly_print(poly3);
	poly_iterate(poly3, triple);
	poly_print(poly3);

	//printf("This is poly_add\n");
//	polynomial *x = NULL;
	//poly_print(poly_add(poly1, poly2));
//	poly_print(x);
}
