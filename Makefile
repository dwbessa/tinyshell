NAME		= minishell
LIBFT		= libft/libft.a
SRC 		= $(shell find src -name '*.c')
OBJ 		= ${patsubst src/%.c, objs/%.o, $(SRC)}
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g
READLINE_FLAGS	= -lreadline
INCLUDE		= -I includes/
RM = rm -rf
SILENT		= @
COLOR_RESET	= \033[0m
COLOR_GREEN	= \033[32m
COLOR_YELLOW	= \033[33m
COLOR_RED	= \033[31m
BLINK		= \033[5m

all:	$(NAME) 

$(LIBFT):
		@$(MAKE) -s -C libft/

objs:
		@mkdir -p objs

$(OBJ): objs/%.o: src/%.c | objs
		@mkdir -p $(dir $@)
		$(SILENT) $(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(LIBFT) $(OBJ)
		$(SILENT) $(CC) $(CFLAGS) $(INCLUDE) $(OBJ) $(LIBFT)  -o $(NAME) \
			$(READLINE_FLAGS)
		@echo "✅ $(BLINK)$(COLOR_GREEN)Minishell is ready!$(COLOR_RESET)"

leak:
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=supressions.supp -s ./minishell

clean: 
		$(SILENT) @make clean -C libft
		$(SILENT) ${RM} ${OBJ}
		@rm -rf objs
		@echo "👀 $(COLOR_YELLOW)Cleaned up object files$(COLOR_RESET)"

fclean: clean
		$(SILENT) @make fclean -C libft
		$(SILENT) ${RM} $(NAME)
		$(SILENT) ${RM} $(LIBFT)
		@echo "🔥 $(COLOR_RED)Removed $(NAME) executable$(COLOR_RESET)"

re: fclean all

.PHONY:		all clean fclean re leak
