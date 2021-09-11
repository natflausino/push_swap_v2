/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:49:12 by nbarreir          #+#    #+#             */
/*   Updated: 2021/09/10 22:15:29 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//void	sort_three(t_stack *stack)
//{
//
//}

void	set_sort(t_stack *stack)
{
	if (stack->len_stack <= 3)
		set_swap(stack->stack_a, NULL);
		//sort_three(stack);

	t_list *node;
	node = stack->stack_a;
	while (node)
	{
		printf("%i\n", node->number);
		node = node->next;
	}
}