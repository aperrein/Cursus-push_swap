/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:01:57 by aperrein          #+#    #+#             */
/*   Updated: 2023/04/20 12:34:11 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_action_bis(t_list **la, t_list **lb, char *line, char **arg)
{
	if (ft_strncmp(line, "rra\n", 4) == 0)
		rrotate_stack(la);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrotate_stack(lb);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
	{
		rrotate_stack(la);
		rrotate_stack(lb);
	}
	else
	{
		free(line);
		error_init(arg, "Wrong instruction", la, lb);
	}
}

void	do_action(t_list **la, t_list **lb, char *line, char **arg)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		swap_stack(*la);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		swap_stack(*lb);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
	{
		swap_stack(*la);
		swap_stack(*lb);
	}
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		push_stack(lb, la);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		push_stack(la, lb);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		rotate_stack(la);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rotate_stack(lb);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
	{
		rotate_stack(la);
		rotate_stack(lb);
	}
	else
		do_action_bis(la, lb, line, arg);
}

void	checking(t_list **la, t_list **lb, char **arg)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		do_action(la, lb, line, arg);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(*la) && !(*lb))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char *argv[])
{
	t_list	*lst_a;
	t_list	*lst_b;
	char	**arg;

	arg = start_check(argc, argv);
	lst_b = NULL;
	lst_a = init_stack(arg);
	checking(&lst_a, &lst_b, arg);
	error_init(arg, 0, &lst_a, &lst_b);
	return (0);
}
