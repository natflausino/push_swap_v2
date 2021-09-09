/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 23:48:03 by nbarreir          #+#    #+#             */
/*   Updated: 2021/09/08 23:26:28 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void verify_args(int argc, char **argv)
{
	int c;

	c = 0;
	while (c < argc)
	{
		checker_errors(argv, c);
		c++;
	}
}

void verify_string(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 1)
	{
		argv = ft_split(argv[0], ' ');
		while (argv[i] != NULL)
			i++;
		argc = i;
	}
}

int main(int argc, char **argv)
{
	if (argc == 1)
		return (0);

	argv = &argv[1];
	argc--;
	verify_string(argc, argv);
	verify_args(argc, argv);
	init_stack(argc, argv);

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