/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaliqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 08:12:31 by dcaliqui          #+#    #+#             */
/*   Updated: 2024/09/09 10:32:20 by dcaliqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **stack_a, int c)
{
	t_list	*first;
	t_list	*second;

	if (*stack_a && (*stack_a)->next)
	{
		first = *stack_a;
		second = (*stack_a)->next;
		first->next = second->next;
		second->next = first;
		*stack_a = second;
		if (c == 42)
			printf ("sa\n");
	}
}

void	ft_sb(t_list **stack_b, int c)
{
	t_list	*first;
	t_list	*second;

	if (*stack_b && (*stack_b)->next)
	{
		first = *stack_b;
		second = (*stack_b)->next;
		first->next = second->next;
		second->next = first;
		*stack_b = second;
		if (c == 42)
			printf ("sb\n");
	}
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{	
	if (*stack_a && *stack_b)
	{
		ft_sa(stack_a, 1);
		ft_sb(stack_b, 1);
		printf ("ss\n");
	}	
}

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;

	if (*stack_b)
	{
		aux = *stack_b;
		*stack_b = (*stack_b)->next;
		aux->next = *stack_a;
		*stack_a = aux;
		printf("pb\n");
	}
}

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;

	if (*stack_a)
	{	
		aux = *stack_a;
		*stack_a = (*stack_a)->next;
		aux->next = *stack_b;
		*stack_b = aux;
		printf("pb\n");
	}
}

void	ft_ra(t_list **stack_a)
{
	t_list	*first;
	t_list	*last;

	if (*stack_a && (*stack_a)->next)
	{
		first = *stack_a;
		last = *stack_a;
		while (last->next)
		{
			last = last->next;
		}
		*stack_a = first->next;
		last->next = first;
		first->next = NULL;
	}
	ft_putstr("ra\n");
}

void	ft_rb(t_list **stack_b)
{
	t_list	*first;
	t_list	*last;

	if (*stack_b && (*stack_b)->next)
	{
		first = *stack_b;
		last = *stack_b;
		while (last->next)
		{
			last = last->next;
		}
		*stack_b = first->next;
		last->next = first;
		first->next = NULL;
	}
	ft_putstr("rb\n");
}

void	ft_rra(t_list **stack_a)
{
	t_list *first;
	t_list *last;
	t_list	*before;

	if (*stack_a && (*stack_a)->next)
	{
		first = *stack_a;
		last = *stack_a;

		while (last->next)
		{
			before = last;		
			last = last->next;
		}
		last->next = first;
		before->next = NULL;
		*stack_a = last;
	}
	ft_putstr("rra\n");
}

void	ft_rrb(t_list **stack_b)
{
	t_list *first;
	t_list *last;
	t_list	*before;

	if (*stack_b && (*stack_b)->next)
	{
		first = *stack_b;
		last = *stack_b;

		while (last->next)
		{
			before = last;		
			last = last->next;
		}
		last->next = first;
		before->next = NULL;
		*stack_b = last;
	}
	ft_putstr("rrb\n");
}
