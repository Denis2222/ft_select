/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_shell.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:45:37 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/28 21:30:05 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_shell	*getshell(void)
{
	static t_shell *save = NULL;

	if (save == NULL)
		save = newshell();
	updateshell(save);
	return (save);
}

t_shell	*newshell(void)
{
	t_shell *shell;

	shell = (t_shell*)malloc(sizeof(t_shell));
	shell->sz = (struct winsize*)malloc(sizeof(struct winsize));
	ioctl(0, TIOCGWINSZ, shell->sz);
	shell->list = NULL;
	shell->tiosold = (struct termios*)malloc(sizeof(struct termios));
	shell->tios = (struct termios*)malloc(sizeof(struct termios));
	if (tcgetattr(0, shell->tiosold) == -1)
		return (NULL);
	tcgetattr(0, shell->tios);
	shell->tios->c_lflag &= ~(ICANON);
	shell->tios->c_lflag &= ~(ECHO);
	shell->tios->c_cc[VMIN] = 1;
	shell->tios->c_cc[VTIME] = 100;
	selectmodeon(shell);
	return (shell);
}

void	updateshell(t_shell *shell)
{
	struct winsize w;

	ioctl(0, TIOCGWINSZ, &w);
	shell->sz->ws_col = w.ws_col;
	shell->sz->ws_row = w.ws_row;
}

void	selectmodeon(t_shell *shell)
{
	tcsetattr(0, TCSADRAIN, shell->tios);
	tputs(tgetstr("vi", NULL), 1, putintc);
	tputs(tgetstr("ti", NULL), 1, putintc);
}

void	selectmodeoff(t_shell *shell)
{
	tcsetattr(0, TCSADRAIN, shell->tiosold);
	tputs(tgetstr("te", NULL), 1, putintc);
	tputs(tgetstr("ve", NULL), 1, putintc);
}
