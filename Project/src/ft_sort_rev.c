/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_rev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:05:03 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/07 13:25:40 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	ft_sort_rev(t_list **a_list, t_list **b_list)
{
	while (ft_lstsize(*a_list) != 0)
		ft_push(a_list, b_list, 'b');
	while (ft_lstsize(*b_list) != 0)
	{
		ft_rotate_rrc(b_list, 'b');
		ft_push(b_list, a_list, 'a');
	}
}
