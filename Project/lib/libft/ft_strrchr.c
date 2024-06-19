/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:58:32 by phkevin           #+#    #+#             */
/*   Updated: 2024/02/22 12:58:35 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	if (c > 127)
		return ((char *) s);
	while (*s)
	{
		if (*s == c)
			last = (char *) s;
		s++;
	}
	if (*s == c)
		return ((char *) s);
	return (last);
}
