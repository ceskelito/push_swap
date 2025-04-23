NAME 	= push_swap
CC 		:= cc 
CFLAGS 	:= -Wall -Werror -Wextra -g -gdwarf-4
RM 		:= rm -f
MKDIR 		:= mkdir -p

OBJS_DIR 	:= objs
SRCS_DIR	:= sources
UTILS_DIR	:= utils
LIB 		:= LIBFT/libft.a

ifeq ($(MODE), debug)
ARGS = "1 2 3 4 5 6 7 8 9"
run: all
	@valgrind --leak-check=full --track-origins=yes ./$(NAME) $(ARGS) > valout.py 2>&1
endif

SOURCES_NAMES = push_swap.c parser.c moves.c ordering_b.c ordering_a.c 
SOURCES = $(addprefix $(SRCS_DIR)/, $(SOURCES_NAMES))
UTILS_NAMES = methods_a.c methods_b.c methods_twin.c utils.c stack_utils.c ordering_utils.c
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