#include "../includes/push_swap.h"

int get_min_index(t_stack *stack)
{
    t_node *current;
    int min_index;

    if (!stack || !stack->head)
        return (-1);
    current = stack->head;
    min_index = current->s_index;
    while (current)
    {
        if (current->s_index < min_index)
            min_index = current->s_index;
        current = current->next;
    }
    return (min_index);
}

int count_r(t_node *stack, int index)
{
    int counter;

    counter = 0;
    while (stack && stack->s_index != index)
    {
        stack = stack->next;
        counter++;
    }
    return (counter);
}

int is_sorted(t_stack *stack)
{
    t_node *tmp;

    if (!stack || !stack->head)
        return (1);
    tmp = stack->head;
    while (tmp->next)
    {
        if (tmp->data > tmp->next->data)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}
