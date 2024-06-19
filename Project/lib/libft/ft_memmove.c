/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:43:32 by phkevin           #+#    #+#             */
/*   Updated: 2024/02/21 09:43:35 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dstr;
	const char	*sstr;
	size_t		i;

	dstr = (char *)dest;
	sstr = (const char *)src;
	if (dstr < sstr)
	{
		i = 0;
		while (i < n)
		{
			dstr[i] = sstr[i];
			i++;
		}
	}
	else
	{
		while (n--)
			dstr[n] = sstr[n];
	}
	return (dest);
}
