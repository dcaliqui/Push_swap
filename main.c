/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaliqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:03:13 by dcaliqui          #+#    #+#             */
/*   Updated: 2024/08/30 15:04:47 by dcaliqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int argc, char **argv) 
{
	t_list *a = NULL;
	t_list *b = NULL;
	
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		if (!process_argument(argv[1], &a))
			return (1);
		is_duplicate(a);
	}
	else 
	{
		if (!process_multiple_arguments(argc, argv, &a))
			return (1);
		is_duplicate(a);
			
	}
	/*ft_putstr("Lista A1\n");
	print_list(a);*/
	if (ft_is_order(&a))
	{
		free_list(a);
		return (1);
	}
	//ft_sa(&a, 42);
	ft_pa(&a, &b);
	ft_pa(&a, &b);
	ft_pa(&a, &b);
	print_list(b);
	printf ("LISTA A\n");
	print_list(a);
	/*ft_rrb(&b);
	ft_sb(&a, 42);*/

	
	free_list(a);
	free_list(b);
	return 0;
}
