/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 16:41:03 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/07 16:41:06 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstrev(t_list *lst)
{
	t_list *out;

	out = NULL;
	while (lst)
	{
		ft_lstadd(&out, ft_lstnew(lst->content, lst->content_size));
		lst = lst->next;
	}
	return (out);
}
