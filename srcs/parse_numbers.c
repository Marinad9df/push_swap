/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigon2 <marigon2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:10:30 by marigon2          #+#    #+#             */
/*   Updated: 2024/09/23 22:10:31 by marigon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	count_numbers(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

int	check_digits(int argc, char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!is_valid_char(argv[i][j]))
				return (-1);
			j++;
		}
		count += count_numbers(argv[i]);
		i++;
	}
	return (count);
}

static int	parse_argument(char *arg, int **numbers, int *index)
{
	char	**s_numbers;
	int		k;

	s_numbers = ft_split(arg, ' ');
	if (!s_numbers)
		return (0);
	if (!check_range(s_numbers, *numbers))
	{
		free_2d(s_numbers);
		return (0);
	}
	k = 0;
	while (s_numbers[k])
		(*numbers)[(*index)++] = ft_atoi(s_numbers[k++]);
	free_2d(s_numbers);
	return (1);
}

int	*parse_numbers(int argc, char **argv, int count)
{
	int	*numbers;
	int	i;
	int	index;

	numbers = (int *)malloc(sizeof(int) * count);
	if (!numbers)
		return (NULL);
	i = 1;
	index = 0;
	while (i < argc)
	{
		if (!parse_argument(argv[i++], &numbers, &index))
		{
			free(numbers);
			return (NULL);
		}
	}
	return (numbers);
}
