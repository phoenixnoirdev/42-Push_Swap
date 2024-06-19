/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:58:46 by phkevin           #+#    #+#             */
/*   Updated: 2024/05/14 01:55:35 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

int	ft_get_min(t_list **l)
{
	t_list	*compt;
	int		min;

	compt = *l;
	min = compt->content;
	while (compt)
	{
		if (compt->content < min)
			min = compt->content;
		compt = compt->next;
	}
	return (min);
}

int	ft_get_max(t_list **l)
{
	t_list	*compt;
	int		max;

	compt = *l;
	max = compt->content;
	while (compt)
	{
		if (compt->content > max)
			max = compt->content;
		compt = compt->next;
	}
	return (max);
}
