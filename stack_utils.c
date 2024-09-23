#include "../includes/push_swap.h"

int	push_stack(t_stack *stack, int index, int data)
{
	t_node	*new_node;

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

int	pop_stack(t_stack *stack)
{
	t_node	*top;
	int		data;

	if (!stack->head)
		return (0);
	top = stack->head;
	data = top->data;
	stack->head = top->next;
	free(top);
	stack->size--;
	return (data);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

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

int	is_stack_empty(t_stack *stack)
{
	return (stack->size == 0);
}

int	get_stack_size(t_stack *stack)
{
	return (stack->size);
}
