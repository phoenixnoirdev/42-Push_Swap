/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:15:41 by phkevin           #+#    #+#             */
/*   Updated: 2024/04/15 11:00:31 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	ft_swap(t_list **list, char c)
{
	t_list	*tmp0;
	t_list	*tmp1;

	tmp0 = NULL;
	tmp1 = NULL;
	if (*list == NULL || (*list)->next == NULL)
		return ;
	tmp0 = *list;
	tmp1 = (*list)->next;
	tmp0->next = tmp1->next;
	tmp1->next = tmp0;
	*list = tmp1;
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
	if (c == 'b')
		ft_putstr_fd("sb\n", 1);
	return ;
}

void	ft_swap_ab(t_list **alist, t_list **blist)
{
	ft_swap(alist, 'r');
	ft_swap(blist, 'r');
	ft_putstr_fd("ss\n", 1);
	return ;
}
