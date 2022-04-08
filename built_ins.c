#include "main.h"

/**
 * findBuiltIns - validates if command is builtin and executes
 * @cart: input cart
 * Return: TRUE if found, FALSE if not
 */
int findBuiltIns(config *cart)
{
	register int i = 0;
	type_b BuiltIns[] = {
			{"exit", exitFunc},
			{"env", envFunc},
			{"history", historyFunc},
			{"alias", aliasFunc},
			{"cd", cdFunc},
			{"setenv", setenvFunc},
			{"unsetenv", unsetenvFunc},
			{"help", helpFunc},
			{NULL, NULL}};

	while (BuiltIns[i].command)
	{
		if (_strcmp(cart->args[0], BuiltIns[i].command) == 0)
		{
			BuiltIns[i].func(cart);
			freeArgsAndBuffer(cart);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

/**
 * exitFunc - exits the application
 * @cart: input cart
 * Return: 1 on success, 0 on failure
 */
int exitFunc(config *cart)
{
	register int argCount, exitStatus;

	argCount = countArgs(cart->args);
	if (argCount == 1)
	{
		freeMembers(cart);
		if (cart->errorStatus)
			exit(cart->errorStatus);
		exit(EXIT_SUCCESS);
	}
	else if (argCount > 1)
	{
		exitStatus = _atoi(cart->args[1]);
		if (exitStatus == -1)
		{
			errno = EILLEGAL;
			cart->errorStatus = 2;
			errorHandler(cart);
			return (0);
		}
		freeMembers(cart);
		exit(exitStatus);
	}
	return (1);
}

/**
 * historyFunc - displays command history
 * @cart: input cart
 * Return: 1 on success, 0 on failure
 */
int historyFunc(config *cart)
{
	char *str = "Currently in development\n";

	(void)cart;
	write(STDOUT_FILENO, str, _strlen(str));
	return (1);
}

/**
 * aliasFunc - displays local aliases
 * @cart: input cart
 * Return: 1 on success, 0 on failure
 */
int aliasFunc(config *cart)
{
	char *str = "Currently in development\n";

	(void)cart;
	write(STDOUT_FILENO, str, _strlen(str));
	return (1);
}
