/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:03:35 by phkevin           #+#    #+#             */
/*   Updated: 2024/05/13 14:32:42 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	ft_rotate_rrc(t_list **list, char c)
{
	t_list	*tmp;
	t_list	*tmpprev;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	tmp = *list;
	tmpprev = ft_lstlast(tmp);
	while (tmp)
	{
		if (tmp->next->next == NULL)
		{
			tmp->next = NULL;
			break ;
		}
		tmp = tmp->next;
	}
	tmpprev->next = *list;
	*list = tmpprev;
	if (c == 'a')
		ft_putstr_fd("rra\n", 1);
	if (c == 'b')
		ft_putstr_fd("rrb\n", 1);
	return ;
}

void	ft_rotate_rrr(t_list **alist, t_list **blist)
{
	ft_rotate_rrc(alist, 'r');
	ft_rotate_rrc(blist, 'r');
	ft_putstr_fd("rrr\n", 1);
	return ;
}
