#include "monty.h"

void check_token(char *token, unsigned int line_n)
{
    int i = 0, j;

    if (token)
    {
        for (; token[i] != '\0'; i++)
        {
            if (token[i] >= 48 && token[i] <= 57)
            {
                j = 0;
            }    
            else
            {
                j = 1;
            }
        }
        if (j == 0)
        {
            number = atoi(token);
            return;
        }
            
        else 
        {
            fprintf(stderr, "L%u: usage: push integer\n", line_n);
			exit(EXIT_FAILURE); 
        }
    }
    else
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_n);
		exit(EXIT_FAILURE); 
    }
    
    }