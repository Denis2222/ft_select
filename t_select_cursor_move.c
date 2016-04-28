/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_select_cursor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:46:10 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/23 19:04:42 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"


void cursornext(t_select *select)
{
	t_select *current;

	current = select;
	while (!current->cursor)
	{
		current = current->next;
	}
	if (current != current->next)
	{
		current->next->cursor = 1;
		current->cursor = 0;
	}
}

void cursorprev(t_select *select)
{
	t_select *current;

	current = select;
	while (!current->cursor)
	{
		current = current->next;
	}
	if (current != current->prev)
	{
		current->prev->cursor = 1;
		current->cursor = 0;
	}
}


void cursorup(t_shell *shell)
{
	t_select	*current;
	int			wbl;
	int			i;

	i = 0;
	wbl = wordbyline(shell->list, shell->sz->ws_col);
	current = shell->list;
	while (!current->cursor)
	{
		current = current->next;
	}
	current->cursor = 0;
	while (wbl)
	{
		current = current->next;
		wbl--;
	}
	current->cursor = 1;
}

void cursordown(t_shell *shell)
{
	t_select	*current;
	int			wbl;
	int			i;

	i = 0;
	wbl = wordbyline(shell->list, shell->sz->ws_col);
	current = shell->list;
	while (!current->cursor)
	{
		current = current->next;
	}
	current->cursor = 0;
	while (wbl)
	{
		current = current->prev;
		wbl--;
	}
	current->cursor = 1;
}
