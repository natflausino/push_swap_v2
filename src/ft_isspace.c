/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 01:23:33 by nbarreir          #+#    #+#             */
/*   Updated: 2021/09/04 19:23:28 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isspace(int chr)
{
	if (chr == '\n' || chr == '\t' || chr == '\v' || chr == '\r'
		|| chr == '\f' || chr == ' ')
		return (1);
	else
		return (0);
}
