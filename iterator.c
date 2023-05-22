#include "shell.h"

/**
 * loop_shell - main function
 * Return: Always 0.
 */
int loop_shell(void)
{
	char **arguments, *buffer, *getp, **argpath;
	int execute, i = 0;
	size_t bufsize = TOK_BUFSIZE, num_size;

	do {
		write(0, "$ ", 2);
		signal(SIGINT, signalc);
		buffer = malloc(bufsize * sizeof(char));
		if (buffer == NULL)
			retu(buffer);
		num_size = getline(&buffer, &bufsize, stdin);
		buffer[num_size - 1] = '\0';
		arguments = split_line(buffer);
		getp = getpath("PATH=");
		argpath = malloc(bufsize * sizeof(char));
		if (argpath == NULL)
			retu(*argpath);
		argpath = split_line_path(getp);
		for (i = 0; argpath[i] != '\0'; i++)
		{
			argpath[i] = _strcat(argpath[i], "/");
			argpath[i] = _strcat(argpath[i], buffer);
			if (stat_arguments(argpath[i]) == 0)
				execute = execute_arguments(argpath[i]);
		}
		free(buffer);
		free(arguments);
		free(argpath);
	} while (execute);
	return (0);
}
