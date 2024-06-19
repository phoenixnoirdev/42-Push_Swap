/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:24:39 by phkevin           #+#    #+#             */
/*   Updated: 2024/04/12 12:35:25 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*sa;
	const unsigned char	*sb;

	sa = s1;
	sb = s2;
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*sa != *sb)
			return (*sa - *sb);
		sa++;
		sb++;
	}
	return (0);
}
