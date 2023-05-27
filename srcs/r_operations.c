/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:33:48 by gabriela          #+#    #+#             */
/*   Updated: 2023/05/27 17:15:50 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rot(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = lstlast(*stack);
	(*stack)->next = temp;
	*stack = temp->next;
	temp->next = NULL;
}

void	ft_ra(t_stack **a, int j)
{
	rot(a);
	if (j == 0)
		write(1, "ra\n", 3);
}

void	ft_rb(t_stack **b, int j)
{
	rot(b);
	if (j == 0)
		write(1, "rb\n", 3);
}

void	ft_rr(t_stack **a, t_stack **b, int j)
{
	rot(a);
	rot(b);
	if (j == 0)
		write(1, "rr\n", 3);
}