/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:04:35 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/07 14:03:52 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	ft_sort(t_list **a_list, t_list **b_list)
{
	if (ft_issort(a_list))
		return ;
	else if (ft_isrevsort(a_list) && ft_lstsize(*a_list) > 5)
		ft_sort_rev(a_list, b_list);
	else if (ft_lstsize(*a_list) > 1)
	{
		if (ft_lstsize(*a_list) == 2)
			ft_swap(a_list, 'a');
		else if (ft_lstsize(*a_list) == 3)
			ft_triple_sort(a_list);
		else if (ft_lstsize(*a_list) == 4)
			ft_four_sort(a_list, b_list);
		else if (ft_lstsize(*a_list) == 5)
			ft_five_sort(a_list, b_list);
		else if (ft_lstsize(*a_list) < 100)
			ft_rotate_sort(a_list, b_list);
		else if (ft_lstsize(*a_list) <= 250)
			ft_k_sort(a_list, b_list, 5);
		else
			ft_k_sort(a_list, b_list, 1);
	}
}
