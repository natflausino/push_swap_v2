/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 00:06:42 by nbarreir          #+#    #+#             */
/*   Updated: 2021/09/11 21:32:56 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	exit_errors(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
	return (1);
}

void	checker_duplicate(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[j])
		{
			if (i != j && ft_strncmp(argv[i], argv[j], sizeof(argv[i])) == 0)
				exit_errors();
			j++;
		}
		i++;
	}
}

void	checker_errors(char **argv, int i)
{
	int		j;
	double	temp;

	j = 0;
	temp = 0;
	if (argv[i][j] == '-')
	{
		j++;
		if (!(argv[i][j]))
			exit_errors();
	}
	while (argv[i][j])
	{
		if (!(ft_isdigit(argv[i][j])))
			exit_errors();
		j++;
	}
	checker_duplicate(argv);
	temp = ft_atoll(argv[i]);
	if (temp > INT_MAX || temp < INT_MIN)
		exit_errors();
}
