#include "monty.h"
/**
  * pchar - prints the char at the top
  * @stack: stack
  * @number: line number
  * Return: void
  */
void pchar(stack_t **stack, unsigned int number)
{
	int n;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	if ((n < 65 || n > 122) && (n > 90 || n < 97))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", n);
}

/**
  * pstr - prints the string from top
  * @stack: stack
  * @number: line number
  * Return: void
  */
void pstr(stack_t **stack, unsigned int number)
{
	int n;
	stack_t *temp = *stack;

	(void)number;
	while (temp && (temp->n != 0))
	{
		n = temp->n;
		if ((n < 65 || n > 122) && (n > 90 || n < 97))
			break;
		printf("%c", n);
		temp = temp->next;
	}
	printf("\n");
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

	(void)number;
	temp = *stack;
	first = *stack;
	if (temp)
		second = (*stack)->next;
	if (temp && temp->next != NULL)
	{
		while (temp)
		{
			if (temp->next == NULL)
			{
				*stack = second;
				first->next = NULL;
				temp->next = first;
				break;
			}
			temp = temp->next;
		}
	}
}
/**
  * rotr - rotates the stack to the bottom
  * @stack: stack
  * @number: number of lines
  * Return: void
  */
void rotr(stack_t **stack, unsigned int number)
{
	stack_t *temp, *head = *stack;

	(void)number;
	while (head)
	{

		temp = head->prev;
		head->prev = head->next;
		head->next = temp;
		head = head->prev;
	}
	if (head)
		*stack = temp->prev;
}
