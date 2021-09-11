/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 22:57:46 by nbarreir          #+#    #+#             */
/*   Updated: 2021/09/10 22:35:24 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_list *stack)
{
	int aux;
	
	aux = stack->number;
	stack->number = stack->next->number;
	stack->next->number = aux;
}

void	rotate(t_list **stack)
{
	t_list aux;
	t_list *last;

	aux = **stack;
	last = ft_lstlast(*stack);
	last->next = *stack;
	(*stack)->next = NULL;
	*stack = aux.next;
}

void	reverse_rotate(t_list **stack)
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
}

void set_rotate(t_list **a, t_list **b)
{
	if (a)
		rotate(a);
	if (b)
		rotate(b);
	if (a && !b)
		write(1, "ra\n", 3);
	else if (!a && b)
		write(1, "rb\n", 3);
	else
		write(1, "rr\n", 4);
}

void set_reverse_rotate(t_list **a, t_list **b)
{
	if (a)
		reverse_rotate(a);
	if (b)
		reverse_rotate(b);
	if (a && !b)
		write(1, "rra\n", 4);
	else if (!a && b)
		write(1, "rrb\n", 4);
	else
		write(1, "rrr\n", 4);
}

void set_swap(t_list *a, t_list *b)
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