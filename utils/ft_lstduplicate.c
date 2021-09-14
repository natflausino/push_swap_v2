/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstduplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 00:09:23 by csantos-          #+#    #+#             */
/*   Updated: 2021/09/14 00:16:17 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ft_lstduplicate(t_list *lst)
{
	t_list	*duplicate;
	t_list	*new;

	duplicate = NULL;
	while (lst)
	{
		new = ft_lstnew(lst->number);
		if (!new)
		{
			ft_lstfree(&duplicate);
			return ;
		}
		ft_lstadd_back(&duplicate, new);
		lst = lst->next;
	}
	return (duplicate);
}