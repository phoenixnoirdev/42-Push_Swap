/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ismin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:14:08 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 14:46:20 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ismin(int *nb, int start, int size)
{
	int	min_i;
	int	i;

	min_i = start;
	i = start + 1;
	while (i < size)
	{
		if (nb[i] < nb[min_i])
			min_i = i;
		i++;
	}
	return (min_i);
}
