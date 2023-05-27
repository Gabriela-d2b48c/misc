/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:50:43 by gabriela          #+#    #+#             */
/*   Updated: 2023/05/27 16:29:39 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// calcs and choose which rotation needed during push from b to a.
int	ft_find_rot_a(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = b;
	i = is_rrarrb_a(a, b, b->nbr);
	while (tmp)
	{
		if (i > is_rarb_a(a, b, tmp->nbr))
			i = is_rarb_a(a, b, tmp->nbr);
		if (i > is_rrarrb_a(a, b, tmp->nbr))
			i = is_rrarrb_a(a, b, tmp->nbr);
		if (i > is_rarrb_a(a, b, tmp->nbr))
			i = is_rarrb_a(a, b, tmp->nbr);
		if (i > is_rrarb_a(a, b, tmp->nbr))
			i = is_rrarb_a(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}

// calcs how many rotates needed
int	is_rarb_a(t_stack *a, t_stack *b, int value)
{
	int	i;

	i = ft_index_in_a(a, value);
	if (i < ft_index(b, value))
		i = ft_index(b, value);
	return (i);
}

int ft_do_rarb_a(t_stack **a, t_stack **b, int pushed)
{
	while ((*a)->nbr != pushed && ft_index_in_b(*b, pushed) > 0)
		ft_rr(a, b, 0);
	while ((*a)->nbr != pushed)
		ft_ra(a, 0);
	while (ft_index_in_b(*b, pushed) > 0)
		ft_rb(b, 0);
	ft_pb(a, b, 0);
	return (-1);
}

int	is_rrarrb_a(t_stack *a, t_stack *b, int value)
{
	int	i;

	i = 0;
	if (ft_index_in_a(a, value))
		i = ft_lstsize(a) - ft_index_in_a(a, value);
	if ((i < (ft_lstsize(b) - ft_index(b, value))) && ft_index(b, value))
		i = ft_lstsize(b) - ft_index(b, value);
	return (i);
}

int ft_do_rrarrb_a(t_stack **a, t_stack **b, int pushed)
{
	while ((*a)->nbr != pushed && ft_index_in_b(*b, pushed) > 0)
		ft_rrr(a, b, 0);
	while ((*a)->nbr != pushed)
		ft_rra(a, 0);
	while (ft_index_in_b(*b, pushed) > 0)
		ft_rrb(b, 0);
	ft_pb(a, b, 0);
	return (-1);
}

int	is_rarrb_a(t_stack *a, t_stack *b, int value)
{
	int	i;

	i = 0;
	if (ft_index(b, value))
		i = ft_lstsize(b) - ft_index(b, value);
	i = ft_index_in_a(a, value) + i;
	return (i);
}

int ft_do_rarrb_a(t_stack **a, t_stack **b, int pushed)
{
	while ((*a)->nbr != pushed)
		ft_ra(a, 0);
	while (ft_index_in_b(*b, pushed) > 0)
		ft_rrb(b, 0);
	ft_pb(a, b, 0);
	return (-1);
}

int	is_rrarb_a(t_stack *a, t_stack *b, int value)
{
	int	i;

	i = 0;
	if (ft_index_in_a(a, value))
		i = ft_lstsize(a) - ft_index_in_a(a, value);
	i = ft_index(b, value) + i;
	return (i);
}

int ft_do_rrarb_b(t_stack **a, t_stack **b, int pushed)
{
	while (ft_index_in_a(*a, pushed) > 0)
		ft_rra(a, 0);
	while ((*b)->nbr != pushed)
		ft_rb(b, 0);
	ft_pa(a, b, 0);
	return (-1);
}