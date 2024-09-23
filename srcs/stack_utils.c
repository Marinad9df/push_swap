#include "../includes/push_swap.h"
#include <stdio.h>  // For printf in debug functions

int push_stack(t_stack *stack, int index, int data)
{
    t_node *new_node;

    if (!stack)
        return (0);
    new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return (0);
    new_node->data = data;
    new_node->s_index = index;
    new_node->next = stack->head;
    stack->head = new_node;
    stack->size++;
    return (1);
}

int pop_stack(t_stack *stack)
{
    t_node *top;
    int data;

    if (!stack || !stack->head)
        return (INT_MIN);  // Using INT_MIN to indicate error
    top = stack->head;
    data = top->data;
    stack->head = top->next;
    free(top);
    stack->size--;
    return (data);
}

void free_stack(t_stack *stack)
{
    t_node *current;
    t_node *next;

    if (!stack)
        return;
    current = stack->head;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    stack->head = NULL;
    stack->size = 0;
}

int is_stack_empty(t_stack *stack)
{
    return (!stack || stack->size == 0);
}

int get_stack_size(t_stack *stack)
{
    return (stack ? stack->size : 0);
}

void print_stack(t_stack *stack, char stack_name)
{
    t_node *current;

    if (!stack)
        return;
    current = stack->head;
    printf("Stack %c: ", stack_name);
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void debug_print(t_stack *stack_a, t_stack *stack_b, char *operation)
{
    printf("After %s:\n", operation);
    print_stack(stack_a, 'A');
    print_stack(stack_b, 'B');
    printf("\n");
}
