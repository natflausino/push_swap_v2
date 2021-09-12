/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 22:57:46 by nbarreir          #+#    #+#             */
/*   Updated: 2021/09/12 00:25:43 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_list **stack_x, t_list **stack_y) //top x -> top y
{
	t_list	*aux;

	if (*stack_x)
	{
		aux = *stack_x;
		*stack_x = aux->next;
		if (!*stack_y)
			aux->next = 0;
		else
			aux->next = *stack_y;
		*stack_y = aux;
	}
}

void	set_push(t_stack *stack, int c)
{
		if (c == 'a')
		{
			push(&stack->stack_b, &stack->stack_a);
			stack->len_a++;
			stack->len_b--;
			write(1, "pa\n", 3);
		}
		if (c == 'b')
		{
			push(&stack->stack_a, &stack->stack_b);
			stack->len_b++;
			stack->len_a--;
			write(1, "pb\n", 3);
		}
}

void	swap(t_list *stack)
{
	int	aux;

	aux = stack->number;
	stack->number = stack->next->number;
	stack->next->number = aux;
}

void	set_swap(t_list *a, t_list *b)
{
	if (a)
		swap(a);
	if (b)
		swap(b);
	if (a && !b)
		write(1, "sa\n", 3);
	else if (!a && b)
		write(1, "sb\n", 3);
	else
		write(1, "ss\n", 4);
}
