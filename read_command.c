#include "simple_shell.h"

/**
 * read_command - reads inputted command
 *
 * Description: function reads command
 *
 * Return: expected output
 */

char *read_command(void)
{
	char *line = NULL;
	size_t len = 0;

	if (getline(&line, &len, stdin) == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}

