/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:03:35 by phkevin           #+#    #+#             */
/*   Updated: 2024/05/13 14:54:26 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	ft_rotate(t_list **list, char c)
{
	t_list	*tmp;
	t_list	*rot;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	tmp = *list;
	rot = ft_lstlast(tmp);
	*list = tmp->next;
	tmp->next = NULL;
	rot->next = tmp;
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
	if (c == 'b')
		ft_putstr_fd("rb\n", 1);
	return ;
}

void	ft_rotate_rr(t_list **alist, t_list **blist)
{
	ft_rotate(alist, 'r');
	ft_rotate(blist, 'r');
	ft_putstr_fd("rr\n", 1);
	return ;
}
