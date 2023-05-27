/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 10:58:21 by gabriela          #+#    #+#             */
/*   Updated: 2023/05/27 16:32:48 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->nbr = 0;
		free(*lst);
		*lst = tmp;
	}
}

void	ft_free_str(char **lst)
{
	char	*s;

	if (!lst)
		return ;
	while (*lst)
	{
		s = *lst;
		lst++;
		free(s);
	}
	*lst = NULL;
}

void	ft_error(void)
{	
	write (2, "Error\n", 6);
	exit(1);
}
