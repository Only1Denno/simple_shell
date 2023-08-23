#include "simple_shell.h"

/**
 * env_builtin - implements builtin env command
 * @custom_environ: array of character strings
 * with environment variables
 *
 * Return: expected output
 */
void env_builtin(char *custom_environ[])
{
	int i = 0;

	while (custom_environ[i] != NULL)
	{
		write(STDOUT_FILENO, custom_environ[i], strlen(custom_environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
