/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:30:18 by aperrein          #+#    #+#             */
/*   Updated: 2023/04/12 12:04:34 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_list **l)
{
	t_list	*temp;

	if (!*l)
		return ;
	temp = *l;
	*l = (*l)->next;
	temp->next = NULL;
	ft_lstlast(*l)->next = temp;
}

void	do_r(t_list **la, t_list **lb)
{
	if (la && lb)
	{
		rotate_stack(la);
		get_pos(la);
		rotate_stack(lb);
		get_pos(lb);
		ft_printf("rr\n");
	}
	else if (la)
	{
		rotate_stack(la);
		get_pos(la);
		ft_printf("ra\n");
	}
	else if (lb)
	{
		rotate_stack(lb);
		get_pos(lb);
		ft_printf("rb\n");
	}
}

t_list	*before_end(t_list *l)
{
	while (l && l->next && l->next->next)
		l = l->next;
	return (l);
}

void	rrotate_stack(t_list **l)
{
	t_list	*temp;
	t_list	*end;

	if (!*l)
		return ;
	temp = *l;
	end = before_end(*l);
	*l = ft_lstlast(*l);
	(*l)->next = temp;
	end->next = NULL;
}

void	do_rr(t_list **la, t_list **lb)
{
	if (la && lb)
	{
		rrotate_stack(la);
		get_pos(la);
		rrotate_stack(lb);
		get_pos(lb);
		ft_printf("rrr\n");
	}
	else if (la)
	{
		rrotate_stack(la);
		get_pos(la);
		ft_printf("rra\n");
	}
	else if (lb)
	{
		rrotate_stack(lb);
		get_pos(lb);
		ft_printf("rrb\n");
	}
}
