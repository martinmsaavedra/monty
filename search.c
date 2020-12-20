#include "monty.h"


int search_opcode(char *token, unsigned int line_n, stack_s **head)
{
	instruction_t options[] = { {"pall", f_pall},{"push", f_push}, {NULL, NULL} };
	int i = 0;
	while(options[i].opcode != NULL)
	{
		if (strcmp(options[i].opcode, token) == 0)
		{
			options[i].f(head, line_n);
			return(1);
		}
		i++;
	}
	return (0);
}

void f_push(stack_s **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
/*	stack_s *node;*/
/*	node = new_node(stack);*/
	printf("El comando es un push y el number es %d\n",number);
}
void f_pall(stack_s **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	printf("es un pall\n");
}

/*
stack_s *new_node(stack_s **head)
{
	stack_s *new;

	new = (stack_s *)malloc(sizeof(stack_s *));
	if (new == NULL)
	{
		fprintf(stderr,"Error allocation");
		exit(EXIT_FAILURE);
	}
	new->n = number;
	new->next = NULL;
	if (head == NULL)
	{
		new->prev = NULL;
		*head = new;
	}
	else
		new->prev = *head;
	printf("se agrego el push a la cola con el numero:%d\n", new->n);
	return (new);
}*/
