#include "monty.h"

void free_stack(stack_s *head)
{
	stack_s *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(head);
}
