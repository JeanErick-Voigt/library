#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char *poly_to_string(const polynomial *p)
{
	//polynomial *currentNode;
	char * str = "\0";
	char * buffer;
	char *sign = "+";
	str = malloc(sizeof(polynomial) *(sizeof(char*)) + 4);
//	while(p->next != NULL)
//	{
//		sprintf(buffer, 
//	}
	sprintf(buffer, "%dx^%d", p->coeff, p->exp);
	strcat(str, buffer);
	//buffer = "\0";
	p = p->next;
	sprintf(buffer,"%dx^%d", p->coeff, p->exp);
	strcat(str, buffer);
	//sprintf(buffer, "%dx^%d", p->coeff, p->exp);
	//strcat(str, buffer);
	

	//while(p->next != NULL)
	//{
	//	buffer = malloc(sizeof(polynomial) + 4);
	//	sprintf(buffer, "%dx^%d", p->coeff, p->exp);
	//	strcat(str, buffer);
	//	buffer = "\0";
	//	if(p->next != NULL)
	//	{
			//buffer = malloc
	//		sprintf(buffer, " %s ", sign);
	//		strcat(str, buffer); 
	//	} 
	//}
	free(buffer);
	return str;
	
}

void main ()
{
	polynomial * poly1 = NULL;
	term_create(1, 3, &poly1);
	term_create(3, 6, &poly1);
	term_create(2, 8, &poly1);
	poly_print(poly1);
	printf("%s", poly_to_string(poly1));
}
