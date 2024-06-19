/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:50:58 by phkevin           #+#    #+#             */
/*   Updated: 2024/02/23 15:51:00 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		index;
	char	*dest;

	dest = (char *) malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		dest[index] = s[index];
		index++;
	}
	dest[index] = 0;
	return (dest);
}
