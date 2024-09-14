/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaliqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:16:16 by dcaliqui          #+#    #+#             */
/*   Updated: 2024/09/11 13:17:53 by dcaliqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d\n", lst->nbr);
		lst = lst->next;
	}
}

void	free_args(char **args, int i)
{
	while (i >= 0)
		free(args[i--]);
	free(args);
}
