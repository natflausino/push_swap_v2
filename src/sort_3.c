/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:49:12 by nbarreir          #+#    #+#             */
/*   Updated: 2021/09/11 00:20:46 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->stack_a->number;
	second = stack->stack_a->next->number;
	third = stack->stack_a->next->next->number;
	if (first < second && second > third && first < third)
	{
		set_rotate(&stack->stack_a, NULL);
		set_swap(stack->stack_a, NULL);
		set_reverse_rotate(&stack->stack_a, NULL);
	}
	else if (first > second && second < third && third > first)
		set_swap(stack->stack_a, NULL);
	else if (first < second && first > third && second > third)
		set_reverse_rotate(&stack->stack_a, NULL);
	else if (first > second && second > third)
	{
		set_swap(stack->stack_a, NULL);
		set_reverse_rotate(&stack->stack_a, NULL);
	}
	else if (first > second && second < third)
		set_rotate(&stack->stack_a, NULL);
	else
		return ;
}

void	set_sort(t_stack *stack)
{
	if (stack->len_stack == 2)
	{
		if (stack->stack_a->number < stack->stack_a->next->number)
			return ;
		else
			set_swap(stack->stack_a, NULL);
	}
	if (stack->len_stack == 3)
	{
		sort_three(stack);
	}

	/*t_list	*node;
	node = stack->stack_a;
	while (node)
	{
		printf("%i\n", node->number);
		node = node->next;
	}*/
}
