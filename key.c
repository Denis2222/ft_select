/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:46:10 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/28 20:25:21 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	keyarrow(char *buffer, t_shell *shell)
{
	if (buffer[2] == 65)
		cursordown(shell);
	if (buffer[2] == 66)
		cursorup(shell);
	if (buffer[2] == 68)
		cursorprev(shell->list);
	if (buffer[2] == 67)
		cursornext(shell->list);
	if (buffer[1] == 0 && buffer[2] == 0)
		handle_quit(0);
	if (buffer[0] == 27 && buffer[1] == 91 &&
		buffer[2] == 51 && buffer[3] == 126)
		cursordel(&(shell->list));
	return (1);
}

int	keyenter(t_shell *shell)
{
	char	*str;

	str = selectreturn(shell->list);
	selectmodeoff(shell);
	if (str[ft_strlen(str) - 1] == ' ')
		str[ft_strlen(str) - 1] = '\0';
	ft_dprintf(STDOUT_FILENO, str);
	free(str);
	str = NULL;
	exit(0);
}

int	key(char *buffer, t_shell *shell)
{
	if (buffer[0] == 27)
		return (keyarrow(buffer, shell));
	else if (buffer[0] == 32)
		selectcursor(shell->list);
	else if (buffer[0] == 127)
		cursordel(&(shell->list));
	else if (buffer[0] == 10)
		keyenter(shell);
	else if (buffer[0] == 4)
		handle_quit(0);
	else if (ft_isalnum(buffer[0]))
		cursornextto(shell->list, buffer[0]);
	return (1);
}
