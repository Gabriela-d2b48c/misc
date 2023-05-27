/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:55:19 by gabriela          #+#    #+#             */
/*   Updated: 2023/05/27 16:36:40 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack || !((*stack)->next))
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void	ft_sa(t_stack **a, int j)
{
	swap(a);
	if (j == 0)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack **b, int j)
{
	swap(b);
	if (j == 0)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack **a, t_stack **b, int j)
{
	swap(a);
	swap(b);
	if (j == 0)
		write(1, "ss\n", 3);
}