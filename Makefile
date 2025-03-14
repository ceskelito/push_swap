NAME 	:= push_swap
CC 		:= cc
CFLAGS 	:= -Wall -Werror -Wextra
RM 		:= rm -f
MKDIR 		:= mkdir -p
OBJS_DIR 	:= objs
SRCS_DIR	:= sources
LIB 		:= LIBFT/libft.a


SOURCES_NAMES = push_swap.c moves.c
SOURCES = $(addprefix $(SRCS_DIR)/, $(SOURCES_NAMES))

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