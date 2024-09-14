/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaliqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:10:54 by dcaliqui          #+#    #+#             */
/*   Updated: 2024/09/11 13:15:28 by dcaliqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - 48;
		str++;
	}
	return (sign * result);
}

void	sort_two(t_list **stack_a)
{
	t_list	*a;
	t_list	*b;

	a = *stack_a;
	b =  (*stack_a)->next;
	
	if (a->nbr > b->nbr)
		ft_sa(stack_a, 42);
}

void	sort_three(t_list **stack_a)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = *stack_a;
	b = (*stack_a)->next;
	c = (*stack_a)->next->next;
	if (a->nbr > b->nbr && b->nbr < c->nbr && a->nbr < c->nbr)
		ft_sa(stack_a, 42);
	else if (a->nbr > b->nbr &&  b->nbr > c->nbr && a->nbr > c->nbr)
	{
		ft_sa(stack_a, 42);
		ft_rra(stack_a);
	}
	else if (a->nbr > b->nbr && b->nbr < c->nbr && a->nbr > c->nbr)
		ft_ra(stack_a);
	else if (a->nbr < b->nbr && b->nbr > c->nbr && a->nbr < c->nbr)
	{
		ft_sa(stack_a, 42);
		ft_ra(stack_a);
	}
	 else if (a->nbr < b->nbr && b->nbr > c->nbr && a->nbr > c->nbr)
		ft_rra(stack_a);
}

int	ft_isdigit(int i)
{
	while ('0' <= i && i <= '9')
		return (1);
	return (0);
}
