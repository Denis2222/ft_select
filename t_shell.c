/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_shell.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:45:37 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/23 19:07:05 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_shell *getshell(t_shell *shell)
{
	static t_shell *save = NULL;
	t_shell	new;
	if (save == NULL)
	{
	 	new = newshell();
		save = &new;
	}
		(void)shell;



	return (save);
}

t_shell newshell(void)
{
	t_shell shell;

	ioctl(0, TIOCGWINSZ, &shell.sz);
	shell.list = NULL;
	//ft_dprintf(STDIN_FILENO,"New shell : info h:%d w:%d\n", shell.sz.ws_row, shell.sz.ws_col);
	return (shell);
}


void updateshell(t_shell *shell)
{
	struct winsize w;

    ioctl(0, TIOCGWINSZ, &w);
	shell->sz.ws_col = w.ws_col;
	shell->sz.ws_row = w.ws_row;
}
