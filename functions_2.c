#include "monty.h"

void f_nop(stack_s **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

void f_swap(stack_s **stack, unsigned int line_number)
{
    stack_s *aux;
    size_t len = 0;
    unsigned int temp;

    len = list_len(stack);

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	temp = aux->n;
	aux->n = aux->next->n;
	aux->next->n = temp;
}

size_t list_len(stack_s **h)
{
	size_t counter = 0;
	stack_s *aux;

	if (*h == NULL)
	{
		return (0);
	}
	aux = *h;

	while (aux)
	{
		aux = aux->next;
		counter++;
	}
	return (counter);
}

void f_add(stack_s **stack, unsigned int line_number)
{
    stack_s *temp_node;
    size_t len = 0;
    unsigned int temp;

    len = list_len(stack);

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n + (*stack)->next->n;
	temp_node = *stack;
	*stack = (*stack)->next;
	(*stack)->n = temp;
	free(temp_node);
}

void f_sub(stack_s **stack, unsigned int line_number)
{
    stack_s *temp_node;
    size_t len = 0;
    unsigned int temp;

    len = list_len(stack);

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next->n - (*stack)->n;
	temp_node = *stack;
	*stack = (*stack)->next;
	(*stack)->n = temp;
	free(temp_node);
}

void f_mul(stack_s **stack, unsigned int line_number)
{
    stack_s *temp_node;
    size_t len = 0;
    unsigned int temp;

    len = list_len(stack);

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next->n * (*stack)->n;
	temp_node = *stack;
	*stack = (*stack)->next;
	(*stack)->n = temp;
	free(temp_node);
}

void f_div(stack_s **stack, unsigned int line_number)
{
    stack_s *temp_node;
    size_t len = 0;
    unsigned int temp;

    len = list_len(stack);

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n != 0)
		temp = (*stack)->next->n / (*stack)->n;
	else
	{
        fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp_node = *stack;
	*stack = (*stack)->next;
	(*stack)->n = temp;
	free(temp_node);
}

void f_mod(stack_s **stack, unsigned int line_number)
{
	stack_s *temp_node;
	size_t len = 0;
	unsigned int temp;

	len = list_len(stack);
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
    if ((*stack)->n != 0)
        temp = (*stack)->next->n % (*stack)->n;
	else
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
    
	temp_node = *stack;
	*stack = (*stack)->next;
	(*stack)->n = temp;
	free(temp_node);
}

void f_rotl(stack_s **stack, unsigned int line_number)
{
	stack_s *aux, *new;
	unsigned int temp;
	int stack_len = 0;

	(void)line_number;
	stack_len = list_len(stack);
	if (*stack != NULL && stack_len >= 2)
	{
		new = malloc(sizeof(stack_s));
		if (!new)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
		aux = *stack;
		temp = aux->n;
		*stack = aux->next;
		free(aux);
		aux = *stack;
		while(aux->next)
			aux = aux->next;
		aux->next = new;
		new->n = temp;
		new->prev = aux;
		new->next = NULL;
	}
	return;
}

void f_rotr(stack_s **stack, unsigned int line_number)
{
	stack_s *aux;
	unsigned int temp, temp2;

	(void)line_number;
	if (*stack != NULL)
	{
		aux = *stack;
		temp = aux->n;
		while (aux->next)
			aux = aux->next;
		
		temp2 = aux->n;
		aux->n = temp;
		aux = *stack;
		aux->n = temp2;
	}
	return;
}