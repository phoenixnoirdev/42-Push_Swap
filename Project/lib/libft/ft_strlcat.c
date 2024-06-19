/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:16:18 by phkevin           #+#    #+#             */
/*   Updated: 2024/02/22 09:16:20 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	lensrc;
	size_t	lendest;

	lensrc = ft_strlen((char *) src);
	lendest = ft_strlen((char *) dest);
	if (size >= lendest + 1)
	{
		i = 0;
		while (src[i] != '\0' && lendest + i < size - 1)
		{
			dest[lendest + i] = src[i];
			i++;
		}
		dest[lendest + i] = '\0';
		return (lendest + lensrc);
	}
	else
		return (size + lensrc);
}
