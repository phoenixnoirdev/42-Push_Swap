/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:23:08 by phkevin           #+#    #+#             */
/*   Updated: 2024/02/27 09:23:11 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_char(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	long long	nbr;
	int			nb_len;

	nbr = (long long)n;
	nb_len = ft_count_char(nbr);
	str = (char *)malloc((nb_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	str[nb_len--] = '\0';
	while (nb_len >= 0)
	{
		str[nb_len] = nbr % 10 + '0';
		nbr = nbr / 10;
		nb_len--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
