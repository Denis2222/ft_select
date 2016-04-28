/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 17:45:21 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/28 16:16:16 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_select *parseargv(char **argv)
{
	int			i;
	t_select	*new;
	t_select	*select = NULL;
	t_shell		*shell;

	shell = getshell();
	i = 1;
	while (argv[i])
	{
		new = newselect(argv[i]);

		select = addselect(&select, new);
		i++;
	}
	shell->list = select;
	return (select);
}
