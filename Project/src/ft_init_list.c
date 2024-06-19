/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:18:22 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/07 15:40:04 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

static void	set_pos(t_list **a_list, int *nb, int size)
{
	t_list	*a;
	int		i;

	a = *a_list;
	while (a)
	{
		i = 0;
		while (i < size)
		{
			if (a->content == nb[i])
				a->pos = i;
			i++;
		}
		a = a->next;
	}
}

static void	sort_pos(int *nb, int size)
{
	int	i;
	int	min;
	int	tmp;

	i = -1;
	while (i++ < size - 1)
	{
		min = ft_ismin(nb, i, size);
		tmp = nb[min];
		nb[min] = nb[i];
		nb[i] = tmp;
	}
}

static void	int_pos(t_list **a_list, char **argv)
{
	int	*array;
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (argv[size] != NULL)
		size++;
	array = malloc(size * sizeof(int));
	while (argv[i] != NULL)
	{
		array[i] = ft_atoi(argv[i]);
		i++;
	}
	sort_pos(array, size);
	set_pos(a_list, array, size);
	free(array);
}

void	ft_init_list(t_list **a_list, char **argv, int spconf)
{
	int		i_argc;
	t_list	*new;

	i_argc = 0;
	if (spconf == 0)
		ft_isdoublecquote(a_list, argv, spconf);
	ft_isddorcinlist(a_list, argv, spconf);
	while (argv[i_argc] != NULL)
	{
		new = ft_lstnew(ft_atoi(argv[i_argc++]));
		ft_lstadd_back(a_list, new);
	}
	int_pos(a_list, argv);
}
