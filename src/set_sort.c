/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:49:12 by nbarreir          #+#    #+#             */
/*   Updated: 2021/09/17 18:22:39 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int is_big_sorted(t_list *stack_a)
{
	int	value;

	value = stack_a->number;
	while (stack_a != NULL)
	{
		if (value < stack_a->next->number)
		{
			value = stack_a->next->number;
			stack_a = stack_a->next;
		}
		else
			return (0);
	}
	return (1);
}

int	get_next_min(t_list	*stack_a, t_list **temp)
{
	t_list	*duplicate;
	int		position;
	int		min_number;

	duplicate = ft_lstduplicate(stack_a);
	sort_duplicate(&duplicate);
	position = equal_value(duplicate, (*temp)->next->number);
	min_number = find_position(duplicate, position);
	if (min_number == ft_lstlast(duplicate)->number)
	{
		ft_lst_free(&duplicate);
		return (min_number);
	}
	else
		min_number = find_position(duplicate, position + 1);
	ft_lst_free(&duplicate);
	return (min_number);
}

void	merge_sorted(t_list **stack_a, t_list **stack_b, t_list *temp)
{
	t_list	*duplicate;
	t_list	*tmp;

	duplicate = ft_lstduplicate(*stack_b);
	sort_duplicate(&duplicate);
	while (ft_lstsize(*stack_b))
	{
		if ((*stack_b)->number == duplicate->number)
		{
			set_push(stack_a, stack_b, 'a');
			tmp = duplicate->next;
			if (ft_lstsize(*stack_b) && (*stack_b)->number != tmp->number
				&& (*stack_b)->number != maximum_value(*stack_b))
				set_rotate(stack_a, stack_b);
			else
				set_rotate(stack_a, NULL);
		}
		else if ((*stack_b)->number == maximum_value(*stack_b))
			set_push(stack_a, stack_b, 'a');
		else
			set_rotate(NULL, stack_b);
	}
	while (ft_lstlast(*stack_a)->number != temp->next->number)
		set_rotate(stack_a, NULL);
	temp->next->number = get_next_min(*stack_a, &temp);
	ft_lst_free(&duplicate);
}

int check_bigger(t_list *stack, int value)
{
	while (stack != NULL)
	{
		if (stack->number > value)
			return (1);
		if (stack->next == NULL)
		stack = stack->next;
	}
	return (0);
}

void	merge_max_to_a(t_list **stack_a, t_list **stack_b, t_list *temp)
{	
	t_list	*aux;
	int	i;

	i= 200;
	aux = temp;
	//generate_block(*stack_b, &temp, 0);
	//while (check_bigger(*stack_b, temp->next->number))
	while (ft_lstsize(*stack_b) != 0)
	{
		//printf("MINIMO: %i, numero %i\n", minimum_value(*stack_b), (*stack_b)->number);
		if ((*stack_b)->number == minimum_value(*stack_b))
		{
			//printf("MINIMO: %i, numero %i\n", minimum_value(*stack_b), (*stack_b)->number);
			//if (*stack_b == aux)
			//	aux = (*stack_b)->next;
			set_push(stack_a, stack_b, 'a');
			//*stack_b = aux;
			set_rotate(stack_a, NULL);
			/*if ((*stack_b) && (*stack_b)->number != minimum_value(*stack_b)
				&& (*stack_b)->number <= temp->next->number)
				set_rotate(stack_a, stack_b);
			else
				set_rotate(stack_a, NULL);*/
		}
		/*else if ((*stack_b)->number > temp->next->number)
		{
			//if (*stack_b == aux)
			//	aux = (*stack_b)->next;
			//set_push(stack_a, stack_b, 'a');
			// *stack_b = aux;
		}*/
		else
			set_rotate(NULL, stack_b);
	}
}

void	rotate_to_sort(t_list **stack_a, t_list *temp)
{
	t_list	*duplicate;
	int		number;
	int		index;

	duplicate = ft_lstduplicate(*stack_a);
	ft_lstadd_front(&duplicate, ft_lstnew(temp->number));
	sort_duplicate(&duplicate);
	number = find_position(duplicate, equal_value(duplicate, temp->number) - 1);
	ft_lst_free(&duplicate);
	index = equal_value(*stack_a, number);
	if (number == INT_MIN || index == INT_MIN)
		return ;
	if (index <= ft_lstsize(*stack_a) / 2)
	{
		while (ft_lstlast(*stack_a)->number != number) //bruxaria nivel choi máxima
		{
			write(1, "Rotate_to_sort\n", 15);
			set_rotate(stack_a, NULL);
		}
	}
	else
	{
		while (ft_lstlast(*stack_a)->number != number)
		{
			write(1, "Reverse_to_sort\n", 16);
			set_reverse_rotate(stack_a, NULL);
		} //bruxaria nivel choi máxima
	}
}

void	swap_temp(t_list **stack)
{
	int	aux;

	aux = (*stack)->number;
	(*stack)->number = (*stack)->next->number;
	(*stack)->next->number = aux;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*elem;

	if (!*lst)
		return ;

	elem = (*lst)->next;
	free(*lst);
	*lst = elem;
}

void	print(t_list *stack_a, t_list *stack_b, t_list *temp)
{
	t_list	*node;
	t_list	*test;
	t_list	*tmp;

	node = stack_a;
	while (node)
	{
		printf("Stack a: %i\n", node->number);
		node = node->next;
	}
	test = stack_b;
	while (test)
	{
		printf("Stack b: %i\n", test->number);
		test = test->next;
	}
	tmp = temp;
	while (tmp)
	{
		printf("Temp: %i\n", tmp->number);
		tmp = tmp->next;
	}
	printf("////////////////\n");
}

void	sort_big(t_list **stack_a, t_list **stack_b, t_list **temp, int index)
{
	//print(*stack_a, *stack_b, *temp);
	if (ft_lstsize(*temp) == 1)
	{
		ft_lst_free(temp);
		return ;
	}
	if (index_counter(*stack_a, *temp) >= 20 && (ft_lstsize(*temp) == 2))
		generate_block(*stack_a, temp, 1);
	if (!ft_lstsize(*stack_b))
	{
		split_block(stack_a, stack_b, *temp);
		rotate_to_sort(stack_a, *temp);
	}
	if (ft_lstsize(*stack_b))
	{
		//print(*stack_a, *stack_b, *temp);
		merge_max_to_a(stack_a, stack_b, *temp);
	}
	/*else
	{
		print(*stack_a, *stack_b, *temp);
		//merge_sorted(stack_a, stack_b, *temp);
	}*/
	//exit(0);
	//print(*stack_a, *stack_b, *temp);
	//merge_sorted(stack_a, stack_b, *temp);
	ft_lstclear(temp);
	sort_big(stack_a, stack_b, temp, ++index);
}

void	sort_five(t_stack *stack)
{
	while (ft_lstsize(stack->stack_a) > 3)
		send_min(stack, &stack->stack_a, &stack->stack_b);
	sort_three(stack);
	while (ft_lstsize(stack->stack_b))
		set_push(&stack->stack_a, &stack->stack_b, 'a');
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
	else if (!is_stack_sorted(stack->stack_a))
	{
		if (stack->len_args <= 19)
			sort_five(stack);
		else
		{
			temp = ft_lstnew(minimum_value(stack->stack_a));
			ft_lstadd_back(&temp, ft_lstnew(maximum_value(stack->stack_a)));
			sort_big(&stack->stack_a, &stack->stack_b, &temp, 0);
		}
	}
}
