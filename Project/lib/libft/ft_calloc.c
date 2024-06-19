/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:51:07 by phkevin           #+#    #+#             */
/*   Updated: 2024/02/23 13:51:13 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*pts;

	if (nmemb == 0 || size == 0)
	{
		pts = malloc(1);
		return (pts);
	}
	if ((nmemb * size) > 2147483647 || nmemb > 2147483647 || size > 2147483647)
		return (NULL);
	else
	{
		pts = (char *)malloc((nmemb * size) * sizeof(*pts));
		if (!pts)
			return (NULL);
		ft_bzero(pts, (nmemb * size));
		return (pts);
	}
}
