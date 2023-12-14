#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack
 * @n: integer
 * @prev: points to the previous element of the stack
 * @next: points to the next element of the stack
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
}
stack_t;
/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the head of the stack.
 * @value: Integer value to be pushed.
 */
void push(stack_t **stack, int value)
{
stack_t *new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
new_node->n = value;
new_node->prev = NULL;
new_node->next = *stack;
if (*stack != NULL)
{
(*stack)->prev = new_node;
}
*stack = new_node;
fprintf(stderr, "Debug: Pushed %d onto the stack\n", value);
}
/**
 * pall - prints all values on the stack.
 * @stack: pointer to the head of the stack.
 */
void pall(stack_t *stack)
{
while (stack != NULL)
{
printf("%d\n", stack->n);
stack = stack->next;
}
fprintf(stderr, "Debug: Finished printing stack\n");
}
void free_stack(stack_t *stack)
{
while (stack != NULL)
{
stack_t *temp = stack;
stack = stack->next;
free(temp);
}
}
int main(int argc, char *argv[])
{
FILE *file;
stack_t *stack = NULL;
char opcode[10];
int value;
unsigned int line_number = 0;
if (argc != 2)
{
fprintf(stderr, "USAGE: %s file\n", argv[0]);
exit(EXIT_FAILURE);
}
file = fopen(argv[1], "r");
if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
while (fscanf(file, "%s", opcode) != EOF)
{
line_number++;
if (strcmp(opcode, "push") == 0)
{
if (fscanf(file, "%d", &value) != 1)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
push(&stack, value);
}
else if (strcmp(opcode, "pall") == 0)
{
pall(stack);
}
else
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
exit(EXIT_FAILURE);
}
}
fclose(file);
free_stack(stack);
return (0);
}
