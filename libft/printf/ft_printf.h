/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:01:51 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/20 13:28:39 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <inttypes.h>
# include <wchar.h>
# include "../libft.h"

# define KNRM   "\x1B[0m"
# define KRED   "\x1B[31m"
# define KGRN   "\x1B[32m"
# define KYEL   "\x1B[33m"
# define KBLU   "\x1B[34m"
# define KMAG   "\x1B[35m"
# define KCYN   "\x1B[36m"
# define KWHT   "\x1B[37m"
# define KBOLD  "\e[1m"
# define KDIM   "\e[2m"
# define KUNDER "\e[4m"
# define KBLINK "\e[5m"
# define KINV   "\e[7m"
# define PRINTFBUFFER 400

int					ft_printf(char *format, ...);
int					ft_dprintf(int fd, char *format, ...);

typedef struct		s_opts
{
	char			*str;
	int				length;
	int				formatstart;
	int				formatend;

	char			type;
	char			*flags;
	int				width;
	int				precision;
	int				precisionn;
	char			*modify;

	struct s_opts	*next;
}					t_opts;

t_opts				*newopts(char *format, int *pos, va_list *pa);
t_opts				*addopts(t_opts **lst, t_opts *new);
int					renderopts(t_opts *opts, va_list *pa, int fd);
void				initopts(t_opts *opts, char *startopts, int *pos);
int					optsflag(t_opts *opts, char *str);
int					cleanopts(t_opts *opts);

typedef struct		s_ftprintf
{
	char			*format;
	t_opts			*opts;
}					t_printf;

t_printf			*newprintf(char *format);
void				debugprintf(t_printf *pf);

int					choose(va_list *pa, char *format);

void				ft_putwchar_fd(wchar_t chr, int fd);
int					ft_wcharlen(wchar_t c);
int					ft_wcslen(wchar_t *wstr);
int					ft_wstrlen(wchar_t *wstr);
wchar_t				*ft_wcsnew(int n);
wchar_t				*ft_wcscpy(wchar_t *dest, wchar_t *src);
wchar_t				*ft_wcsdup(wchar_t *src);
wchar_t				*ft_wcscat(wchar_t *dest, const wchar_t *src);

void				ft_putwchar(wchar_t c, int fd);
void				ft_putwstr(wchar_t *wstr, int fd);

char				*ft_itoa_base(intmax_t value, int base);
char				*ft_uitoa_base(uintmax_t value, int base);

char				*ft_strminn(char *str, int size, int align, char c);
char				*ft_strmaxn(char *str, int size);

int					issigned(t_opts *opts);
int					isunsigned(t_opts *opts);
int					iswchar(t_opts *opts);
int					ischar(t_opts *opts);
int					isptr(t_opts *opts);

int					istype(char c);
int					isflag(char c);
int					ismod(char c);

int					isocta(t_opts *opts);
int					ishexa(t_opts *opts);
int					isptrand0orishexaandsharpand0(t_opts *opts);

void				analyseflags(t_opts *opts);
void				analysewidth(t_opts *opts, va_list *pa);
void				analyseprecision(t_opts *opts, va_list *pa);
void				analysemod(t_opts *opts);
void				analyseopts(t_opts *opts, va_list *pa);
char				*render_opts_ptr(t_opts *opts, va_list *pa);
char				*render_opts_char(t_opts *opts, va_list *pa);
wchar_t				*render_opts_wchar(t_opts *opts, va_list *pa);
char				*render_opts_numeric_signed(t_opts *opts, va_list *pa);
char				*render_opts_numeric_unsigned(t_opts *opts, va_list *pa);
char				*render_opts_error(t_opts *opts, va_list *pa, char *str);

char				*straddnchar(char *str, int way, int n, char c);
char				*straddncharsigned(char *str, int n, char c);
wchar_t				*wstraddnchar(wchar_t *wstr, int way, int n, char c);

char				*addhexachar(char *str, int ishexa);
char				*addoctachar(char *str);
char				*applyflag(t_opts *opts, char *str);
char				*applyprecision(t_opts *opts, char *str);
wchar_t				*applyprecisionwchar(t_opts *opts, wchar_t *str);
char				*applywidth(t_opts *opts, char *str);
wchar_t				*applywidthwchar(t_opts *opts, wchar_t *wstr);

void				freestr(char *str);
void				freewstr(wchar_t *wstr);
void				printfclean(t_printf *pf);

int					putoptsstr(t_opts *opts, char *str, int fd);
int					putoptswstr(t_opts *opts, wchar_t *wstr, int fd);
int					putoptsnull(t_opts *opts, int fd);

void				evalcolor(char **format, va_list *pa, int len, int fd);
void				incremente(char **format, int *pos);

void				ft_putstrn(char *buffer, int len, int fd);
void				ft_putbuffer(char c, int way, int fd);
void				ft_printbuffer(char *buffer, int len);
void				ft_putstrbuf(char *str, int fd);

#endif
