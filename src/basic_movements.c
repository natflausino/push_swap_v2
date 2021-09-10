/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 22:57:46 by nbarreir          #+#    #+#             */
/*   Updated: 2021/09/10 00:38:32 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_stack *stack)
{
	int aux;

	aux = stack->stack_a->number;
	stack->stack_a->number = stack->stack_a->next->number;
	stack->stack_a->next->number = aux;
	write(1, "sa\n", 3);
}

void	rotate_a(t_list **stack)
{
	t_list aux;
	t_list *last;

	aux = **stack;
	last = ft_lstlast(*stack);
	last->next = *stack;
	(*stack)->next = NULL;
	*stack = aux.next;
	write(1, "ra\n", 3);
}

void	reverse_rotate_a(t_list **stack)
{
	int i;
	int j;
	t_list *last;

	j = 0;
	i = ft_lstsize(*stack);
	last = ft_lstlast(*stack);
	ft_lstadd_front(stack, last);
	while (++j < i)
		*stack = (*stack)->next;
	(*stack)->next = NULL;
	*stack = last;
	write(1, "rra\n", 4);
}
