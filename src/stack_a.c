/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 23:25:25 by nbarreir          #+#    #+#             */
/*   Updated: 2021/09/18 02:27:01 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_stack_sorted(t_list *stack)
{
	while(stack->next != NULL)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	*replace_numbs(int argc, char **argv)
{
	int	*numbers1;
	int	*numbers2;
	int	cont;
	int	i;
	int	j;

	numbers1 = malloc((argc) * sizeof(int*));
	numbers2 = malloc((argc) * sizeof(int*));
	i = -1;
	while (++i < argc)
		numbers1[i] = ft_atoll(argv[i]);
	i = -1;
	while (++i < argc)
	{
		j = -1;
		cont = 0;
		while (++j < argc)
			if (numbers1[i] > numbers1[j])
				cont++;
		numbers2[i] = cont + 1;
	}
	free(numbers1);
	return(numbers2);
}

void	fill_stack_a(t_stack *stack, int argc, char **argv)
{
	int		i;
	double	temp;
	t_list	*number;
	int		*nuns;

	nuns = replace_numbs(argc, argv);
	i = 0;
	while (i < stack->len_args)
	{
		number = (t_list *)malloc(sizeof(t_list));
		if (!number)
			return ;
		temp = nuns[i];
		number->number = temp;
		number->next = NULL;
		ft_lstadd_back(&stack->stack_a, number);
		i++;
	}
	free(nuns);
}

int	init_stacks(t_stack *stack, int argc, char **argv)
{
	stack->stack_a = NULL;
	stack->stack_b = NULL;
	stack->len_args = argc;
	fill_stack_a(stack, argc, argv);
	return (0);
}
