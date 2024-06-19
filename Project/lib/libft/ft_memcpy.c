/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:36:41 by phkevin           #+#    #+#             */
/*   Updated: 2024/02/21 11:02:06 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dstr;
	const char	*sstr;

	sstr = (char *) src;
	dstr = (char *) dest;
	if (!dest && !src)
		return (0);
	while (n--)
		dstr[n] = sstr[n];
	return (dest);
}
