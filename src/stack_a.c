/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 23:25:25 by nbarreir          #+#    #+#             */
/*   Updated: 2021/09/09 22:11:51 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int init_stack(t_stack *stack, int argc, char **argv)
{
	int i;
	double temp;

	stack->stack_a = NULL;
	stack->len_stack = argc;
	i = 0;
	while (i < stack->len_stack)
	{
		t_list *number;

		number = (t_list *)malloc(sizeof(t_list));
		if (!number)
			return (1);
		temp = ft_atoll(argv[i]);
		number->number = temp;
		number->next = NULL;
		ft_lstadd_back(&stack->stack_a, number);
		i++;
	}
	return (0);
}