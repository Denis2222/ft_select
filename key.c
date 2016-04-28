/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:46:10 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/28 18:06:48 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int key(char *buffer, t_shell *shell)
{
	ft_dprintf(STDIN_FILENO,"[%d %d %d %d]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
	if (buffer[0] == 27)
	{
		if (buffer[2] == 65)
			cursordown(shell);
		if (buffer[2] == 66)
			cursorup(shell);
		if (buffer[2] == 68)
			cursorprev(shell->list);
		if (buffer[2] == 67)
			cursornext(shell->list);
		if (buffer[1] == 0 && buffer[2] == 0) //ECHAP
			exitprg();
		if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 51 && buffer[3] == 126)
			cursordel(&(shell->list));
		return (1);
	}
	else if (buffer[0] == 32)
	{
		selectcursor(shell->list);
		cursornext(shell->list);
	}
	else if (buffer[0] == 127)
	{
		//delete
		cursordel(&(shell->list));
	}
	else if (buffer[0] == 10) //ENTER
	{
		selectmodeoff(shell);
		ft_dprintf(STDOUT_FILENO, selectreturn(shell->list));
		exit(0);
	}
	else if (buffer[0] == 4)
		exitprg();
	return (1);
}
