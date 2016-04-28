/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:46:10 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/28 20:33:11 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		putintc(int c)
{
	write(STDIN_FILENO, &c, 1);
	return (0);
}

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

int		mainloop(int ac, char **argv)
{
	char		buffer[4];
	t_shell		*shell;

	(void)ac;
	shell = getshell();
	parseargv(argv);
	signal(SIGWINCH, handle_winch);
	signal(SIGTSTP, handle_stop);
	signal(SIGCONT, handle_continue);
	signal(SIGINT, handle_quit);
	signal(SIGQUIT, handle_quit);
	signal(SIGKILL, handle_quit);
	while (1)
	{
		tputs(tgetstr("cl", NULL), 1, putintc);
		key(buffer, shell);
		viewselect(shell);
		bzero(buffer, 4);
		read(0, buffer, 4);
		updateshell(shell);
	}
	return (0);
}

int		main(int ac, char **argv)
{
	char			*name_term;

	if ((name_term = getenv("TERM")) == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Please set the environment variable TERM;");
		return (-1);
	}
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	if (ac < 2)
		exit(1);
	mainloop(ac, argv);
	return (0);
}
