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

int keytest(char *buffer, t_select *select, t_shell shell)
{
	ft_dprintf(STDIN_FILENO,"[%d %d %d]\n", buffer[0], buffer[1], buffer[2]);
	if (buffer[0] == 27)
	{
		if (buffer[2] == 65)
			cursordown(select, shell);
		if (buffer[2] == 66)
			cursorup(select, shell);
		if (buffer[2] == 68)
			cursorprev(select);
		if (buffer[2] == 67)
			cursornext(select);
		if (buffer[1] == 0 && buffer[2] == 0) //ECHAP
			exitprg();
		return (1);
	}
	else if (buffer[0] == 32)
		selectcursor(select);
	else if (buffer[0] == 10) //ENTER
	{
		tputs(tgetstr("te", NULL), 1, lol);
		ft_dprintf(STDOUT_FILENO, selectreturn(select));
		exit(0);
	}
	else if (buffer[0] == 4)
		exitprg();
	return (1);
}


void handle_winch(int sig) {
	(void)sig;
	tputs(tgetstr("cl", NULL), 1, lol);
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

int	mainloop(int ac, char **argv)
{
	char		buffer[3];
	t_shell		shell;
	t_select	*select;

	shell = newshell();
	select = parseargv(ac, argv);
	signal(SIGWINCH, handle_winch);
	signal(SIGTSTP, handle_stop);
	signal(SIGCONT, handle_continue);
	while (1)
	{

		tputs(tgetstr("cl", NULL), 1, lol);
		keytest(buffer, select, shell);
		viewselect(select, shell);
		bzero(buffer, 3);
		read(0, buffer, 3);
		updateshell(&shell);

	}
	return (0);
}


int	main(int ac, char **argv, char **env)
{
	char			*name_term;
	struct termios	term;

	(void)env;
	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);

	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 100;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	tputs(tgetstr("ti", NULL), 1, lol);
	mainloop(ac, argv);
	return (0);
}
