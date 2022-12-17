#include "monty.h"
/**
  * free_tokens - free memory
  * @tok: pointer to array
  * Return: void
  */
void free_tokens(char **tok)
{
	int i;

	for (i = 0; tok[i]; i++)
	{
		free(tok[i]);
	}
}

/**
  * free_stack - frees stack
  * @stack: linked list
  * Return: void
  */
void free_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
/**
  * skip_line - checks for # comment or empty line
  * @line: line
  * Return: 1 or 0
  */
int skip_line(char *line)
{
	int i = 0;

	while (line[i] == ' ')
	{
		i++;
		continue;
	}
	if (line[i] == '\n' || line[i] == '#')
		return (1);
	return (0);
}
/**
  * printchar - convert ascii value to character
  * @n: ascii value
  * Return: character
  */
char printchar(int n)
{
	(void)n;
	return (0);
}
