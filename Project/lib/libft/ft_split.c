/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:25:11 by phkevin           #+#    #+#             */
/*   Updated: 2024/02/26 11:25:12 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

static int	ft_countword(char const *s, char c)
{
	int	nb;
	int	i;

	nb = 1;
	i = 1;
	if (s[0] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c)
			nb++;
		i++;
	}
	if (s[i - 1] == c)
		nb--;
	return (nb);
}

static char	*get_word(char const *s, char c, int start)
{
	char	*res;
	int		i;
	int		si;

	i = 0;
	si = 0;
	while (s[start + si] != '\0' && s[start + si] != c)
		si++;
	res = (char *)malloc((si + 1) * sizeof(char *));
	while (i < si)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	*word;
	int		i;
	int		i_res;

	if (!s)
		return (NULL);
	res = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	i = 0;
	i_res = 0;
	while (s[i] == c && *s)
		i++;
	while (i_res < ft_countword(s, c))
	{
		word = get_word(s, c, i);
		res[i_res++] = ft_strdup(word);
		i += ft_strlen(word);
		free(word);
		while (s[i] == c)
			i++;
	}
	res[i_res] = NULL;
	return (res);
}
