#define _GNU_SOURCE_
#include "monty.h"
#include <unistd.h>
int num = 0;
/**
  * main - entry point into the program
  * @ac: number of arguments
  * @av: pointer to command line args
  * Return: 0 for success
  */
int main(int ac, char **av)
{
	const char *file_name;
	char *command;
	FILE *fd;
	char line[256];
	char **cmd;
	int line_number = 0;
	void (*fptr)(stack_t **, unsigned int);
	stack_t *head = NULL;

	if (ac != 2)
		arg_err();
	file_name = av[1];
	fd = fopen(file_name, "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), fd) != 0)
	{
		line_number++;
		if (skip_line(line))
			continue;
		command = strtok(line, "\t\n");
		cmd = handle_commands(command);
		if (strcmp(cmd[0], "push") == 0)
			num = handle_arg(cmd[1], line_number);
		fptr = run_command(cmd[0]);
		if (fptr == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cmd[0]);
			exit(EXIT_FAILURE);
		}
		fptr(&head, line_number);
		free(cmd);
	}
	fclose(fd);
	free_stack(&head);
	return (0);
}
