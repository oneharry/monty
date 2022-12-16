#include "monty.h"
/**
  * pchar - prints the char at the top
  * @stack: stack
  * @number: line number
  * Return: void
  */
void pchar(stack_t **stack, unsigned int number)
{
	int a, b, len = 0;
	stack_t *temp, *first, *second;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->next;
	a = first->n;
	b = second->n;
	free(first);
	*stack = second;
	(*stack)->n = (a * b);
}

/**
  * pstr - prints the string from top
  * @stack: stack
  * @number: line number
  * Return: void
  */
void pstr(stack_t **stack, unsigned int number)
{
	int a, b, len = 0;
	stack_t *temp, *first, *second;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", number);
		 exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->next;
	a = first->n;
	b = second->n;
	free(first);
	*stack = second;
	(*stack)->n = (b / a);
}

/**
  * rotl - rotate the list, set the first el to be the last
  * @stack: stack
  * @number: line number
  * Return: void
  */
void rotl(stack_t **stack, unsigned int number)
{
	stack_t *temp, *first, *second;
	int a, b, len = 0;

	temp = *stack;

	while (temp)
	{
		temp = temp->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->next;
	a = first->n;
	b = second->n;
	*stack = second;
	(*stack)->n = (a % b);
	free(first);
}
/**
  * rotr - rotates the stack to the bottom
  * @stack: stack
  * @number: number of lines
  * Return: void
  */
void rotr(stack_t **stack, unsigned int number)
{
	stack_t *temp, *first, *second;
	int a, b, len = 0;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", number);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = (*stack)->next;
	a = first->n;
	b = second->n;
	free(first);
	*stack = second;
	(*stack)->n = (b - a);
}
