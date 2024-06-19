/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:03:02 by phkevin           #+#    #+#             */
/*   Updated: 2024/05/21 13:34:42 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

static void	sort_clean(t_list **a)
{
	int	max;

	if (ft_issort(a))
		return ;
	max = ft_get_max(a);
	while ((*a)->content != max)
		ft_rotate(a, 'a');
}

static void	ft_init_b_pivot(t_list **la, t_list **lb)
{
	int	pivot;

	pivot = ft_get_pivot(la);
	while (*la && (*la)->next)
	{
		if ((*la)->content >= pivot)
			ft_push(la, lb, 'b');
		if ((*la)->content < pivot)
		{
			ft_push(la, lb, 'b');
			ft_rotate(lb, 'b');
		}
	}
}

void	ft_rotate_sort(t_list **la, t_list **lb)
{
	int	max;

	ft_init_b_pivot(la, lb);
	max = ft_get_max(lb);
	while (ft_lstsize(*lb) > 0)
	{
		if ((*lb)->content == max)
		{
			ft_push(lb, la, 'a');
			if (ft_lstsize(*lb) > 0)
				max = ft_get_max(lb);
			if (ft_lstsize(*la) > 1 && (*la)->content > (*la)->next->content)
				ft_swap(la, 'a');
		}
		else
			ft_rotate(lb, 'b');
	}
	sort_clean(la);
}
