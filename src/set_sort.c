/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:49:12 by nbarreir          #+#    #+#             */
/*   Updated: 2021/09/14 23:15:51 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int equal_value(t_list *stack, int value)
{
	int i;
	
	i = 0;
	while (stack != NULL)
	{
		if (stack->number == value)
			return (i);
		stack = stack->next;
		i++;
	}
	return (INT_MIN);
}

int maximum_value(t_list *stack)
{
	int	value;

	value = stack->number;
	while (stack != NULL)
	{
		if (stack->number > value)
		{
			value = stack->number;
		}
		stack = stack->next;
	}
	return (value);
}

int minimum_value(t_list *stack)
{
	int	value;

	value = stack->number;
	while (stack != NULL)
	{
		if (stack->number < value)
		{
			value = stack->number;
		}
		stack = stack->next;
	}
	return (value);
}

void	send_min(t_stack *stack, t_list **stack_x, t_list **stack_y)
{
	int min_num;

	min_num = minimum_value(*stack_x);
	while ((*stack_x)->number != min_num)
	{
		if ((*stack_x)->next->number != min_num)
			set_reverse_rotate(stack_x, NULL);
		else
			set_rotate(stack_x, NULL);
	}
	set_push(stack, 'b');
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
	find_middle(duplicate);
	sort_duplicate(&duplicate);
	ft_lst_free(&duplicate);
	return (max_ind - min_ind + 1);
}

void	sort_big(t_list **stack_a, t_list **stack_b, t_list **temp, int index)
{
	if (ft_lstsize(*temp) != 2)
	{
		ft_lst_free(temp);
		return ;
	}
	index_counter(*stack_a, *temp);
	//if (index_counter(*stack->stack_a, *temp) >= 20)
	//{
	//	
	//}
}

void	sort_five(t_stack *stack)
{
	while (stack->len_a > 3)
		send_min(stack, &stack->stack_a, &stack->stack_b);
	sort_three(stack);
	while (stack->len_b)
		set_push(stack, 'a');
}

void	sort_three_b(t_stack *stack, int first, int second, int third)
{
	if (first > second && second > third && third < first)
	{
		set_swap(stack->stack_a, NULL);
		set_reverse_rotate(&stack->stack_a, NULL);
	}
	else if (first > second && second < third && third < first)
		set_rotate(&stack->stack_a, NULL);
	else
		return ;
}

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
	sort_three_b(stack, first, second, third);
}

void	set_sort(t_stack *stack)
{
	t_list	*temp;

	if (stack->len_args == 2)
	{
		if (stack->stack_a->number < stack->stack_a->next->number)
			return ;
		else
			set_swap(stack->stack_a, NULL);
	}
	else if (stack->len_args == 3)
		sort_three(stack);
	else if (stack->len_args <= 19)
		sort_five(stack);
	else
	{
		temp = ft_lstnew(minimum_value(stack->stack_a));
		ft_lstadd_back(&temp, ft_lstnew(maximum_value(stack->stack_a)));
		sort_big(&stack->stack_a, &stack->stack_b, &temp, 1);
		ft_lst_free(&temp);
	}
}