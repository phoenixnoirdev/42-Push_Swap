/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:34:36 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/01 15:37:32 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

t_list	*ft_lstnew(int val)
{
	t_list	*ln;

	ln = (t_list *) malloc(sizeof(*ln));
	if (!ln)
		return (NULL);
	ln->content = val;
	ln->pos = 0;
	ln->next = NULL;
	return (ln);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_front(t_list **lf, t_list *lt)
{
	lt->next = *lf;
	*lf = lt;
}

void	ft_lstadd_back(t_list **ls, t_list *lt)
{
	t_list	*lsladd;

	if (ls == NULL || lt == NULL)
		return ;
	if (*ls == NULL)
	{
		*ls = lt;
		return ;
	}
	lsladd = *ls;
	while (lsladd->next != NULL)
		lsladd = lsladd->next;
	lsladd->next = lt;
}

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
