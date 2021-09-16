/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 23:25:25 by nbarreir          #+#    #+#             */
/*   Updated: 2021/09/15 22:51:12 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	fill_stack_a(t_stack *stack, char **argv)
{
	int		i;
	double	temp;
	t_list	*number;

	i = 0;
	while (i < stack->len_args)
	{
		number = (t_list *)malloc(sizeof(t_list));
		if (!number)
			return ;
		temp = ft_atoll(argv[i]);
		number->number = temp;
		number->next = NULL;
		ft_lstadd_back(&stack->stack_a, number);
		i++;
	}
}

int	init_stacks(t_stack *stack, int argc, char **argv)
{
	stack->stack_a = NULL;
	stack->stack_b = NULL;
	stack->len_args = argc;
	fill_stack_a(stack, argv);
	return (0);
}
