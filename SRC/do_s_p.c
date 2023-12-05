/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_s_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:57:12 by aperrein          #+#    #+#             */
/*   Updated: 2023/04/12 13:06:33 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_list *l)
{
	int	tmp;

	if (!l || !l->next)
		return ;
	tmp = ((t_stack *)l->content)->val;
	((t_stack *)l->content)->val = ((t_stack *)l->next->content)->val;
	((t_stack *)l->next->content)->val = tmp;
	tmp = ((t_stack *)l->content)->ind;
	((t_stack *)l->content)->ind = ((t_stack *)l->next->content)->ind;
	((t_stack *)l->next->content)->ind = tmp;
}

void	do_s(t_list **la, t_list **lb)
{
	if (la && lb)
	{
		swap_stack(*la);
		get_pos(la);
		swap_stack(*lb);
		get_pos(lb);
		ft_printf("ss\n");
	}
	else if (la)
	{
		swap_stack(*la);
		get_pos(la);
		ft_printf("sa\n");
	}
	else if (lb)
	{
		swap_stack(*lb);
		get_pos(lb);
		ft_printf("sb\n");
	}
}

void	push_stack(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	do_p(t_list **la, t_list **lb, char c)
{
	if (c == 'a')
	{
		push_stack(lb, la);
		get_pos(la);
		get_pos(lb);
		ft_printf("pa\n");
	}
	else if (c == 'b')
	{
		push_stack(la, lb);
		get_pos(la);
		get_pos(lb);
		ft_printf("pb\n");
	}
}
