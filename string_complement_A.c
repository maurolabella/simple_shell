#include "main.h"

/**
 * splitString - splits string into an array of strings
 * separated by spaces
 * @build: input build
 * Return: TRUE if able to split, FALSE if not
 */
int splitString(config *build)
{
	register unsigned int i = 0;
	char *tok, *cpy;

	if (countWords(build->buffer) == 0)
	{
		build->args = NULL;
		free(build->buffer);
		return (FALSE);
	}
	build->args = malloc((countWords(build->buffer) + 1) * sizeof(char *));
	cpy = _strdup(build->buffer);
	tok = _strtok(cpy, " ");
	while (tok)
	{
		build->args[i] = _strdup(tok);
		tok = _strtok(NULL, " ");
		i++;
	}
	build->args[i] = NULL;
	free(cpy);
	return (TRUE);
}

/**
 * countWords - count number of words in a string
 * @str: input string
 * Return: number of words
 */
unsigned int countWords(char *str)
{
	register int words = 0;
	int wordOn = FALSE;

	while (*str)
	{
		if (isSpace(*str) && wordOn)
			wordOn = FALSE;
		else if (!isSpace(*str) && !wordOn)
		{
			wordOn = TRUE;
			words++;
		}
		str++;
	}
	return (words);
}

/**
 * isSpace - determines if char is a space
 * @c: input char
 * Return: TRUE or FALSE
 */
int isSpace(char c)
{
	return (c == ' ');
}
