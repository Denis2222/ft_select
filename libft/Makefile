SRCS = put/ft_putchar.c \
	   put/ft_putstr.c \
	   put/ft_putnbr.c \
	   put/ft_putendl.c \
	   put/ft_putchar_fd.c \
	   put/ft_putstr_fd.c \
	   put/ft_putendl_fd.c \
	   put/ft_putnbr_fd.c \
	   is/ft_isprint.c \
	   is/ft_isdigit.c \
	   is/ft_isalpha.c \
	   is/ft_isalnum.c \
	   is/ft_isascii.c \
	   is/ft_isupper.c \
	   is/ft_islower.c \
	   is/ft_isblank.c \
	   is/ft_isspace.c \
	   str/ft_strcmp.c \
	   str/ft_strlen.c \
	   str/ft_strcat.c \
	   str/ft_strcmp.c \
	   str/ft_strcpy.c \
	   str/ft_strdup.c \
	   str/ft_strlen.c \
	   str/ft_strncat.c \
	   str/ft_strncmp.c \
	   str/ft_strncpy.c \
	   str/ft_strrev.c \
	   str/ft_strstr.c \
	   str/ft_strnstr.c \
	   str/ft_strchr.c \
	   str/ft_strrchr.c \
	   str/ft_strrepchrbystr.c \
	   str/ft_strlcat.c \
	   str/ft_strnew.c \
	   str/ft_strdel.c \
	   str/ft_strclr.c \
	   str/ft_striter.c \
	   str/ft_striteri.c \
	   str/ft_strmap.c \
	   str/ft_strmapi.c \
	   str/ft_strequ.c \
	   str/ft_strnequ.c \
	   str/ft_strsub.c \
	   str/ft_strjoin.c \
	   str/ft_strtrim.c \
	   str/ft_strsplit.c \
	   str/ft_strrepchr.c \
	   mem/ft_memset.c \
	   mem/ft_memalloc.c \
	   mem/ft_memdel.c \
	   mem/ft_memcpy.c \
	   mem/ft_memccpy.c \
	   mem/ft_memcmp.c \
	   mem/ft_memmove.c \
	   mem/ft_memchr.c \
	   lst/ft_lstnew.c \
	   lst/ft_lstdelone.c \
	   lst/ft_lstdel.c \
	   lst/ft_lstadd.c \
	   lst/ft_lstpush.c \
	   lst/ft_lstpush_back.c \
	   lst/ft_lstiter.c \
	   lst/ft_lstmap.c \
	   lst/ft_lstlen.c \
	   lst/ft_lstrev.c \
	   ft_atoi.c \
	   ft_bzero.c \
	   ft_tolower.c \
	   ft_toupper.c \
	   ft_tabfree.c \
	   ft_itoa.c \
	   ft_sqrt.c \
	   ft_tablen.c \
	   ft_abs.c \
	   get_next_line.c \
	   printf/ft_printf.c \
	   printf/addchar.c \
	   printf/ft_itoa_base.c \
	   printf/ft_putw.c \
	   printf/ft_wcs.c \
	   printf/is.c \
	   printf/is2.c \
	   printf/t_opts.c \
	   printf/t_opts_analyse.c \
	   printf/t_opts_analyse_width.c \
	   printf/t_opts_put.c \
	   printf/t_opts_render.c \
	   printf/t_opts_render_numeric.c \
	   printf/t_opts_tools.c \
	   printf/t_opts_tools_prec.c \
	   printf/bonus.c \
	   printf/buffer.c \
	   printf/tools.c

LIBA = libft.a
NAME = $(LIBA)
GCC_FLAGS = -Wall -Werror -Wextra
CC = gcc $(GCC_FLAGS)
SRCDIR = ./
OBJDIR = ./
AR = ar -cq
RM = rm -rf
# standart
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $@ $^
	@echo "Link $^"
	@ranlib $@
	@echo "[$@] Complete"

$(addprefix $(OBJDIR)/, %.o): $(addprefix $(SRCDIR)/, %.c)
	@mkdir -p $(OBJDIR)
	@$(CC) -I. -o $@ -c $^
	@echo "[√]$^ "

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(LIBA)

re: fclean all
