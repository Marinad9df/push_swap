#include "../includes/push_swap.h"

static void print_instruction(char *instruction, char x)
{
    write(1, instruction, ft_strlen(instruction));
    write(1, &x, 1);
    write(1, "\n", 1);
}

void swap(t_stack *stack, char x, bool b)
{
    t_node *tmp;

    if (stack->head == NULL || stack->head->next == NULL)
        return;
    tmp = stack->head;
    stack->head = tmp->next;
    tmp->next = stack->head->next;
    stack->head->next = tmp;
    if (b)
        print_instruction("s", x);
}

void push(t_stack *stack1, t_stack *stack2, char x, bool b)
{
    int index;

    if (stack2->head == NULL)
        return;
    index = stack2->head->s_index;
    push_stack(stack1, index, pop_stack(stack2));
    if (b)
        print_instruction("p", x);
}

void rotate(t_stack *stack, char x, bool b)
{
    t_node *tmp;
    t_node *current;

    if (stack->head == NULL || stack->head->next == NULL)
        return;
    tmp = stack->head;
    stack->head = tmp->next;
    current = stack->head;
    while (current->next != NULL)
        current = current->next;
    current->next = tmp;
    tmp->next = NULL;
    if (b)
        print_instruction("r", x);
}

void reverse_rotate(t_stack *stack, char x, bool b)
{
    t_node *current;
    t_node *tmp;

    if (!stack->head || !stack->head->next || !stack)
        return;
    current = stack->head;
    while (current->next->next != NULL)
        current = current->next;
    tmp = current->next;
    current->next = NULL;
    tmp->next = stack->head;
    stack->head = tmp;
    if (b)
        print_instruction("rr", x);
}
