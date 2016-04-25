/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:06:14 by dmoureu-          #+#    #+#             */
/*   Updated: 2015/11/25 14:28:22 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char *mem;

	mem = malloc(sizeof(char) * size);
	if (!mem)
		return (NULL);
	while (size-- > 0)
	{
		mem[size] = 0;
	}
	return ((void*)mem);
}
