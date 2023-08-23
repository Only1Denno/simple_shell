#include "simple_shell.h"

/**
 * execute_command - Executes command with execve
 * @command: Command for execution
 * @custom_environ: Array of character
 * string with environment variables
 * Return: 0 on success and -1 on failure
 */
int execute_command(char *command, char *custom_environ[])
{
	pid_t child_pid;
	int status;

	char *full_command = find_command(command, custom_environ);
	char error_message[] = "execve error\n";

	if (full_command == NULL)
	{

		write(STDOUT_FILENO, error_message, sizeof(error_message) - 1);
		return (-1);
	}

	child_pid = fork();

	if (child_pid == -1)
	{

		write(STDOUT_FILENO, error_message, sizeof(error_message) - 1);
		return (-1);
	}
	if (child_pid == 0)
	{
		char *args[3];

		args[0] = full_command;
		args[1] = NULL;
		args[2] = NULL;

		execve(args[0], args, custom_environ);

		write(STDOUT_FILENO, error_message, sizeof(error_message) - 1);
		_exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(child_pid, &status, 0);
		return (0);
	}
}

