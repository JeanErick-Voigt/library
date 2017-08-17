#include <stdio.h>
#include <stdlib.h>

struct term {
	int coeff;
	unsigned int exp;
	struct term *next;
};

typedef struct term polynomial;

void term_create(int coeff, unsigned int exp, polynomial ** e)
{
	struct term *node = malloc(sizeof(polynomial));
	struct term *current = malloc(sizeof(polynomial));
	struct term  current = *e;
	if(node){
		node->coeff = coeff;
		node->exp = exp;
	}
	if(current == NULL){
		//struct term *current = malloc(sizeof(polynomial));
		//current->coeff = coeff;
		//current->exp = exp;
		current->coeff = coeff;
		current->exp = exp;
		*e = current;


	while(current->next != NULL){
		current = current->next;
	}

	//current->next = malloc(sizeof(polynomial));
	//current = current->next;
	//*e = current;
	current->coeff = current;
	current->exp = current;
	current->next = NULL

}

void main()
{
	struct term *expression = NULL; 
	term_create(5, 2, expression);
}



