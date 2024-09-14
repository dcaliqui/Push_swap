/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaliqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:38:23 by dcaliqui          #+#    #+#             */
/*   Updated: 2024/08/30 14:38:25 by dcaliqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

//#define MAX_INT_LEN 10

typedef struct	s_list 
{
	int	nbr;
	//int	*count;
	struct	s_list *next;
}	t_list;

bool	process_arguments(int argc, char **argv, t_list **list);
void	sort_three(t_list **stack_a);
void	ft_ra(t_list **stack_a);
void	ft_sb(t_list **stack_b, int c);
int	ft_is_order(t_list **stack_a);
void	ft_rb(t_list **stack_b);
void	ft_rra(t_list **stack_a);
void	ft_rb(t_list **stack_b);
char	**ft_split(const char *str, int *count);
void	ft_rrb(t_list **stack_b);
void	ft_rra(t_list **stack_a);
void	sort_two(t_list **stack_a);
void	ft_putstr(char *str);
void	free_args(char **args, int i);
int	ft_atoi(char *str);
void	print_list(t_list *lst);
void	is_duplicate(t_list *stack_a);
t_list *create_node(int nbr);
void	free_list(t_list *head);
void	append_node(t_list **head, int nbr);
bool process_multiple_arguments(int argc, char **argv, t_list **list);
bool process_argument(char *arg, t_list **list);
int	is_valid_integer(const char *str);
void	ft_sa(t_list **stack_a, int c);
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_sb(t_list **stack_b, int c);
void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_pa(t_list **stack_a, t_list **stack_b);
int	ft_isdigit(int i);

