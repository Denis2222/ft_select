SRCS = addchar.c \
	   ft_itoa_base.c \
	   ft_printf.c \
	   ft_putw.c \
	   ft_wcs.c \
	   is.c \
	   is2.c \
	   t_opts.c \
	   t_opts_analyse.c \
	   t_opts_analyse_width.c \
	   t_opts_put.c \
	   t_opts_render.c \
	   t_opts_render_numeric.c \
	   t_opts_tools.c \
	   t_opts_tools_prec.c \
	   bonus.c \
	   buffer.c \
	   tools.c

NAME = libftprintf.a
GCC_FLAGS = -Wall -Werror -Wextra
CC = gcc $(GCC_FLAGS)
SRCDIR = ./
OBJDIR = ./objs
AR = ar -cq
RM = rm -rf
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
LIBFT = ./libft/libft.a

all: $(NAME)

$(LIBFT):
	@make -C libft
	@echo $(SRC_LIB_O)

$(NAME): $(OBJS) $(LIBFT)
	@$(AR) $@ $^ ./libft/*.o
	@#echo "Link $^"
	@ranlib $@
	@#echo "[$@] Complete"

$(addprefix $(OBJDIR)/, %.o): $(addprefix $(SRCDIR)/, %.c)
	@mkdir -p $(OBJDIR)
	@$(CC) -o $@ -c $^

clean:
	@$(RM) $(OBJDIR)

fclean: clean
	@$(RM) $(NAME)
	#@make -C libft fclean

re: fclean all

test: clean all
	rm -f test
	gcc libftprintf.a main.c -o test
	./test

test2: clean all
	rm -f test2
	gcc libftprintf.a main2.c -o test2
	./test2

speed: clean all
	rm -f speed
	gcc libftprintf.a speedtest_ft_printf.c -o speed
	time ./speed

speedreal: clean all
	rm -f speedreql
	gcc speedtest_printf.c -o speedreal
	time ./speedreal

