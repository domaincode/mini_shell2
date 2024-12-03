NAME = minishell.a
EXE = minishell 

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRCS = parsing/dollar_env.c \
       parsing/free.c \
       parsing/list_utils.c \
       parsing/quote.c \
       parsing/create_token.c \
       parsing/dollar_replace.c \
       parsing/list_token.c \
       parsing/ms_utils.c \
       parsing/parsing_utils.c \
       parsing/error.c \
       parsing/cmd_fd.c \
       parsing/cmd_param.c \
       parsing/create_cmd.c \
       parsing/list_cmd.c \
       parsing/here_doc.c \
       parsing/signal.c \
       parsing/free_reset.c \
       parsing/free_cmd.c \
       exec/cmd/find.c \
       exec/cmd/exec.c \
       exec/cmd/wait.c \
       exec/cmd/cmd_init.c \
       exec/cmd/null_cmd.c \
       exec/src/free.c \
       exec/src/split.c \
       exec/src/set_env.c \
       exec/builtins/cd.c \
       exec/builtins/echo.c \
       exec/builtins/env.c \
       exec/builtins/export.c \
       exec/builtins/export_utils.c \
       exec/builtins/unset.c \
       exec/builtins/pwd.c \
       exec/builtins/env_cmp.c \
       exec/builtins/print.c \
       exec/builtins/exit.c \
       main.c \
       
LIBFT_LIB = libft/libft.a
MAKE_EXEC = 
OBJS := $(SRCS:.c=.o)

all: $(EXE)

$(NAME): $(OBJS)
	ar -rc $(NAME) $?

$(EXE): $(NAME) $(LIBFT_LIB)
	$(CC) $(NAME) $(LIBFT_LIB) -o $(EXE) -pthread -I libft -lreadline

$(LIBFT_LIB):
	make -C libft -s

clean:
	make fclean -C libft -s
	rm -f $(OBJS) $(NAME) 

fclean: clean
	rm -f  $(EXE)

re: fclean all

.SECONDARY:

.PHONY: all clean fclean re
