/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:06:56 by phkevin           #+#    #+#             */
/*   Updated: 2024/02/22 16:06:59 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	litlen;
	size_t	i_b;

	litlen = ft_strlen((char *) little);
	if (little[0] == '\0')
	{
		return ((char *) big);
	}
	i_b = 0;
	while (big[i_b] && i_b < len)
	{
		if (big[i_b] == little[0] && (len - i_b >= litlen))
			if (!ft_strncmp((char *)&big[i_b], (char *)little, litlen))
				return ((char *)&big[i_b]);
		i_b++;
	}
	return (0);
}
