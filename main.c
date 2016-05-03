/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:46:10 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/04 00:04:46 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		sig_handler(int sig)
{
	if (sig == SIGWINCH)
		handle_winch(0);
	else if (sig == SIGTSTP)
		handle_stop(0);
	else if (sig == SIGCONT)
		handle_continue(0);
	else if (sig == SIGINT)
		handle_quit(0);
	else if (sig == SIGQUIT)
		handle_quit(0);
	else if (sig == SIGKILL)
		handle_quit(0);
	else if (sig == SIGTERM)
		handle_quit(0);
	else
		ft_dprintf(STDIN_FILENO,
			"\n O YEAH GIVE ME SIGNAL Love that [%d] 💘!", sig);
}

void		ft_signal(void)
{
	int		i;

	i = 0;
	while (i < 33)
	{
		signal(i, sig_handler);
		i++;
	}
}

static int	mainloop(int ac, char **argv)
{
	char		buffer[4];
	t_shell		*shell;

	(void)ac;
	shell = getshell();
	parseargv(argv);
	ft_signal();
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

int			putintc(int c)
{
	write(STDIN_FILENO, &c, 1);
	return (0);
}

int			main(int ac, char **argv)
{
	char	*name_term;

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
