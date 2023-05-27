/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:19:51 by gabriela          #+#    #+#             */
/*   Updated: 2023/05/27 16:35:32 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_index(t_stack *stack, int value)
{
	int		i;

	i = 0;
	while (stack->nbr != value)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	ft_index_in_b(t_stack *b, int pushed)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (pushed > b->nbr && pushed < ft_lstlast(b)->nbr)
		i = 0;
	else if (pushed > ft_find_max(b) || pushed < ft_find_min(b))
		i = ft_index(b, ft_find_max(b));
	else
	{
		tmp = b->next;
		while (b->nbr < pushed || tmp->nbr > pushed)
		{
			b = b->next;
			tmp = b->next;
			i++;
		}
	}
	return (i);
}

int	ft_index_in_a(t_stack *a, int pushed)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (pushed < a->nbr && pushed > ft_lstlast(a)->nbr)
		i = 0;
	else if (pushed > ft_find_max(a) || pushed < ft_find_min(a))
		i = ft_index(a, ft_find_min(a));
	else
	{
		tmp = a->next;
		while (a->nbr > pushed || tmp->nbr < pushed)
		{
			a = a->next;
			tmp = a->next;
			i++;
		}
	}
	return (i);
}