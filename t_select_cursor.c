/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_select_cursor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:46:10 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/28 19:06:09 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	cursordel(t_select **select)
{
	t_select *current;
	t_select *last;
	t_select *next;
	t_select *first;

	first = *select;
	last = *select;
	current = *select;

	if (selectlen(*select) < 2)
	{
		handle_quit(0);
	}
	while (!current->cursor)
	{
		last = current;
		current = current->next;
	}
	next = current->next;
	if (current == first)
	{
		current->name = next->name;
		current->next = next->next;
		next->next->prev = current;
/*		free(next->name);
		next->name = NULL;
		free(next);*/
	}
	else
	{
		last->next = next;
		next->prev = last;
		next->cursor = 1;

		free(current->name);
		current->name = NULL;
		free(current);
	}



}

void selectcursor(t_select *select)
{
	t_select *current;

	current = select;
	while (!current->cursor)
	{
		current = current->next;
	}
	current->select = current->select ? 0 : 1;
}

char	*selectreturn(t_select *select)
{
	t_select	*current;
	t_select	*first;
	char 		*out;
	char 		*tmp;
	int			i;

	current = select;
	first = select;
	i = 0;
	out =ft_strdup("");
	while (i == 0 || current != first)
	{
		if (current->select)
		{
			tmp = out;
			out = ft_strjoin(out, current->name);
			ft_strdel(&tmp);
			tmp = out;
			out = ft_strjoin(out, " ");
			ft_strdel(&tmp);
		}
		current = current->next;
		i++;
	}
	return (out);
}
