/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 21:13:54 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/28 21:17:30 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	handle_winch(int sig)
{
	t_shell	*shell;

	(void)sig;
	shell = getshell();
	updateshell(shell);
	tputs(tgetstr("cl", NULL), 1, putintc);
	viewselect(shell);
}

void	handle_stop(int sig)
{
	char	buf[2];
	t_shell	*shell;

	(void)sig;
	shell = getshell();
	buf[0] = shell->tiosold->c_cc[VSUSP];
	buf[1] = 0;
	selectmodeoff(shell);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, buf);
	ft_printf(" ");
}

void	handle_quit(int sig)
{
	t_shell	*shell;

	(void)sig;
	shell = getshell();
	selectmodeoff(shell);
	exit(0);
}

void	handle_continue(int sig)
{
	t_shell	*shell;

	(void)sig;
	signal(SIGTSTP, handle_stop);
	signal(SIGCONT, handle_continue);
	shell = getshell();
	selectmodeon(shell);
	tputs(tgetstr("cl", NULL), 1, putintc);
	viewselect(shell);
}
