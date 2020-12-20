#include "monty.h"
#define TOKEN_DELIM " \t\n\r"
int number = 0;

int main(int argc, char *argv[])
{
	FILE *stream;
	size_t len = 0;
	ssize_t nread;
	unsigned int line_n = 0;
	char *token = NULL, *token_2, *line = NULL;
	stack_s *head = NULL;
    
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{ 
		fprintf(stderr, "Error: Can't open file<%s>\n", argv[0]);
        exit(EXIT_FAILURE);
	}
	while ((nread = getline(&line, &len, stream)) != -1)
	{
		while (line[0] == 32)
		{
			line++;
		}
		if (line[0] == '\0')
		{
			break;
		}
		token = strtok(line, TOKEN_DELIM);
		token_2 = strtok(NULL, TOKEN_DELIM);
		if (token_2 != NULL)
			number = atoi(token_2);
		search_function(token, line_n, &head);
		line_n++;
	}
	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
