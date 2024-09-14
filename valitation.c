/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valitation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaliqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:47:22 by dcaliqui          #+#    #+#             */
/*   Updated: 2024/08/30 14:50:11 by dcaliqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <limits.h>
#include <ctype.h>

int	is_valid_integer(const char *str)
{
	long	num;
	int		i;
	int		sign;

	num = 0;
	sign = 1;
	i = 0;
	if (*str == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		num = num * 10 + (str[i] - '0');
		if ((sign == 1 && num > INT_MAX)
			|| (sign == -1 && -num < INT_MIN))
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_order(t_list **stack_a)
{
	t_list	*valid;

	valid = *stack_a;
	if (valid && valid->next)
	{
		while (valid->next)
		{
			if (valid->nbr > valid->next->nbr)
				return (0);
			valid = valid->next;
		}
	}
	return (1);
}

static bool	process_numbers(char **args, t_list **list, int count_args)
{
	int	i;
	int	num;

	i = 0;
	while (i < count_args)
	{
		if (is_valid_integer(args[i]))
		{
			num = ft_atoi(args[i]);
			append_node(list, num);
		}
		else
			return (false);
		i++;
	}
	return (true);
}

bool	process_argument(char *arg, t_list **list)
{
	char	**args;
	int		count_args;

	args = ft_split(arg, &count_args);
	if (!args)
		return (false);
	if (!process_numbers(args, list, count_args))
	{
		free_list(*list);
		free_args(args, count_args);
		return (false);
	}
	if (count_args == 2)
		sort_two(list);
	if (count_args == 3)
		sort_three(list);
	free_args(args, count_args);
	return (true);
}

bool	process_multiple_arguments(int argc, char **argv, t_list **list)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!process_argument(argv[i], list))
		{
			fprintf(stderr, "Error\n");
			//free_list(*list);
			return (false);
		}
		i++;
	}
	if (argc - 1 == 2)
		 sort_two(list);
	if (argc - 1 == 3)
		sort_three(list);
	//free_args(argv, i);
	return (true);
}
