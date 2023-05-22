#include "shell.h"

/**
 * _realloc - prints buffer in hexa
 * @ptr: pointer
 * @old_size: size old
 * @new_size: size new
 * Return: ptr
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return ('\0');
	}

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
		ptr = malloc(new_size);

	free(ptr);
	ptr = malloc(new_size);
	return (ptr);
}

/**
 * split_line - function to split the line with tokens
 * @buffer: Line of arguments
 * Return: tokens
 */

char **split_line(char *buffer)
{
	char *token, **tokens;
	int posicion = 0;

	tokens = malloc(TOK_BUFSIZE * sizeof(char *));
	if (tokens == NULL)
	{
		free(tokens);
		perror("Error creating malloc");
		exit(98);
	}
	token = strtok(buffer, " ");
	while (token != NULL)
	{
		tokens[posicion] = token;
		posicion++;
		if (!tokens)
		{
			free(tokens);
			perror("Error in realloc");
			exit(98);
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[posicion] = NULL;
	return (tokens);
}


/**
 * split_line_path - function to split the line with tokens
 * @buffer: Line of arguments
 * Return: tokens
 */

char **split_line_path(char *buffer)
{
	char *token, **tokens, *equal;
	int posicion = 0;

	tokens = malloc(TOK_BUFSIZE * sizeof(char *));
	if (tokens == NULL)
	{
		perror("Error creating malloc");
		return (NULL);
	}
	equal = strtok(buffer, "=");
	equal = strtok(NULL, "=");
	token = strtok(equal, ":");
	while (token != NULL)
	{
		tokens[posicion] = malloc((TOK_BUFSIZE * sizeof(char *)));
		tokens[posicion] = token;
		posicion++;
		token = strtok(NULL, ":");
	}
	tokens[posicion] = NULL;
	return (tokens);
}
