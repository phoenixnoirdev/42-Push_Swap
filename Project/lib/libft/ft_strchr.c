/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:23:31 by phkevin           #+#    #+#             */
/*   Updated: 2024/02/22 12:23:55 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (c > 127)
		return ((char *) s);
	while (*s)
	{
		if (*s == c)
		{
			return ((char *) s);
		}
		s++;
	}
	if (*s == c)
		return ((char *) s);
	return (0);
}
