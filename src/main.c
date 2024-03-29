/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 23:48:03 by nbarreir          #+#    #+#             */
/*   Updated: 2021/09/18 19:40:25 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack *stack)
{
	ft_lst_free(&stack->stack_a);
	ft_lst_free(&stack->stack_b);
}

void	verify_args(int argc, char **argv)
{
	int	c;

	c = 0;
	while (c < argc)
	{
		checker_errors(argv, c);
		c++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc == 1)
		return (0);
	argv = &argv[1];
	argc--;
	verify_args(argc, argv);
	if (argc > 1)
	{
		init_stacks(&stack, argc, argv);
		set_sort(&stack);
		free_stack(&stack);
	}
}
