/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:11:22 by aperrein          #+#    #+#             */
/*   Updated: 2023/04/20 12:42:57 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_list **la, t_list **lb)
{
	int	max_bit;
	int	i;
	int	j;
	int	t;

	i = 0;
	max_bit = 0;
	t = ((t_stack *)ft_lstlast(*la)->content)->pos;
	while (t >> max_bit)
		max_bit++;
	while (i < max_bit)
	{
		j = 0;
		while (j <= t)
		{
			if ((((t_stack *)(*la)->content)->ind >> i) & 1)
				do_r(la, 0);
			else
				do_p(la, lb, 'b');
			j++;
		}
		while (*lb)
			do_p(la, lb, 'a');
		i++;
	}
}

void	four_sort(t_list **la, t_list **lb, int t)
{
	if (((t_stack *)(*la)->next->content)->ind == t - 4)
		do_s(la, 0);
	else if (((t_stack *)ft_lstlast(*la)->content)->ind == t - 4)
		do_rr(la, 0);
	else if (((t_stack *)(*la)->content)->ind != t - 4)
	{
		do_r(la, 0);
		do_r(la, 0);
	}
	if (is_sorted(*la))
		return ;
	do_p(la, lb, 'b');
	three_sort(la, t);
	do_p(la, lb, 'a');
}

void	five_sort(t_list **la, t_list **lb, int t)
{
	if (((t_stack *)(*la)->next->content)->ind == 0)
		do_s(la, 0);
	else if (((t_stack *)ft_lstlast(*la)->content)->ind == 0)
		do_rr(la, 0);
	else if (((t_stack *)(*la)->next->next->content)->ind == 0)
	{
		do_r(la, 0);
		do_r(la, 0);
	}
	else if (((t_stack *)(*la)->content)->ind != 0)
	{
		do_rr(la, 0);
		do_rr(la, 0);
	}
	if (is_sorted(*la))
		return ;
	do_p(la, lb, 'b');
	four_sort(la, lb, t);
	do_p(la, lb, 'a');
}

void	three_sort(t_list **l, int t)
{
	if (is_sorted(*l))
		return ;
	if (((t_stack *)(*l)->content)->ind == t - 1)
		do_r(l, 0);
	else if (((t_stack *)(*l)->next->content)->ind == t - 1)
		do_rr(l, 0);
	if (!is_sorted(*l))
		do_s(l, 0);
}

void	choice_sort(t_list **la, t_list **lb)
{
	int	t;

	t = ft_lstsize(*la);
	if (is_sorted(*la))
		return ;
	else if (t <= 3)
		three_sort(la, t);
	else if (t == 4)
		four_sort(la, lb, t);
	else if (t == 5)
		five_sort(la, lb, t);
	else
		radix_sort(la, lb);
}
