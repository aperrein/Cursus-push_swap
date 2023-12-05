/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:57:51 by aperrein          #+#    #+#             */
/*   Updated: 2023/04/20 12:42:43 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *l)
{
	while (l->next)
	{
		if (((t_stack *)l->content)->ind > ((t_stack *)l->next->content)->ind)
			return (0);
		l = l->next;
	}
	return (1);
}

void	get_pos(t_list **l)
{
	t_list	*t;
	int		i;

	t = *l;
	i = 0;
	while (t)
	{
		((t_stack *)t->content)->pos = i;
		t = t->next;
		i++;
	}
}

int	indexation(char *val, char **arg)
{
	int	m;
	int	r;

	m = 0;
	r = -1;
	while (arg[m])
	{
		if (ft_atoi(val) >= ft_atoi(arg[m]))
			r++;
		m++;
	}
	return (r);
}

t_list	*init_stack(char **arg)
{
	t_list	*l;
	t_stack	*tmp;
	int		i;

	tmp = malloc(sizeof(*tmp));
	tmp->val = ft_atoi(arg[0]);
	tmp->ind = indexation(arg[0], arg);
	tmp->pos = 0;
	l = ft_lstnew((void *)tmp);
	i = 1;
	while (arg[i])
	{
		tmp = malloc(sizeof(*tmp));
		tmp->val = ft_atoi(arg[i]);
		tmp->ind = indexation(arg[i], arg);
		tmp->pos = i;
		ft_lstadd_back(&l, ft_lstnew(tmp));
		i++;
	}
	return (l);
}
