/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:00:02 by phkevin           #+#    #+#             */
/*   Updated: 2024/02/23 16:00:05 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	int		i;
	int		len_n;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	len_n = ft_strlen(s) - start + 1;
	if (len_n > (int)len)
		len_n = len + 1;
	dest = (char *)malloc(len_n * sizeof(char));
	if (!dest || !s)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && len--)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}
