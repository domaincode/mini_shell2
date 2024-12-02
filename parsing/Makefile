NAME = minishell.a
EXE = minishell 

CC = cc
CFLAGS = -g3

SRCS = dollar_env.c \
       free.c \
       list_utils.c \
       quote.c \
       create_token.c \
       dollar_replace.c \
       list_token.c \
       ../main.c \
       ms_utils.c \
       parsing_utils.c \
       error.c \
       cmd_fd.c \
       cmd_param.c \
       create_cmd.c \
       list_cmd.c \
       here_doc.c \
       signal.c \
       ${wildcard ../exec/*.c } \
       ${wildcard ../exec/builtins/*.c } \
       ${wildcard ../exec/src/*.c } \

       
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
