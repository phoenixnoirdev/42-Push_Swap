/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:17:57 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/07 15:40:14 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/libft/libft.h"
#include "./src/src.h"

void	ft_free(t_list **l)
{
	t_list	*ll;
	t_list	*tmp;

	ll = *l;
	while (ll)
	{
		tmp = ll;
		ll = ll->next;
		free(tmp);
		tmp = NULL;
	}
	free(l);
	l = NULL;
}

void	ft_error(t_list **a_list, char **arg, int spconf)
{
	ft_putstr_fd("Error\n", 2);
	ft_free(a_list);
	if (spconf == 1)
		ft_free_split(arg);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_list		**a_list;
	t_list		**b_list;
	static char	**argsplit = NULL;

	if (argc < 2)
		return (0);
	argv++;
	a_list = (t_list **)malloc(sizeof(t_list));
	*a_list = NULL;
	if (argc == 2)
	{
		argsplit = ft_split(*argv, ' ');
		ft_init_list(a_list, argsplit, 1);
	}
	else
		ft_init_list(a_list, argv, 0);
	b_list = (t_list **)malloc(sizeof(t_list));
	*b_list = NULL;
	ft_sort(a_list, b_list);
	ft_free_split(argsplit);
	ft_free(a_list);
	ft_free(b_list);
	return (0);
}
