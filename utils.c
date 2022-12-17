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
  * @str: line
  * Return: 1 or 0
  */
int skip_line(char *str)
{
	if (str[0] == '\n' || str[0] == '#')
		return (1);
	return (0);
}
