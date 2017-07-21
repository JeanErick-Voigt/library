#include <stdio.h>
#include <stdlib.h>

struct term {
	int coeff;
	unsigned int exp;
	struct term *next;
};

typedef struct term polynomial;

void term_create(int coeff, unsigned int exp, polynomial **eqPtr)
{
	polynomial *currentNode, *temp; 
	temp = *eqPtr;
	if (temp == NULL){
		currentNode = malloc(sizeof(polynomial));
		currentNode->coeff = coeff;
		currentNode->exp = exp;
		*eqPtr = currentNode;
		currentNode->next = malloc(sizeof(polynomial));
		currentNode = currentNode->next;
		currentNode->next = NULL;
	}else{
		//struct term *node = malloc(sizeof(struct term));
		currentNode->coeff = coeff;
		currentNode->exp = exp;
		currentNode->next = malloc(sizeof(struct term));
		currentNode = currentNode->next;
		currentNode->next = NULL;
	}
}

void poly_print(polynomial *eqn)
{
	if(!eqn){
		return;
	}
	while(eqn->next != NULL)
	{
		printf("%dx^%d", eqn->coeff, eqn->exp);
		eqn = eqn->next;
		if(eqn->next != NULL){
			printf(" + ");
		}
	}
}

void main ()
{
	polynomial * poly1 = NULL;
	term_create(1, 3, &poly1);
	term_create(5, 6, &poly1);
	poly_print(poly1);
}
