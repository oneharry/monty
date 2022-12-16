#include "monty.h"
/**
  * handle_commands - handles spaces and tokenize commands
  * @line: command line
  * Return: pointer to array of strings
  */
char **handle_commands(char *line)
{
	const char *del = " \n";
	char *token;
	char **cmd;

	cmd = malloc(sizeof(char *) * 4);
	if (cmd == NULL)
		return (NULL);
	token = strtok(line, del);
	cmd[0] = token;
	while (token)
	{
		token = strtok(NULL, del);
		cmd[1] = token;
		break;
	}
	cmd[3] = NULL;
	return (cmd);
}


/**
  * run_command - returns a pointer for a command
  * @command: command
  * Return: pointer to a function
  */
void (*run_command(char *command)) (stack_t **, unsigned int)
{
	 instruction_t myFuncs[] = {
		 {"push", push},
		 {"pall", pall},
		 {"pint", pint},
		 {"pop", pop},
		 {"swap", swap},
		 {"add", add},
		 {"nop", nop},
		 {"sub", sub},
		 {"mul", mul},
		 {"div", div_monty},
		 {"mod", mod},
		 {NULL, NULL}
	 };
	int i;

	for (i = 0; myFuncs[i].opcode; i++)
	{
		if (strcmp(command, myFuncs[i].opcode) == 0)
		{
			return (myFuncs[i].f);
		}
	}
	return (NULL);
}

/**
  * handle_arg - takes care of arguments of opcodes
  * @str: argument
  * @line_number: line number
  * Return: the number argument
  */

int handle_arg(char *str, unsigned int line_number)
{
	int i = 0;

	if (str == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (str[0] == '-')
		i = 1;
	for (; str[i] != 0; i++)
	{
		if (!isdigit(str[i]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (atoi(str));

}
