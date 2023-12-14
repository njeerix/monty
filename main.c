#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - Monty ByteCode Interpreter
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
unsigned int line_number = 0;
stack_t *stack = NULL;
char *line = NULL;
size_t len = 0;
FILE *file = fopen("bytecodes/00.m", "r");
if (file == NULL)
{
fprintf(stderr, "Error opening file.\n");
exit(EXIT_FAILURE);
}
while (getline(&line, &len, file) != -1)
{
push(&stack);
line_number++;
}
free(line);
fclose(file);
return (0);
}
/**
 * free_stack - frees the entire stack
 * @stack: Pointer to the beginning of the stack
 */
void free_stack(stack_t *stack)
{
stack_t *temp;
while (stack)
{
temp = stack;
stack = stack->next;
free(temp);
}
}
