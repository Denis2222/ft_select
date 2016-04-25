/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_opts_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:07:24 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/03/02 10:10:35 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*applyflag(t_opts *opts, char *str)
{
	if (opts->flags['#'] && opts->type == 'x' && ft_strlen(str))
		return (ft_strtolower(addhexachar(str, 1)));
	if (opts->flags['#'] && opts->type == 'X' && ft_strlen(str))
		return (addhexachar(str, 1));
	if (opts->flags['#'] && (opts->type == 'o' || opts->type == 'O'))
		return (addoctachar(str));
	if (issigned(opts) && opts->flags['+'])
		if (str[0] != '-')
			str = straddnchar(str, 0, 1, '+');
	if (issigned(opts) && ft_isdigit(str[0]) && opts->flags[' '])
		str = straddnchar(str, 0, 1, ' ');
	return (str);
}

int		isptrand0orishexaandsharpand0(t_opts *opts)
{
	if ((opts->type == 'p' && opts->flags['0']) ||
		(ishexa(opts) && opts->flags['#'] && opts->flags['0']))
		return (1);
	return (0);
}

char	*applywidth(t_opts *opts, char *str)
{
	int		length;
	int		way;
	char	c;

	c = ' ';
	way = 0;
	if (isptrand0orishexaandsharpand0(opts))
		opts->width = opts->width - 2;
	if (isocta(opts) && opts->flags['#'] && opts->flags['0'])
		opts->width = opts->width - 1;
	if (opts->flags['-'])
		way = 1;
	else if (opts->flags['0'])
		c = '0';
	length = ft_strlen(str);
	if (str[0] == '\0' && opts->type == 'c')
		length = 1;
	if (opts->width > length)
	{
		if (issigned(opts) && opts->flags['0'] && !opts->flags['-'])
			str = straddncharsigned(str, opts->width - length, c);
		else
			str = straddnchar(str, way, opts->width - length, c);
	}
	return (str);
}

wchar_t	*applywidthwchar(t_opts *opts, wchar_t *wstr)
{
	int		length;
	int		way;
	char	c;

	c = ' ';
	way = 0;
	if (opts->flags['-'])
		way = 1;
	else if (opts->flags['0'])
		c = '0';
	length = ft_wstrlen(wstr);
	if (opts->width > length)
	{
		wstr = wstraddnchar(wstr, way, opts->width - length, c);
	}
	return (wstr);
}
