/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:18:17 by aperrein          #+#    #+#             */
/*   Updated: 2023/04/20 11:41:29 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*lst_a;
	t_list	*lst_b;
	char	**arg;

	arg = start_check(argc, argv);
	lst_b = NULL;
	lst_a = init_stack(arg);
	choice_sort(&lst_a, &lst_b);
	error_init(arg, 0, &lst_a, &lst_b);
	return (0);
}
