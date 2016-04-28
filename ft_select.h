/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:45:37 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/23 19:07:05 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft/libft.h"
# include <termios.h>
# include <term.h>
# include <curses.h>
# include <sys/ioctl.h>

typedef struct		s_select
{
	char			*name;
	int				select;
	int				cursor;
	struct s_select	*next;
	struct s_select	*prev;
}					t_select;

typedef struct		s_shell
{
	struct winsize	*sz;
	t_select		*list;
	struct termios	*tiosold;
	struct termios	*tios;
}					t_shell;

t_select			*newselect(char *name);
t_select			*addselect(t_select **list, t_select *elem);

int					selectlen(t_select *select);
size_t				selectmaxstr(t_select *select);
int 				wordbyline(t_select *select, int ws_col);

void				viewselect(t_shell *shell);
void 				cursornext(t_select *select);
void 				cursorprev(t_select *select);
void				cursorup(t_shell *shell);
void				cursordown(t_shell *shell);
void				cursordel(t_select **select);
void				selectcursor(t_select *select);
char				*selectreturn(t_select *select);

t_select			*parseargv(char **argv);
t_shell				*newshell(void);
t_shell				*getshell(t_shell *shell);
void 				updateshell(t_shell *shell);
int					lol(int c);

int 				key(char *buffer, t_shell *shell);
void 				exitprg(void);

#endif
