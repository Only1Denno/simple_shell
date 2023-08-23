#include "simple_shell.h"

/**
 * find_command - finds command
 * @custom_environ: array to string
 *
 * Return: return expected output
 */
char *find_command(char *command, char *custom_environ[])
{
	char *path = NULL;
	char *token = NULL;
	char *path_copy = NULL;

	int i = 0;

	while (custom_environ[i] != NULL)
	{
		if (strncmp(custom_environ[i], "PATH=", 5) == 0)
		{
			path = custom_environ[i] + 5;
			break;
		}
		i++;
	}

	if (path == NULL)
		return (NULL);

	path_copy = strdup(path);
	if (path_copy == NULL)
		return (NULL);

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		char *full_path = malloc(strlen(token) + strlen(command) + 2);

		if (full_path != NULL)
		{
			sprintf(full_path, "%s/%s", token, command);
			if (access(full_path, F_OK) == 0)
			{
				free(path_copy);
				return (full_path);
			}
			free(full_path);
		}
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}

