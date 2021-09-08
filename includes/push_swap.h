/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 23:13:59 by nbarreir          #+#    #+#             */
/*   Updated: 2021/09/07 23:45:31 by nbarreir         ###   ########.fr       */
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

void						checker_errors(char **argv, int i);
void	checker_duplicate(char **argv);
int							exit_errors(void);

int							ft_isdigit(int c);
int							ft_isspace(int chr);
char						**ft_split(char const *s, char c);
long long int		ft_atoll(char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif