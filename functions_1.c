#include "monty.h"


int search_function(char *token, unsigned int line_n, stack_s **head)
{
	instruction_t options[] = { {"pall", f_pall}, {"push", f_push}, {"pint", f_pint}, {"pop", f_pop}, {"nop", f_nop}, {NULL, NULL} };
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
	stack_s *new = NULL;

	(void) line_number;
	if (!stack)
		exit(EXIT_FAILURE);

	new = malloc(sizeof(stack_s));
	if (!new)
		exit(EXIT_FAILURE);
	new->n = number;
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new;
	}

	*stack = new;
	return;
}


void f_pall(stack_s **stack, unsigned int line_number)
{
	stack_s *aux;

	(void) line_number;
	if (stack == NULL)
	{
		exit(EXIT_FAILURE);
	}
	aux = *stack;

	while (aux)
	{
		printf("%i\n", aux->n);
		aux = aux->next;
	}
	return;
}

void f_pint(stack_s **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%i\n", (*stack)->n);

	return;
}

void f_pop(stack_s **stack, unsigned int line_number)
{
	stack_s *aux;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	*stack = (*stack)->next;
	free(aux);
	return;
}