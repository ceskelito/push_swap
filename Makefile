NAME 	:= push_swap
CC 		:= cc
CFLAGS 	:= -Wall -Werror -Wextra
RM 		:= rm -f
MKDIR 		:= mkdir -p

OBJS_DIR 	:= objs
SRCS_DIR	:= sources
UTILS_DIR	:= utils
LIB 		:= LIBFT/libft.a


SOURCES_NAMES = push_swap.c moves.c
SOURCES = $(addprefix $(SRCS_DIR)/, $(SOURCES_NAMES))
UTILS_NAMES = methods_a.c methods_b.c methods_double.c utils.c
UTILS = $(addprefix $(UTILS_DIR)/, $(UTILS_NAMES))

SOURCES_OBJECTS = $(addprefix $(OBJS_DIR)/, $(SOURCES_NAMES:.c=.o))
UTILS_OBJECTS = $(addprefix $(OBJS_DIR)/, $(UTILS_NAMES:.c=.o))
OBJECTS = $(SOURCES_OBJECTS) $(UTILS_OBJECTS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(MKDIR) $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "creating obj %-33.33s\r" $@

$(OBJS_DIR)/%.o: $(UTILS_DIR)/%.c
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
	rm -f $(OBJECTS)

fclean: clean
	@make -C LIBFT fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: re all clean fclean