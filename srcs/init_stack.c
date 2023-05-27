/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:00:15 by gabriela          #+#    #+#             */
/*   Updated: 2023/05/27 16:13:45 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc < 2)
		return (0);
	a = ft_handle_input(argc, argv);
	if (!a || ft_is_dup(a))
	{
		ft_free(&a);
		ft_error();
	}
	if (!ft_is_sorted(a))
		ft_sort(&a);
	ft_free(&a);
	return (0);
}

t_stack	*ft_handle_quoted_str(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		j = ft_atoi_long(tmp[i]);
		ft_add_back_node(&a, ft_new_stack(j));
		i++;
	}
	ft_free_str(tmp);
	free(tmp);
	return (a);
}

t_stack	*ft_handle_input(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (argc == 2)
		a = ft_handle_quoted_str(argv);
	else
	{
		while (i < argc)
		{
			j = ft_atoi_long(argv[i]);
			ft_add_back_node(&a, ft_new_stack(j));
			i++;
		}
	}
	return (a);
}

int	ft_is_dup(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->nbr == tmp->nbr)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

