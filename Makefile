NAME		= minishell
LIBFT		= libft/libft.a
SRC 		= $(shell find src -name '*.c')
OBJ 		= ${patsubst src/%.c, objs/%.o, $(SRC)}
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g
READLINE_FLAGS	= -lreadline
INCLUDE		= -I includes/
RM = rm -rf

all:	$(NAME) 

$(LIBFT):
		@$(MAKE) -s -C libft/

objs:
		@mkdir -p objs

$(OBJ): objs/%.o: src/%.c | objs
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(LIBFT) $(OBJ)
		$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) $(LIBFT)  -o $(NAME) \
			$(READLINE_FLAGS)

clean: 
		@make clean -C libft
		${RM} ${OBJ}
		@rm -rf objs

fclean: clean
		@make fclean -C libft
		${RM} $(NAME)
		${RM} $(LIBFT)

re: fclean all

.PHONY:		all clean fclean re
