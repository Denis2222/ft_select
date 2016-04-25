/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_select.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 16:37:43 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/23 19:08:40 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"


t_select	*newselect(char *name)
{
	t_select *new;

	new = (t_select*)malloc(sizeof(t_select));
	new->name = ft_strdup(name);
	new->select = 0;
	new->cursor = 0;
	new->next = NULL;
	new->next = NULL;
	return (new);
}

t_select	*addselect(t_select **list, t_select *elem, int last)
{
	t_select	*cursor;
	t_select	*first;

	(void)last;
	first = *list;
	cursor = *list;
	if (!*list)
	{
		elem->cursor = 1;
		*list = elem;
	}
	else
	{
		while (cursor->next)
		{
			cursor = cursor->next;
		}
		elem->prev = cursor;
		if (last)
		{
			elem->next = first;
			first->prev = elem;
		}
		cursor->next = elem;
	}
	return (*list);
}

int		selectlen(t_select *select)
{
	t_select	*current;
	t_select	*first;
	int			i;

	current = select;
	first = select;
	i = 0;
	while (i == 0 || current != first)
	{
		current = current->next;
		i++;
	}
	return (i);
}
/*
char	*viewselect(t_select *select)
{
	if (select && select->name)
		return (select->name);
	else
		return ("empty");
}*/

size_t	selectmaxstr(t_select *select)
{
	t_select	*current;
	t_select	*first;
	size_t		max;
	int			tour;

	max = 0;
	tour = 0;
	current = select;
	first = select;
	while (current && !tour)
	{
		if (ft_strlen(current->name) > max)
			max = ft_strlen(current->name);
		if (current->next == first)
			tour = 1;
		current = current->next;
	}
	return (max);
}

int wordbyline(t_select *select, int ws_col)
{
	int	sizemax;
	int	wordbyline;

	sizemax = selectmaxstr(select);
	wordbyline = ws_col / (sizemax + 5);
	return (wordbyline);
}

void viewselect(t_select *select, t_shell shell)
{
	t_select	*current;
	t_select	*first;
	int			tour;
	int			wbl;
	int			i;
	int			sizemax;

	sizemax = selectmaxstr(select);
	wbl = wordbyline(select, shell.sz.ws_col);
	if ((selectlen(select) / wbl) > shell.sz.ws_row)
	{
		ft_dprintf(STDIN_FILENO,"Not enought size\n");
		return ;
	}
	current = select;
	first = select;
	i = 1;
	tour = 0;
	while (current && !tour)
	{
		if (current->select)
			tputs(tgetstr("mr", NULL), 1, lol);
		if (current->cursor)
			tputs(tgetstr("us", NULL), 1, lol);

		ft_dprintf(STDIN_FILENO,"{red}[ %-*s ]{eoc} ", sizemax , current->name);

		if (current->select)
			tputs(tgetstr("me", NULL), 1, lol);
		if (current->cursor)
			tputs(tgetstr("ue", NULL), 1, lol);

		if (i % (wbl) == 0)
			ft_dprintf(STDIN_FILENO, "\n");

		if (current->next == first)
			tour = 1;
		current = current->next;
		i++;
	}
}

void cursornext(t_select *select)
{
	t_select *current;

	current = select;
	while (!current->cursor)
	{
		current = current->next;
	}
	current->next->cursor = 1;
	current->cursor = 0;
}

void cursorprev(t_select *select)
{
	t_select *current;

	current = select;
	while (!current->cursor)
	{
		current = current->next;
	}
	current->prev->cursor = 1;
	current->cursor = 0;
}

void cursorup(t_select *select, t_shell shell)
{
	t_select	*current;
	int			wbl;
	int			i;

	i = 0;
	wbl = wordbyline(select, shell.sz.ws_col);
	current = select;
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

void cursordown(t_select *select, t_shell shell)
{
	t_select	*current;
	int			wbl;
	int			i;

	i = 0;
	wbl = wordbyline(select, shell.sz.ws_col);
	current = select;
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

void selectcursor(t_select *select)
{
	t_select *current;

	current = select;
	while (!current->cursor)
	{
		//ft_dprintf(STDIN_FILENO,"While !\n");
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
