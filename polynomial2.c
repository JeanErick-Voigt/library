#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

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
	puts("\n");
}

char *poly_to_string(const polynomial *p)
{
	char * str = malloc(sizeof(polynomial) * (sizeof(char*)) + 4);
	char *buffer;
	char *sign = " + ";
	while(p->next != NULL)
	{
		sprintf(buffer, "%dx^%d", p->coeff, p->exp);
		strcat(str, buffer);
		p = p->next;
		if(p -> next != NULL){
			strcat(str, sign);
		}
	}
	free(buffer);
	return str;
	
}

bool poly_equal(const polynomial *a, const polynomial *b)
{
	bool val = true;
	while(a->next != NULL  || b->next != NULL)
	{
		if((a->coeff == b->coeff) && (a->exp == b->exp)){
			val = true;  //printf("%d and b coeff is %d\n", a->coeff, b->coeff);
		}else{
			val = false;
			break;
		}
		a = a->next;
		b = b->next;
	}
	return val;
}

double poly_eval(const polynomial *p, double x)
{
	double raised; 
	int num;
	double sum = 0.0;
	while(p->next != NULL)
	{
		if(p->exp > 0){
			raised = (double) p->exp;
		}
		num = p->coeff;
		p = p->next;
		sum += (num*(pow(x, raised)));
	}
	return sum;
}

void main ()
{
	double y = 3;
	polynomial * poly1 = NULL;
	polynomial * poly2 = NULL;
	term_create(1, 3, &poly1);
	term_create(5, 6, &poly1);
	term_create(1, 3, &poly2);
	term_create(5, 6, &poly2);
	poly_print(poly1);
	printf("%s\n", poly_to_string(poly1));
	//bool value = true;
	bool value = poly_equal(poly1, poly2);
	printf("%d\n", value);
	//poly_equal(poly1, poly2);
	printf("sum %lf\n", poly_eval(poly1, y));
}
