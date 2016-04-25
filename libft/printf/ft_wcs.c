/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 00:14:23 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/03/02 10:06:59 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*ft_wcsnew(int n)
{
	wchar_t *wstr;

	wstr = (wchar_t *)malloc(sizeof(wchar_t *) * (++n));
	if (!wstr)
		return (NULL);
	while (n-- > 0)
		wstr[n] = '\0';
	return (wstr);
}

wchar_t	*ft_wcscpy(wchar_t *dest, wchar_t *src)
{
	int	pos;

	pos = 0;
	while (src[pos] != '\0')
	{
		dest[pos] = src[pos];
		pos++;
	}
	dest[pos] = '\0';
	return (dest);
}

wchar_t	*ft_wcsdup(wchar_t *src)
{
	wchar_t	*wstr;

	wstr = (wchar_t *)malloc(sizeof(wchar_t *) * (ft_wcslen(src) + 1));
	if (!wstr)
		return (NULL);
	ft_wcscpy(wstr, src);
	return (wstr);
}

wchar_t	*ft_wcscat(wchar_t *dest, const wchar_t *src)
{
	int	length;
	int	i;

	length = ft_wcslen(dest);
	i = 0;
	while (src[i])
	{
		dest[length + i] = src[i];
		i++;
	}
	dest[length + i] = '\0';
	return (dest);
}

int		ft_wcslen(wchar_t *wstr)
{
	int	i;

	i = 0;
	while (wstr[i])
		i++;
	return (i);
}
