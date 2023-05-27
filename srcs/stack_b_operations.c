/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:50:43 by gabriela          #+#    #+#             */
/*   Updated: 2023/05/27 16:32:41 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// calcs and choose which rotation needed during push from a to b.
int	ft_find_rot_b(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = a;
	i = is_rrarrb_b(a, b, a->nbr);
	while (tmp)
	{
		if (i > is_rarb_b(a, b, tmp->nbr))
			i = is_rarb_b(a, b, tmp->nbr);
		if (i > is_rrarrb_b(a, b, tmp->nbr))
			i = is_rrarrb_b(a, b, tmp->nbr);
		if (i > is_rarrb_b(a, b, tmp->nbr))
			i = is_rarrb_b(a, b, tmp->nbr);
		if (i > is_rrarb_b(a, b, tmp->nbr))
			i = is_rrarb_b(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}

// calcs how many rotates needed
int	is_rarb_b(t_stack *a, t_stack *b, int value)
{
	int	i;

	i = ft_index_in_b(b, value);
	if (i < ft_index(a, value))
		i = ft_index(a, value);
	return (i);
}

int ft_do_rarb_b(t_stack **a, t_stack **b, int pushed)
{
	while ((*b)->nbr != pushed && ft_index_in_a(*a, pushed) > 0)
		ft_rr(a, b, 0);
	while ((*b)->nbr != pushed)
		ft_rb(b, 0);
	while (ft_index_in_a(*a, pushed) > 0)
		ft_ra(a, 0);
	ft_pa(a, b, 0);
	return (-1);
}

int	is_rrarrb_b(t_stack *a, t_stack *b, int value)
{
	int	i;

	i = 0;
	if (ft_index_in_b(b, value))
		i = ft_lstsize(b) - ft_index_in_b(b, value);
	if ((i < (ft_lstsize(a) - ft_index(a, value))) && ft_index(a, value))
		i = ft_lstsize(a) - ft_index(a, value);
	return (i);
}

int ft_do_rrarrb_b(t_stack **a, t_stack **b, int pushed)
{
	while ((*b)->nbr != pushed && ft_index_in_a(*a, pushed) > 0)
		ft_rrr(a, b, 0);
	while ((*b)->nbr != pushed)
		ft_rrb(b, 0);
	while (ft_index_in_a(*a, pushed) > 0)
		ft_rra(a, 0);
	ft_pa(a, b, 0);
	return (-1);
}

int	is_rrarb_b(t_stack *a, t_stack *b, int value)
{
	int	i;

	i = 0;
	if (ft_index(a, value))
		i = ft_lstsize(a) - ft_index(a, value);
	i = ft_index_in_b(b, value) + i;
	return (i);
}

int ft_do_rrarb_a(t_stack **a, t_stack **b, int pushed)
{
	while ((*a)->nbr != pushed)
		ft_rra(a, 0);
	while (ft_index_in_b(*b, pushed) > 0)
		ft_rb(b, 0);
	ft_pb(a, b, 0);
	return (-1);
}

int	is_rarrb_b(t_stack *a, t_stack *b, int value)
{
	int	i;

	i = 0;
	if (ft_index_in_b(b, value))
		i = ft_lstsize(b) - ft_index_in_b(b, value);
	i = ft_index(a, value) + i;
	return (i);
}

int ft_do_rarrb_b(t_stack **a, t_stack **b, int pushed)
{
	while (ft_index_in_a(*a, pushed) > 0)
		ft_ra(a, 0);
	while ((*b)->nbr != pushed)
		ft_rrb(b, 0);
	ft_pa(a, b, 0);
	return (-1);
}