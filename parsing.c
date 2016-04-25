/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 17:45:21 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/23 18:28:59 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_select *parseargv(int ac, char **argv)
{
	int			i;
	t_select	*new;
	t_select	*select = NULL;

	i = 1;
	while (argv[i])
	{
		new = newselect(argv[i]);
		if (i < ac - 1)
			select = addselect(&select, new, 0);
		else
			select = addselect(&select, new, 1);
		i++;
	}
	return (select);
}
