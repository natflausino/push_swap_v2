/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 23:48:03 by nbarreir          #+#    #+#             */
/*   Updated: 2021/09/07 22:53:13 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int i;
	int c;

	i = 0;
	c = 0;
	if(argc == 1)
		return (0);

	argv = &argv[1];
	argc--;

	if (argc == 1)
	{
		argv = ft_split(argv[0], ' ');
		while (argv[i] != NULL)
			i++;
		argc = i;
	}
	while (c < argc)
	{
		checker_errors(argv, c);
		c++;
	}
	//printf("%i\n", argc);
	//i = 0;
	//while (argv[i] != NULL)
	//{
	//	printf("%s\n", argv[i]);
	//	i++;
	//}
	return(0);
}