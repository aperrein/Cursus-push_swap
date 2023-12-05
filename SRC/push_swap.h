/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:50:15 by aperrein          #+#    #+#             */
/*   Updated: 2023/04/20 14:47:14 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int				val;
	int				ind;
	int				pos;
}	t_stack;

void	error_init(char **arg, char *s, t_list **la, t_list **lb);
void	get_pos(t_list **l);
void	do_s(t_list **la, t_list **lb);
void	push_stack(t_list **src, t_list **dest);
void	swap_stack(t_list *l);
void	rrotate_stack(t_list **l);
void	rotate_stack(t_list **l);
void	do_r(t_list **la, t_list **lb);
void	do_p(t_list **la, t_list **lb, char c);
void	do_rr(t_list **la, t_list **lb);
void	choice_sort(t_list **la, t_list **lb);
void	three_sort(t_list **l, int t);
int		is_sorted(t_list *l);
char	**start_check(int argc, char *argv[]);
t_list	*init_stack(char **arg);

#endif
