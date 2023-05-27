/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:31:18 by gabriela          #+#    #+#             */
/*   Updated: 2023/05/27 16:14:41 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rot(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	if (!*stack || !(*stack)->next)
		return ;
	i = 0;
	temp = *stack;
	while ((*stack)->next)
	{
		*stack = (*stack)->next;
		i++;
	}
	(*stack)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
}

void	ft_rra(t_stack **a, int j)
{
	rev_rot(a);
	if (j == 0)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **b, int j)
{
	rev_rot(b);
	if (j == 0)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **a, t_stack **b, int j)
{
	rev_rot(a);
	rev_rot(b);
	if (j == 0)
		write(1, "rrr\n", 4);
}