/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:35:29 by phkevin           #+#    #+#             */
/*   Updated: 2024/05/21 13:36:12 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"
#include <stdio.h>

static void	ft_target_send(char c)
{
	if (c == 'a')
		ft_putstr_fd("pa\n", 1);
	if (c == 'b')
		ft_putstr_fd("pb\n", 1);
}

void	ft_push(t_list **listf, t_list **listt, char c)
{
	t_list	*tmp;
	t_list	*to;
	t_list	*from;

	if (ft_lstsize(*listf) == 0)
		return ;
	to = *listt;
	from = *listf;
	tmp = from;
	from = from->next;
	*listf = from;
	if (!to)
	{
		to = tmp;
		to->next = NULL;
		*listt = to;
	}
	else
	{
		tmp->next = to;
		*listt = tmp;
	}
	ft_target_send(c);
	return ;
}
