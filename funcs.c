#include "monty.h"
/**
  * push - push to end of stack
  * @stack: stack
  * @number: line number
  * Return: void
  */
void push(stack_t **stack, unsigned int __attribute__((__unused__)) number)
{

	stack_t *new, *temp = *stack;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = num;
	if (temp == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
	} else
	{
		new->prev = NULL;
		new->next = temp;
		temp->prev = new;
		*stack = new;
	}

}
/**
  * pall - display
  * @stack: stack
  * @number: line number
  * Return: void
  */
void pall(stack_t **stack, unsigned int __attribute__((__unused__)) number)
{
	stack_t *temp = *stack;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
  * pop - pop from end of stack
  * @stack: stack
  * @number: line number
  * Return: void
  */
void pop(stack_t **stack, unsigned int number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", number);
		exit(EXIT_FAILURE);
	} else
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
/**
  * pint - print element at end of stack
  * @stack: stack
  * @number: line number
  * Return: void
  */
void pint(stack_t **stack, unsigned int number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", number);
		exit(EXIT_FAILURE);
	} else
	{
		printf("%d\n", temp->n);
	}
}
