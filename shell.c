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

	write(STDOUT_FILENO, prompt, sizeof(prompt) - 1); /* Write prompt to stdout */
}
