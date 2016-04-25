/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_opts_render_numeric.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 09:46:42 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/03/02 10:10:33 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	render_opts_numeric_unsigned_get(t_opts *opts, va_list *pa)
{
	uintmax_t		n;

	if (!ft_strcmp(opts->modify, "l") || opts->type == 'O' || opts->type == 'U')
		n = (unsigned long)va_arg(*pa, uintmax_t);
	else if (!ft_strcmp(opts->modify, "hh"))
		n = (unsigned char)(va_arg(*pa, uintmax_t));
	else if (!ft_strcmp(opts->modify, "h"))
		n = (unsigned short)va_arg(*pa, uintmax_t);
	else if (!ft_strcmp(opts->modify, "ll"))
		n = (unsigned long long)va_arg(*pa, uintmax_t);
	else if (!ft_strcmp(opts->modify, "z"))
		n = (size_t)(va_arg(*pa, uintmax_t));
	else if (!ft_strcmp(opts->modify, "j"))
		n = (uintmax_t)(va_arg(*pa, uintmax_t));
	else
		n = (unsigned int)(va_arg(*pa, uintmax_t));
	return (n);
}

char		*render_opts_numeric_uitoa(t_opts *opts, uintmax_t n)
{
	char	*s;

	if (opts->type == 'o')
		s = ft_uitoa_base(n, 8);
	else if (opts->type == 'O')
		s = ft_uitoa_base(n, 8);
	else if (opts->type == 'x')
		s = ft_strtolower(ft_uitoa_base(n, 16));
	else if (opts->type == 'X')
		s = ft_uitoa_base(n, 16);
	else if (opts->type == 'u')
		s = ft_uitoa_base(n, 10);
	else if (opts->type == 'b')
		s = ft_uitoa_base(n, 2);
	else
		s = ft_uitoa_base(n, 10);
	return (s);
}

int			ishexaoctacasdemerde(t_opts *opts)
{
	if ((ishexa(opts) && opts->flags['#'] && !opts->flags['0']) ||
			(isocta(opts) && opts->flags['#'] && !opts->flags['0']))
		return (1);
	return (0);
}

char		*render_opts_numeric_unsigned(t_opts *opts, va_list *pa)
{
	uintmax_t	n;
	char		*s;

	n = render_opts_numeric_unsigned_get(opts, pa);
	s = render_opts_numeric_uitoa(opts, n);
	if (isocta(opts) && opts->precision && opts->precisionn)
	{
		s = applyflag(opts, s);
		s = applyprecision(opts, s);
		s = applywidth(opts, s);
	}
	else if (ishexaoctacasdemerde(opts))
	{
		s = applyprecision(opts, s);
		s = applyflag(opts, s);
		s = applywidth(opts, s);
	}
	else
	{
		s = applyprecision(opts, s);
		s = applywidth(opts, s);
		s = applyflag(opts, s);
	}
	return (s);
}

char		*render_opts_numeric_signed(t_opts *opts, va_list *pa)
{
	intmax_t		n;
	char			*s;

	if (!ft_strcmp(opts->modify, "l") || opts->type == 'D')
		n = (long)va_arg(*pa, intmax_t);
	else if (!ft_strcmp(opts->modify, "hh"))
		n = (char)(va_arg(*pa, intmax_t));
	else if (!ft_strcmp(opts->modify, "h"))
		n = (short)va_arg(*pa, intmax_t);
	else if (!ft_strcmp(opts->modify, "ll"))
		n = (long long)va_arg(*pa, intmax_t);
	else if (!ft_strcmp(opts->modify, "z"))
		n = (size_t)(va_arg(*pa, intmax_t));
	else if (!ft_strcmp(opts->modify, "j"))
		n = (intmax_t)(va_arg(*pa, intmax_t));
	else
		n = (int)(va_arg(*pa, intmax_t));
	s = ft_itoa_base(n, 10);
	s = applyprecision(opts, s);
	s = applyflag(opts, s);
	s = applywidth(opts, s);
	return (s);
}
