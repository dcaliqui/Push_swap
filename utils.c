/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaliqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:50:45 by dcaliqui          #+#    #+#             */
/*   Updated: 2024/08/30 15:10:45 by dcaliqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(const char *str)
{
	int	count;
	int	in_word;

	in_word = 0;
	count = 0;
	while (*str)
	{
		if (*str != ' ' && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*str == ' ')
		{
			in_word = 0;
		}
		str++;
	}
	return (count);
}

void	is_duplicate(t_list *stack_a)
{
	t_list	*current;
	t_list	*cmp;

	current = stack_a;
	while (current != NULL)
	{
		cmp = stack_a;
		while (cmp != current)
		{
			if (current->nbr == cmp->nbr)
			{
				printf("Error\n");
				free_list(stack_a);
				exit(1);
			}
			cmp = cmp->next;
		}
		current = current->next;
	}
}

static	void	clean_line(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

static	void	there_are_spaces(const char *str, int *i)
{
	while ((str[(*i)] == ' ' || str[(*i)] == '\n' || str[(*i)] == '\t')
		&& str[(*i)])
		(*i) += 1;
}

char	**ft_split(char const *str, int *count)
{
	char	**mat;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	*count = count_words(str);
	there_are_spaces(str, &i);
	mat = (char **)malloc(sizeof(char *) * (456));
	if (!mat)
		return (NULL);
	while (str[i])
	{
		j = 0;
		mat[k] = (char *)malloc(sizeof(char) * (4096));
		if (!mat[k])
			return (clean_line(mat), NULL);
		while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i])
			mat[k][j++] = str[i++];
		mat[k++][j] = '\0';
		there_are_spaces(str, &i);
	}
	mat[k] = NULL;
	return (mat);
}
