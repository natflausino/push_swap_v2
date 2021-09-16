/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 23:48:03 by nbarreir          #+#    #+#             */
/*   Updated: 2021/09/16 02:13:34 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lst_free(t_list **lst)
{
	t_list	*next;

	if (!*lst)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
}

void	free_stack(t_stack *stack)
{
	ft_lst_free(&stack->stack_a);
	ft_lst_free(&stack->stack_b);
}

void	test_print(t_stack *stack)
{
	t_list	*node;
	t_list	*test;

	node = stack->stack_a;
	while (node)
	{
		printf("Stack a: %i\n", node->number);
		node = node->next;
	}
	test = stack->stack_b;
	while (test)
	{
		printf("Stack b: %i\n", test->number);
		test = test->next;
	}
		/*
	printf("%i\n", argc);
	int i;
	i = 0;
	while (argv[i] != NULL)
	{
		printf("%s\n", argv[i]);
		i++;
	}
	return(0); */
}

void	verify_args(int argc, char **argv)
{
	int	c;

	c = 0;
	while (c < argc)
	{
		checker_errors(argv, c);
		c++;
	}
}

char	**verify_string(int *argc, char **argv)
{
	int	i;

	i = 0;
	argv = ft_split(argv[0], ' ');
	while (argv[i] != NULL)
		i++;
	(*argc) = i;
	return (argv);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc == 1)
		return (0);
	argv = &argv[1];
	argc--;
	if (argc == 1)
		argv = verify_string(&argc, argv);
	verify_args(argc, argv);
	if (argc > 1)
	{
		init_stacks(&stack, argc, argv);
		set_sort(&stack);
	}
	test_print(&stack);

	free_stack(&stack);
}
