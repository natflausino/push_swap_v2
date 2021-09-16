/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:29:58 by csantos-          #+#    #+#             */
/*   Updated: 2021/09/15 23:07:26 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	move_to_top(t_list *stack_a, t_list *temp)
{
	int	first;
	int	max;
	int	min;

	min = temp->number;
	max = temp->next->number;
	first = 0;
	while (stack_a != NULL)
	{
		if (stack_a->number >= min && stack_a->number <= max)
			return (first);
		first++;
		stack_a = stack_a->next;
	}
	return (first);
}

void	split_block(t_list **stack_a, t_list **stack_b, t_list *temp)
{
	int	block_size;
	int	first;
	t_stack stack;

	block_size = index_counter(*stack_a, temp);
	while (ft_lstsize(*stack_b) < block_size)
	{
		first = move_to_top(*stack_a, temp);
		while (first--)
			set_rotate(stack_a, 0);
		set_push(stack_a, stack_b, 'b');
	}
}

int find_position(t_list *stack, int position)
{
	int i;
	
	i = 0;
	while (stack != NULL)
	{
		if (i == position)
			return (stack->number);
		stack = stack->next;
		i++;
	}
	return (INT_MIN);
}

void	generate_block(t_list *stack_a, t_list **temp, int flag)
{
	t_list *duplicate;
	int	min_ind;;
	int max_ind;
	int	new;

	duplicate = ft_lstduplicate(stack_a);
	sort_duplicate(&duplicate);
	if (flag)
	{
		min_ind = equal_value(duplicate, (*temp)->number);
		max_ind = equal_value(duplicate, (*temp)->next->number);
		new = find_position(duplicate, ((max_ind - min_ind) / 2) + min_ind + 3);
	}
	else
		new = find_position(duplicate, (ft_lstsize(duplicate) / 2));
	ft_lstadd_front(temp, ft_lstnew(new));
	sort_duplicate(temp);
	ft_lst_free(&duplicate);
}

t_list	*merge_sorted_duplicate(t_list *first, t_list *second)
{
	if (!first)
		return (second);
	if (!second)
		return (first);
	if (first->number < second->number)
	{
		first->next = merge_sorted_duplicate(first->next, second);
		return (first);
	}
	else
	{
		second->next = merge_sorted_duplicate(first, second->next);
		return (second);
	}
}

t_list	*find_middle(t_list *stack)
{
	t_list	*future;
	t_list	*present;

	future = stack;
	present = stack;
	while (future->next && future->next->next)
	{
		future = future->next->next;
		present = present->next;
	}
	future = present->next;
	present->next = 0;
	return (future);
}

void	sort_duplicate(t_list **duplicate)
{
	t_list	*first;
	t_list	*second;

	first = *duplicate;
	if (!first || !first->next)
		return ;
	second = find_middle(first);
	sort_duplicate(&first);
	sort_duplicate(&second);
	*duplicate = merge_sorted_duplicate(first, second);
	
}

int	index_counter(t_list *stack_a, t_list *temp)
{
	t_list *duplicate;
	int min_ind;
	int max_ind;

	duplicate = ft_lstduplicate(stack_a);
	sort_duplicate(&duplicate);
	min_ind = equal_value(duplicate, temp->number);
	max_ind = equal_value(duplicate, temp->next->number);
	ft_lst_free(&duplicate);
	return (max_ind - min_ind + 1);
}
