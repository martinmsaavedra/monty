#include "monty.h"
#define TOKEN_DELIM " \t\n\r"
/* Number = global variable. */
int number = 0;
/**
 * main - Main function
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 in success, 1 in error
 **/
int main(int argc, char *argv[])
{
	FILE *stream;
	size_t len = 0;
	ssize_t nread;
	unsigned int line_n = 1;
	char *token = NULL, *token_2, *line = NULL;
	stack_s *head = NULL;
	int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((nread = getline(&line, &len, stream)) != -1)
	{
		while (line[0] == 32)
		{
			count++;
			line++;
		}

		if (line[0] == '\n' || line[0] == '\0')
			continue;
		token = strtok(line, TOKEN_DELIM);
		/*printf("%s\n", token);*/
		token_2 = strtok(NULL, TOKEN_DELIM);
		if (strcmp(token, "push") == 0)
			check_token(token_2, line_n);
		if (token && token[0] != '#')
			search_function(token, line_n, &head);
		line_n++;
	}
	for (; count > 0; count--)
		line--;
	free(line);
	free_stack(head);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
