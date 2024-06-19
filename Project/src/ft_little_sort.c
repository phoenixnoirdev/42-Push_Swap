/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_little_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:07:12 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/07 11:59:19 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	ft_triple_sort(t_list **la)
{
	int	a;
	int	b;
	int	c;

	if (ft_issort(la))
		return ;
	a = (*la)->content;
	b = (*la)->next->content;
	c = (*la)->next->next->content;
	if (a < b && b > c && c > a)
	{
		ft_rotate_rrc(la, 'a');
		ft_swap(la, 'a');
	}
	else if (a > b && b < c && a > c)
		ft_rotate(la, 'a');
	else if (a > b && b < c && a < c)
		ft_swap(la, 'a');
	else if (a > b && b > c && a > c)
	{
		ft_swap(la, 'a');
		ft_rotate_rrc(la, 'a');
	}
	else if (a < b && b > c && a > c)
		ft_rotate_rrc(la, 'a');
}

void	ft_four_sort(t_list **a, t_list **b)
{
	int	max;

	if (ft_issort(a))
		return ;
	max = 0;
	max = ft_get_max(a);
	while ((*a)->content != max)
		ft_rotate(a, 'a');
	ft_push(a, b, 'b');
	ft_triple_sort(a);
	ft_push(b, a, 'a');
	ft_rotate(a, 'a');
}

static int	count_cost(t_list *l, int nb)
{
	int	cost;

	cost = 0;
	while (l && l->pos != nb)
	{
		l = l->next;
		cost++;
	}
	return (cost);
}

static int	pos_min(t_list **l)
{
	t_list	*compt;
	int		min;

	compt = *l;
	min = compt->pos;
	while (compt)
	{
		if (compt->pos < min)
			min = compt->pos;
		compt = compt->next;
	}
	return (min);
}

void	ft_five_sort(t_list **a, t_list **b)
{
	int	rb_count;
	int	rrb_count;
	int	i;

	i = 0;
	while (i < 2)
	{
		rb_count = count_cost(*a, pos_min(a));
		rrb_count = (ft_lstsize(*a)) - rb_count;
		if (rb_count <= rrb_count)
		{
			while ((*a)->pos != pos_min(a))
				ft_rotate(a, 'a');
		}
		else
		{
			while ((*a)->pos != pos_min(a))
				ft_rotate_rrc(a, 'a');
		}
		ft_push(a, b, 'b');
		i++;
	}
	ft_triple_sort(a);
	ft_push(b, a, 'a');
	ft_push(b, a, 'a');
}
