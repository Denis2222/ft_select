SRCS = main.c \
		t_select.c \
		parsing.c \
		t_select_fct.c \
		t_select_cursor.c \
		t_select_cursor_move.c \
		handle.c \
		key.c \
		t_shell.c

NAME = ft_select
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
	$(CC) -o $(NAME) $(OBJS) -lft -L./libft/ -lncurses

$(addprefix $(OBJDIR)/, %.o): $(addprefix $(SRCDIR)/, %.c)
	@mkdir -p $(OBJDIR)
	@$(CC) -o $@ -c $^

clean:
	@$(RM) $(OBJDIR)

fclean: clean
	@$(RM) $(NAME)
	@make -C libft fclean

re: fclean all

test: $(NAME)
	ls -l `./ft_select *`
