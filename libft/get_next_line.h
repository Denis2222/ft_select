/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 00:27:38 by dmoureu-          #+#    #+#             */
/*   Updated: 2015/12/12 14:12:02 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>

# define BUFF_SIZE 1024

int				get_next_line(int const fd, char **line);

typedef struct	s_file
{
	int			fd;
	char		*buf;
}				t_file;

#endif
