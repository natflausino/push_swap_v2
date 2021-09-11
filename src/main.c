/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 23:48:03 by nbarreir          #+#    #+#             */
/*   Updated: 2021/09/10 22:53:16 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	verify_args(int argc, char **argv)
{
	int c;

	c = 0;
	while (c < argc)
	{
		checker_errors(argv, c);
		c++;
	}
}

char	**verify_string(int *argc, char **argv)
{
	int i;

	i = 0;
	argv = ft_split(argv[0], ' ');
	while (argv[i] != NULL)
		i++;
	(*argc) = i;
	return (argv);
}

int main(int argc, char **argv)
{
	t_stack stack;

	if (argc == 1)
		return (0);
	argv = &argv[1];
	argc--;
	if (argc == 1)
		argv = verify_string(&argc, argv);
	verify_args(argc, argv);
	if (argc > 1)
	{
		init_stack(&stack, argc, argv);
		set_sort(&stack);
	}

	/*
	printf("%i\n", argc);
	int i;
	i = 0;
	while (argv[i] != NULL)
	{
		printf("%s\n", argv[i]);
		i++;
	}
	return(0); */
}