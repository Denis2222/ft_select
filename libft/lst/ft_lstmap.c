/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 21:42:14 by dmoureu-          #+#    #+#             */
/*   Updated: 2015/11/27 13:12:05 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*begin_list;

	begin_list = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		if (!begin_list)
		{
			begin_list = (f)(lst);
			lst = lst->next;
			new = begin_list;
		}
		else
		{
			new->next = (f)(lst);
			new = new->next;
			lst = lst->next;
		}
	}
	return (begin_list);
}
