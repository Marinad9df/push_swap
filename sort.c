#include "../includes/push_swap.h"

static int	is_rot_sort(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->head->data;
	b = stack->head->next->data;
	c = stack->head->next->next->data;
	return ((a < b && b < c) || (b < c && a > c) || (c < a && a < b));
}

static void	rotate_to_min(t_stack *stack, int min_index, int length)
{
	int	r;

	r = count_r(stack->head, min_index);
	if (r < length - r)
		rotate(stack, 'a', true);
	else
		reverse_rotate(stack, 'a', true);
}

void	simple_sort(t_stack *stack, int length)
{
	int	min_index;

	if (is_sorted(stack))
		return ;
	min_index = get_min_index(stack);
	if (is_rot_sort(stack))
		rotate_to_min(stack, min_index, length);
	else
	{
		swap(stack, 'a', true);
		if (is_sorted(stack))
			return ;
		rotate_to_min(stack, min_index, length);
	}
}

void	s_insertion_sort(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	min_index;
	int	iter;
	int	n;

	n = length;
	for (iter = 0; iter < n - 3; iter++)
	{
		min_index = get_min_index(stack_a);
		rotate_to_min(stack_a, min_index, length);
		if (is_sorted(stack_a) && stack_b->size == 0)
			return ;
		push(stack_b, stack_a, 'b', true);
		length--;
	}
	simple_sort(stack_a, length);
	while (stack_b->size > 0)
		push(stack_a, stack_b, 'a', true);
}

void	k_sort1(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(length) * 14 / 10;
	while (stack_a->head)
	{
		if (stack_a->head->s_index <= i)
		{
			push(stack_b, stack_a, 'b', true);
			rotate(stack_b, 'b', true);
			i++;
		}
		else if (stack_a->head->s_index <= i + range)
		{
			push(stack_b, stack_a, 'b', true);
			i++;
		}
		else
			rotate(stack_a, 'a', true);
	}
}

void	k_sort2(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	rb_count;
	int	rrb_count;

	while (--length >= 0)
	{
		rb_count = count_r(stack_b->head, length);
		rrb_count = (length + 3) - rb_count;
		if (rb_count <= rrb_count)
			while (stack_b->head->s_index != length)
				rotate(stack_b, 'b', true);
		else
			while (stack_b->head->s_index != length)
				reverse_rotate(stack_b, 'b', true);
		push(stack_a, stack_b, 'a', true);
	}
}
