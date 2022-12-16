#include "monty.h"
/**
  * swap - swap top 2 elements
  * @stack: stack
  * @number: line number
  * Return: void
  */
void swap(stack_t **stack, unsigned int number)
{
	int a, len = 0;
	stack_t *temp, *second;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	second = temp->next;
	a = temp->n;
	temp->n = second->n;
	second->n = a;
}

/**
  * nop - doesnt do anything
  * @stack: stack
  * @number: line number
  * Return: void
  */
void nop(stack_t __attribute__((__unused__)) **stack, unsigned int number)
{
	(void)number;
}

/**
  * add - add the top 2 elements
  * @stack: stack
  * @number: line number
  * Return: void
  */
void add(stack_t __attribute__((__unused__)) **stack, unsigned int number)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->next;
	a = first->n;
	b = second->n;
	*stack = second;
	(*stack)->n = a + b;
	free(first);
}
/**
  * sub - find the difference between the 2 top element
  * @stack: stack
  * @number: number of lines
  * Return: void
  */
void sub(stack_t **stack, unsigned int number)
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
