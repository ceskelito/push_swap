NAME	:= ../checker
CC 		:= cc 
CFLAGS 	:= -Wall -Werror -Wextra -g -gdwarf-4
RM 		:= rm -f
MKDIR 	:= mkdir -p

PS_OBJS_DIR	:= ../objs
OBJS_DIR 	:= objs
SRCS_DIR	:= .
LIB 		:= ../LIBFT/libft.a

PS_OBJS_NAMES := moves.o parser.o get_address.o utils.o methods_a.o methods_b.o methods_twin.o stack_utils.o
SOURCES := checker.c methods_a.c methods_b.c methods_twin.c
OBJECTS = $(addprefix $(OBJS_DIR)/, $(SOURCES:.c=.o))
PS_OBJS = $(addprefix $(PS_OBJS_DIR)/, $(PS_OBJS_NAMES))

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(MKDIR) $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "creating obj %-33.33s\r" $@

all: $(NAME)

$(NAME): $(OBJECTS) $(LIB)
	$(CC) $(CFLAGS) $(OBJECTS) $(PS_OBJS) $(LIB) -o $(NAME)
	
$(LIB):
	@make -C ../LIBFT

clean:
	@make -C ../LIBFT clean
	rm -f $(OBJECTS)

fclean: clean
	@make -C ../LIBFT fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: re all clean fclean