/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_select.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 16:37:43 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/02 08:29:47 by dmoureu-         ###   ########.fr       */
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

t_select	*addselect(t_select **list, t_select *elem)
{
	t_select	*current;
	t_select	*first;

	first = *list;
	current = *list;
	if (!*list)
	{
		elem->cursor = 1;
		elem->next = elem;
		elem->prev = elem;
		*list = elem;
	}
	else
	{
		while (current->next && current->next != first)
			current = current->next;
		elem->prev = current;
		elem->next = first;
		first->prev = elem;
		current->next = elem;
	}
	return (*list);
}

static void	viewelem(t_select *current, t_shell *shell, int i)
{
	if (current->select)
		tputs(tgetstr("mr", NULL), 1, putintc);
	if (current->cursor)
		tputs(tgetstr("us", NULL), 1, putintc);
	if (current->cursor)
		ft_dprintf(0, "{red}[⪢%-*s]{eoc}", shell->sizemax, current->name);
	else
		ft_dprintf(0, "{red}[ %-*s]{eoc}", shell->sizemax, current->name);
	if (current->select)
		tputs(tgetstr("me", NULL), 1, putintc);
	if (current->cursor)
		tputs(tgetstr("ue", NULL), 1, putintc);
	if (i % (shell->wbl) == 0)
		ft_dprintf(STDIN_FILENO, "\n");
}

void		viewselect(t_shell *shell)
{
	t_select	*current;
	t_select	*first;
	int			tour;
	int			i;

	shell->sizemax = selectmaxstr(shell->list);
	shell->wbl = wordbyline(shell->list, shell->sz->ws_col);
	if ((selectlen(shell->list) / shell->wbl) > shell->sz->ws_row)
	{
		ft_dprintf(STDIN_FILENO, "Not enought size\n");
		return ;
	}
	current = shell->list;
	first = shell->list;
	i = 1;
	tour = 0;
	while (current && !tour)
	{
		viewelem(current, shell, i);
		if (current->next == first)
			tour = 1;
		current = current->next;
		i++;
	}
}
