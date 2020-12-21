#include "monty.h"

void f_nop(stack_s **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;

    return;
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
	return;
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
	return;
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
	return;
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
	return;
}

void f_div(stack_s **stack, unsigned int line_number)
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
	return;
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
	return;
}
