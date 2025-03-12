NAME 	:= push_swap
CC 		:= cc
CFLAGS 	:= -Wall -Werror -Wextra
RM 		:= rm -f
MKDIR 		:= mkdir -p
OBJS_DIR 	:= objs
LIB 		:= LIBFT/libft.a


SOURCES = push_swap.c

OBJECTS = $(addprefix $(OBJS_DIR)/, $(SOURCES:.c=.o))

$(OBJS_DIR)/%.o: %.c
	@$(MKDIR) $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "creating obj %-33.33s\r" $@
 
all: $(NAME)

$(NAME): $(OBJECTS) $(LIB)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIB) -o $(NAME)
	
$(LIB):
	@make -C LIBFT

clean:
	@make -C LIBFT clean
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ)

fclean: clean
	@make -C LIBFT fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: re all clean fclean bonu