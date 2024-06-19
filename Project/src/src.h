/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:17:18 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/07 15:39:52 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
# define SRC_H

# include "../lib/libft/libft.h"
# include <limits.h>

/*
 * LISTE
 */
typedef struct s_list
{
	int				content;
	int				pos;
	struct s_list	*next;
}					t_list;

/*
 * Fonction "Init"
 */
void				ft_init_list(t_list **a_list, char **argv, int spconf);

/*
 * Fonction "Sort"
 */
void				ft_sort(t_list **a_list, t_list **b_list);
void				ft_triple_sort(t_list **a);
void				ft_four_sort(t_list **a, t_list **b);
void				ft_five_sort(t_list **a, t_list **b);
void				ft_sort_rev(t_list **a_list, t_list **b_list);
void				ft_rotate_sort(t_list **la, t_list **lb);
void				ft_k_sort(t_list **la, t_list **lb, int calib);
int					ft_issort(t_list **c_list);
int					ft_isrevsort(t_list **c_list);

/*
 * Fonction "Swap"
 */
void				ft_swap(t_list **list, char c);
void				ft_swap_ab(t_list **alist, t_list **blist);

/*
 * Fonction "Push"
 */
void				ft_push(t_list **alist, t_list **blist, char c);

/*
 * Fonction "Rotate"
 */
void				ft_rotate(t_list **list, char c);
void				ft_rotate_rr(t_list **alist, t_list **blist);

/*
 * Fonction "Rotate Reverse"
 */
void				ft_rotate_rrc(t_list **list, char c);
void				ft_rotate_rrr(t_list **alist, t_list **blist);

/*
 * Fonction "ERROR"
 */
void				ft_error(t_list **a_list, char **arg, int spconf);

/*
 * Fonction "Utils"
 */
int					ft_get_pivot(t_list **list);
int					ft_get_pivot_pos(t_list **list);
void				ft_isddorcinlist(t_list **a_list, char **argv, int spconf);
void				ft_isdoublecquote(t_list **a_list, char **argv, int spconf);
void				ft_free(t_list **l);
int					ft_get_min(t_list **l);
int					ft_get_max(t_list **l);

/*
 * Fonction "List"
 */
int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **lf, t_list *lt);
void				ft_lstadd_back(t_list **ls, t_list *lt);
t_list				*ft_lstnew(int val);
t_list				*ft_lstlast(t_list *lst);

#endif
