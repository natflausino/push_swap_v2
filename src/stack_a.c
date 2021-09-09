/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 23:25:25 by nbarreir          #+#    #+#             */
/*   Updated: 2021/09/08 23:28:31 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int init_stack(int argc, char **argv)
{
	int i;
	double temp;
	t_list *stack_a;

	stack_a = NULL;
	i = 0;
	while (i < argc)
	{
		t_list *number;

		number = (t_list *)malloc(sizeof(t_list));
		if (!number)
			return (1);
		temp = ft_atoll(argv[i]);
		number->number = temp;
		number->next = NULL;
		ft_lstadd_back(&stack_a, number);
		i++;
	}

/*
	t_list *node;
	node = stack_a;

	while (node)
	{
		printf("%i\n", node->number);
		node = node->next;
	}
*/
	return (0);
}