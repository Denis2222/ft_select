/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_select_fct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:46:10 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/28 21:12:41 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

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

int		wordbyline(t_select *select, int ws_col)
{
	int	sizemax;
	int	wordbyline;

	sizemax = selectmaxstr(select);
	wordbyline = ws_col / (sizemax + 5);
	return (wordbyline);
}
