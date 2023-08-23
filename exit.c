#include "simple_shell.h"
#include <stdlib.h>

/**
 * exit_builtin - Implements builtin command
 * Description: exits the shell
 */
void exit_builtin(void)
{
	/* no argument passed */
	_exit(EXIT_SUCCESS);
}
