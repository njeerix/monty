#include "monty.h"
/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the head of the stack.
 */
void push(stack_t **stack)
{
int value = 0;
stack_t *new_node = malloc(sizeof(stack_t));
if (!new_node)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
new_node->n = value;
new_node->prev = NULL;
new_node->next = *stack;
if (*stack)
(*stack)->prev = new_node;
*stack = new_node;
}
/**
 * pall - prints all values on the stack.
 * @stack: pointer to the head of the stack.
 */
void pall(stack_t **stack)
{
stack_t *current = *stack;
while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}
