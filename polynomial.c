#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "polynomial.h"

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

void poly_iterate(polynomial *p, void(*transform)(struct term *p))
{
	while(p->next != NULL)
	{
		transform(p);
		p = p->next;
	}
}

void triple(struct term *p)
{
	
	while (p->next != NULL)
	{
		p->coeff *= 3;
		//printf("coeff %d", p->coeff);
		p = p->next;
	}
	//printf("\n");
}

polynomial *poly_add(const polynomial *a, const polynomial *b)
{
	polynomial *polySum = malloc(sizeof(polynomial));
	while(a->next != NULL && b->next != NULL)
	{	
		if(a->exp > b->exp)
		{
			polySum->exp = a->exp;
			polySum->coeff = a->coeff;
			a = a->next;
		}
		else if(a->exp < b->exp)
		{
			polySum->exp = b->exp;;
			polySum->coeff = a->coeff;
			a = a->next;
		}else{
			polySum->exp = b->exp;
			polySum->coeff = a->coeff + b->coeff;
			a = a->next;
			b = b->next;
		}
		polySum->next = malloc(sizeof(polynomial));
		polySum = polySum->next;
		polySum->next = NULL;
	}
	while(a->next != NULL || b->next != NULL)
	{
		if(a->next)
		{
			polySum->exp = a->exp;
			polySum->coeff = a->coeff;
			a = a->next;
		}
		if(b->next)
		{
			polySum->exp = b->exp;
			polySum->coeff = b->exp;
			b = b->next;
		}
		polySum->next = malloc (sizeof(polynomial));
		polySum = polySum->next;
		polySum->next = NULL;
	}
	return polySum;

}

