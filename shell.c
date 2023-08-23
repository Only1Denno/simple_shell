#include "simple_shell.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

/**
 * main - Entry of simple shell program
 * Description: function displays prompt to user
 * and executes command
 * the displays new line
 *
 * Return: Always 0.
 */
int main(void)
{
	char *command;

	while (1)
	{
		char *environ[] = {NULL};

		display_prompt(); /* Display the prompt */
		command = read_command(); /* Read user input */

		if (!command) /* Handle end of file condition (Ctrl+D) */
			break;

		execute_command(command, environ); /* Execute the command */

		free(command); /* Free allocated memory */
	}

	return (0);
}
/**
 * display_prompt - Displays expected prompt
 */
void display_prompt(void)
{
	char prompt[] = "$ "; /* Prompt string */

	write(1, prompt, sizeof(prompt) - 1); /* Write prompt to stdout */
}

/**
 * read_command - Reads command given
 * Return: Pointer to allocated string or NULL
 */
char *read_command(void)
{
	char *line = NULL;
	size_t len = 0;

	if (getline(&line, &len, stdin) == -1) /* Read user input */
	{
		free(line); /* Free allocated memory */
		return (NULL);
	}

	return (line);
}

/**
 * execute_command - Execute a command with execve
 * @command: command to be executed
 * @custom_environ: array of character strings
 * with environment variables
 * Return: 0 on success and -1 on failure
 */
int execute_command(char *command, char *custom_environ[])
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		return (-1);
	}
	if (child_pid == 0) /* Child process */
	{
		char *args[2];

		args[0] = command;
		args[1] = NULL;

		execve(command, args, custom_environ);
		perror("./hsh");
		_exit(EXIT_FAILURE); /* Use _exit to avoid flushing buffers */
	}
	else /* Parent process */
	{
		waitpid(child_pid, &status, 0);
		return (0); /* Return success code */
	}
}

