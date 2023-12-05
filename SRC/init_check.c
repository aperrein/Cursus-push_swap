/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:48:36 by aperrein          #+#    #+#             */
/*   Updated: 2023/04/20 11:43:05 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_init(char **arg, char *s, t_list **la, t_list **lb)
{
	int	m;

	m = 0;
	if (arg)
	{
		while (arg[m])
			free(arg[m++]);
	}
	free(arg);
	if (la)
		ft_lstclear(la, free);
	if (lb)
		ft_lstclear(lb, free);
	if (s)
		ft_printf("%s\n", s);
	exit(0);
}

void	check_doublon(char **arg)
{
	int	m;
	int	i;

	m = 0;
	while (arg[m])
	{
		i = 1;
		while (arg[m + i])
		{
			if (ft_atoi(arg[m]) == ft_atoi(arg[m + i]))
				error_init(arg, "Error\nDoublon", 0, 0);
			i++;
		}
		m++;
	}
}

void	check_atoi(char	**arg, int m)
{
	int			i;
	int			s;
	long int	r;	

	i = 0;
	r = 0;
	s = 1;
	if (arg[m][i] == '-' || arg[m][i] == '+')
	{
		if (arg[m][i] == '-')
			s = -1;
		i++;
	}
	while (arg[m][i])
	{
		if (arg[m][i] < '0' || arg[m][i] > '9')
			error_init(arg, "Error\nNot number", 0, 0);
		r = r * 10 + arg[m][i++] - '0';
		if (r * s > 2147483647 || r * s < -2147483648)
			error_init(arg, "Error\nNot int", 0, 0);
	}
}

char	**start_check(int argc, char *argv[])
{
	char	**arg;
	int		m;

	if (argc < 2)
		exit(1);
	if (argc == 2)
		arg = ft_split(argv[1], ' ');
	if (argc > 2)
	{
		m = 0;
		arg = malloc(sizeof(char *) * argc);
		while (argv[m + 1])
		{
			arg[m] = ft_strdup(argv[m + 1]);
			m++;
		}
		arg[m] = NULL;
	}
	m = 0;
	while (arg[m])
		check_atoi(arg, m++);
	check_doublon(arg);
	return (arg);
}
