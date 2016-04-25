/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_opts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:07:39 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/20 12:09:45 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initopts(t_opts *opts, char *startopts, int *pos)
{
	opts->formatstart = 0;
	opts->formatend = 0;
	opts->type = 0;
	opts->flags = ft_memalloc('1');
	opts->width = 0;
	opts->precision = 0;
	opts->precisionn = 0;
	opts->modify = 0;
	opts->str = ft_strnew(opts->length + 1);
	opts->str = ft_strncpy(opts->str, startopts, opts->length + 1);
	opts->formatstart = *pos;
	opts->formatend = *pos + opts->length;
	opts->type = opts->str[opts->length];
}

t_opts	*newopts(char *format, int *pos, va_list *pa)
{
	t_opts	*opts;
	char	*startopts;

	startopts = format;
	opts = (t_opts*)malloc(sizeof(t_opts));
	opts->length = 0;
	while (!istype(*format) && !(opts->length && *format == '%'))
	{
		if (isflag(*format) || ft_isdigit(*format) ||
			ismod(*format) || *format == '%' ||
			*format == '.' || *format == '*')
		{
			opts->length++;
			format++;
		}
		else
			break ;
	}
	initopts(opts, startopts, pos);
	analyseopts(opts, pa);
	opts->next = NULL;
	*pos += opts->length;
	return (opts);
}

int		cleanopts(t_opts *opts)
{
	int	length;

	length = opts->length;
	free(opts->str);
	free(opts->flags);
	free(opts->modify);
	free(opts);
	return (length);
}

int		renderopts(t_opts *opts, va_list *pa, int fd)
{
	char	*str;
	wchar_t	*wstr;

	str = NULL;
	wstr = NULL;
	if (issigned(opts))
		str = render_opts_numeric_signed(opts, pa);
	if (isunsigned(opts))
		str = render_opts_numeric_unsigned(opts, pa);
	if (iswchar(opts))
		wstr = render_opts_wchar(opts, pa);
	else if (ischar(opts))
		str = render_opts_char(opts, pa);
	if (isptr(opts))
		str = render_opts_ptr(opts, pa);
	if (!istype(opts->type) && opts->type != '%')
		str = render_opts_error(opts, pa, str);
	if (str)
		return (putoptsstr(opts, str, fd));
	else if (wstr)
		return (putoptswstr(opts, wstr, fd));
	else
		return (putoptsnull(opts, fd));
	return (0);
}

t_opts	*addopts(t_opts **lst, t_opts *new)
{
	t_opts	*beginlst;
	t_opts	*current;

	beginlst = *lst;
	current = beginlst;
	if (!*lst)
		beginlst = new;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
	return (beginlst);
}
