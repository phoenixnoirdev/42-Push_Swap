/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_k.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:34:00 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/01 18:26:30 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

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

static int	pos_max(t_list **l)
{
	t_list	*compt;
	int		max;

	compt = *l;
	max = compt->pos;
	while (compt)
	{
		if (compt->pos > max)
			max = compt->pos;
		compt = compt->next;
	}
	return (max);
}

static void	sort_fin(t_list **la, t_list **lb)
{
	int	rb_count;
	int	rrb_count;

	while (ft_lstsize(*lb) != 0)
	{
		rb_count = count_cost(*lb, pos_max(lb));
		rrb_count = (ft_lstsize(*lb)) - rb_count;
		if (rb_count <= rrb_count)
		{
			while ((*lb)->pos != pos_max(lb))
				ft_rotate(lb, 'b');
		}
		else
		{
			while ((*lb)->pos != pos_max(lb))
				ft_rotate_rrc(lb, 'b');
		}
		ft_push(lb, la, 'a');
	}
}

static int	sort_move(t_list **a, t_list **b, int range, int i)
{
	if ((*a)->pos <= i)
	{
		ft_push(a, b, 'b');
		ft_rotate(b, 'b');
	}
	else if ((*a)->pos <= i + range)
	{
		ft_push(a, b, 'b');
	}
	return (1);
}

void	ft_k_sort(t_list **la, t_list **lb, int calib)
{
	int	i;
	int	range;

	i = 0;
	range = ft_get_pivot_pos(la) * calib / 10;
	while (ft_lstsize(*la) != 0)
	{
		if (ft_isrevsort(la) == 0)
		{
			if ((*la)->pos <= i || (*la)->pos <= i + range)
				i += sort_move(la, lb, range, i);
			else
				ft_rotate(la, 'a');
		}
		else
			ft_push(la, lb, 'b');
	}
	sort_fin(la, lb);
}
