/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 02:30:12 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/07 15:39:29 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

static int	ft_isarg(char *str)
{
	int	i;

	i = 0;
	while (i < str[i])
	{
		if ((str[i] == '+' || str[i] == '-') && ft_isdigit(str[i + 1]))
			i++;
		else if ((str[i] == 9 || str[i] == 32))
			i++;
		else if (!ft_isdigit(str[i]))
			return (1);
		else
			i++;
	}
	return (0);
}

void	ft_isddorcinlist(t_list **a_list, char **argv, int spconf)
{
	int	i;
	int	ii;

	i = 0;
	while (argv[i] != NULL)
	{
		if (ft_isarg(argv[i]) == 1)
			ft_error(a_list, argv, spconf);
		if (ft_atoill(argv[i]) > INT_MAX || ft_atoill(argv[i]) < INT_MIN)
			ft_error(a_list, argv, spconf);
		ii = 0;
		while (argv[ii] != NULL)
		{
			if (ii != i && ft_atoi(argv[ii]) == ft_atoi(argv[i]))
				ft_error(a_list, argv, spconf);
			ii++;
		}
		i++;
	}
}

void	ft_isdoublecquote(t_list **a_list, char **argv, int spconf)
{
	int	i_argc;
	int	i;

	i_argc = 0;
	while (argv[i_argc])
	{
		i = 0;
		while (argv[i_argc][i])
		{
			if ((argv[i_argc][i] == '+' || argv[i_argc][i] == '-')
				&& ft_isdigit(argv[i_argc][i + 1]))
				i++;
			else if (!(argv[i_argc][i] >= 48 && argv[i_argc][i] <= 57))
				ft_error(a_list, argv, spconf);
			i++;
		}
		i_argc++;
	}
}
