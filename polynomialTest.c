#include <stdio.h>
#include <stdlib.h>

struct term {
	int coeff;
	unsigned int exp;
	struct term *next;
};

typedef struct term polynomial;


//struct poly expression
struct poly_expression{
	struct term *head;
	struct term *tail;
};

void initialize_poly(struct poly_expression *e)
{
	e->head = NULL;
	e->tail = NULL;
}

//combine terms
//void combine_terms(struct poly_expression *e, polynomial *term1)
//{
//	polynomial *terme = term_create(term1->coeff, term1->exp);
//	if(e->head == NULL){
//		e->head = terme;
//		e->tail = e->head;
//		next_link(terme,NULL);
//	}else{
//		next_link(e->tail,terme);
//		e->tail = terme;
//	}
//}

//set the next term for the link
void next_link(polynomial *initial_term, polynomial *next_term)
{
	initial_term->next = next_term;
}

//Create all the terms
polynomial *term_create(int coeff, unsigned int exp)
{
	polynomial *node = malloc(sizeof(polynomial));
	if (node){
		node->coeff = coeff;
		node->exp = exp;
		node->next = NULL;
	}
	return node;
}

void combine_terms(struct poly_expression *e, polynomial *term1)
{
	polynomial *terme = term_create(term1->coeff, term1->exp);
	if(e->head == NULL){
		e->head = terme;
		e->tail = e->head;
		next_link(terme, NULL);
	}else{
		next_link(e->tail, terme);
		e->tail = terme;
	}
}


//display terms
void Display(struct poly_expression *e)
{
	polynomial *p = e->head;
	if(p == NULL)
		printf("No members.\n");
	while(p != NULL)
	{
		printf("%d^%d", p->coeff, p->exp);
		p = p->next;
	}
}


void main ()
{
	struct poly_expression *expression;
	polynomial *TermA = term_create(1, 3);
	polynomial *TermB = term_create(5, 6); 

	//printf("%d\n", TermA->coeff);
	//printf("%d\n", TermA->exp);
	//printf("%d\n", TermB->coeff);
	initialize_poly(expression);
	combine_terms(expression, TermA);
	//Display(&expression); 

}
