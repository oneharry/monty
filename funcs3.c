#include "monty.h"
/**
  * mul - multiply top 2 elements
  * @stack: stack
  * @number: line number
  * Return: void
  */
void mul(stack_t **stack, unsigned int number)
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
  * div_monty - divides 2nd by top element
  * @stack: stack
  * @number: line number
  * Return: void
  */
void div_monty(stack_t **stack, unsigned int number)
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
  * mod - modulus of top 2 elements
  * @stack: stack
  * @number: line number
  * Return: void
  */
void mod(stack_t **stack, unsigned int number)
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
	(*stack)->n = (b % a);
	free(first);
}
/**
  * comments - handle comments
  * @stack: stack
  * @number: number of lines
  * Return: void
  */
void comments(stack_t **stack, unsigned int number)
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
