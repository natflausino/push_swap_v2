/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 23:13:59 by nbarreir          #+#    #+#             */
/*   Updated: 2021/09/10 22:14:19 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define EXIT_FAILURE 1

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int number;
	struct s_list *next;
} t_list;

typedef struct s_stack
{
	t_list *stack_a;
	t_list *stack_b;
	int	len_stack;
} t_stack;

/*
**PUSH_SWAP
*/

void						checker_errors(char **argv, int i);
void	checker_duplicate(char **argv);
int							exit_errors(void);
int init_stack(t_stack *stack, int argc, char **argv);
void	set_sort(t_stack *stack);
//void	sort_three(t_stack *stack);
void set_rotate(t_list **a, t_list **b);
void set_swap(t_list *a, t_list *b);
void set_reverse_rotate(t_list **a, t_list **b);

/*
** BASIC_MOVEMENTS
*/
void	swap(t_stack *stack);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);

/*
**UTILS
*/

int							ft_isdigit(int c);
int							ft_isspace(int chr);
char						**ft_split(char const *s, char c);
long long int		ft_atoll(char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list *ft_lstlast(t_list *lst);
int	ft_lstsize(t_list *lst);

#endif