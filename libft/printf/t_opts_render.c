/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_opts_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 13:50:53 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/03/02 10:10:31 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*render_opts_char(t_opts *opts, va_list *pa)
{
	char	*s;
	char	c;

	s = NULL;
	if (opts->type == '%')
		s = ft_strdup("%");
	else if (opts->type == 'c')
	{
		c = va_arg(*pa, int);
		s = ft_strdup(" ");
		s[0] = c;
		s = applyprecision(opts, s);
	}
	else
	{
		s = va_arg(*pa, char *);
		if (!s)
			s = ft_strdup("(null)");
		else if (!s)
			s = ft_strdup("");
		else
			s = ft_strdup(s);
		s = applyprecision(opts, s);
	}
	return (applywidth(opts, s));
}

char		*render_opts_error(t_opts *opts, va_list *pa, char *str)
{
	char	*s;

	(void)pa;
	(void)str;
	s = ft_strdup(" ");
	s[0] = opts->str[ft_strlen(opts->str) - 1];
	s = applywidth(opts, s);
	return (s);
}

wchar_t		*render_opts_wchar(t_opts *opts, va_list *pa)
{
	wchar_t	*w;

	if (opts->type == 'C' ||
		(opts->type == 'c' && !ft_strcmp(opts->modify, "l")))
	{
		w = (wchar_t*)malloc(sizeof(wchar_t) * 2);
		w[0] = va_arg(*pa, int);
		w[1] = '\0';
	}
	else
	{
		w = va_arg(*pa, wchar_t *);
		if (w)
			w = ft_wcsdup(w);
		if (!w)
			w = ft_wcsdup(L"(null)");
		w = applyprecisionwchar(opts, w);
	}
	w = applywidthwchar(opts, w);
	return (w);
}

char		*render_opts_ptr(t_opts *opts, va_list *pa)
{
	char		*s;
	uintmax_t	ptr;

	ptr = va_arg(*pa, uintmax_t);
	s = ft_uitoa_base(ptr, 16);
	if (opts->flags['0'])
	{
		s = applyprecision(opts, s);
		s = applywidth(opts, s);
		s = ft_strtolower(addhexachar(s, 0));
	}
	else
	{
		s = applyprecision(opts, s);
		s = ft_strtolower(addhexachar(s, 0));
		s = applywidth(opts, s);
	}
	return (s);
}
