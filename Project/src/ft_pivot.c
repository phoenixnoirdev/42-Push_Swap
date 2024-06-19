/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pivot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:51:52 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/01 18:32:56 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

int	ft_get_pivot(t_list **list)
{
	int		pivot;
	t_list	*tmp;

	tmp = *list;
	pivot = 0;
	while (tmp)
	{
		if (tmp->content > pivot)
			pivot = tmp->content;
		tmp = tmp->next;
	}
	pivot /= 2;
	return (pivot);
}

int	ft_get_pivot_pos(t_list **list)
{
	int		pivot;
	t_list	*tmp;

	tmp = *list;
	pivot = 0;
	while (tmp)
	{
		if (tmp->pos > pivot)
			pivot = tmp->pos;
		tmp = tmp->next;
	}
	pivot /= 2;
	return (pivot);
}
