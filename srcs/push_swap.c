/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigon2 <marigon2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:10:39 by marigon2          #+#    #+#             */
/*   Updated: 2024/09/23 22:10:40 by marigon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	validate_input(int argc, char **argv, int **numbers)
{
	int	count;

	if (argc == 1)
		return (-1);
	count = check_digits(argc, argv);
	*numbers = arg_parse(argc, argv, count);
	if (count <= 1 || check_duplicates_bf(*numbers, count))
	{
		free(*numbers);
		return (-1);
	}
	return (count);
}

static void	set_stack_indexes(t_stack *stack, int *sorted_numbers)
{
	t_node	*tmp;

	tmp = stack->head;
	while (tmp)
	{
		tmp->s_index = index_of(tmp->data, sorted_numbers);
		tmp = tmp->next;
	}
}

static void	initialize_stacks(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->head = NULL;
	stack_b->head = NULL;
	stack_a->size = 0;
	stack_b->size = 0;
}

void	init_stack(t_stack *stack_a, t_stack *stack_b, int *nb, int c)
{
	int	i;

	initialize_stacks(stack_a, stack_b);
	i = c - 1;
	while (i >= 0)
		push_stack(stack_a, 0, nb[i--]);
	insertion_sort(nb, c);
	set_stack_indexes(stack_a, nb);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		count;
	int		*numbers;

	count = validate_input(argc, argv, &numbers);
	if (count == -1)
		return (1);
	init_stack(&stack_a, &stack_b, numbers, count);
	sort(&stack_a, &stack_b, numbers, count);
	free(numbers);
	free_stack(&stack_a);
	return (0);
}
