/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:46:10 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/23 19:04:42 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
int lol(int c)
{
	write(STDIN_FILENO, &c, 1);
	return (0);
}


void exitprg(void)
{
	tputs(tgetstr("te", NULL), 1, lol);
	exit(0);
}

void handle_winch(int sig) {
	(void)sig;
	t_shell	*shell;

	shell = getshell(NULL);
	updateshell(shell);
	tputs(tgetstr("cl", NULL), 1, lol);
	viewselect(shell);
	ft_dprintf(STDIN_FILENO,"clear move !\n");
}

void handle_stop(int sig)
{
	(void)sig;
	struct termios	term;

	tcgetattr(0, &term);
	term.c_lflag = (ICANON | ECHO);
	tcsetattr(0, TCSADRAIN, &term);
	tputs(tgetstr("te", NULL), 1, lol);
}

void handle_continue(int sig)
{
	(void)sig;
	struct termios	term;

	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	tcsetattr(0, TCSADRAIN, &term);
	tputs(tgetstr("ti", NULL), 1, lol);
}
char	*staticchar(char *in, int way)
{
	static char *str = NULL;

	if (way)
	{
		str = ft_strdup(in);
		return (str);
	}
	else
	{
		return (str);
	}
}


int	mainloop(int ac, char **argv)
{
	char		buffer[3];
	t_shell		*shell;

	(void)ac;
	shell = getshell(NULL);

	parseargv(argv);
	signal(SIGWINCH, handle_winch);
	signal(SIGTSTP, handle_stop);
	signal(SIGCONT, handle_continue);
	while (1)
	{
		tputs(tgetstr("cl", NULL), 1, lol);
		key(buffer, shell);
		viewselect(shell);
		//exit(0);
		bzero(buffer, 3);
		read(0, buffer, 3);
		updateshell(shell);
	}
	return (0);
}


int	main(int ac, char **argv)
{
	//t_shell			*shell;
	char			*name_term;

	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) == ERR)
		return (-1);

	if (ac < 2)
		exit(1);

	mainloop(ac, argv);
	return (0);
}
