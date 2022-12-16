#include "monty.h"
/**
  * arg_err - printss error for incomplete program usage argument
  *
  * Return: void
  */
void arg_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
