
CC = cc
NAME = push_swap
BNS_NAME = checker

SRC = src/create_stack/create_stack_utils.c\
src/create_stack/create_stack.c\
src/create_stack/parse_str.c\
src/operations/exec_both.c\
src/operations/push.c\
src/operations/rev_rotate.c\
src/operations/rotate.c\
src/operations/swap.c\
src/sort/cases.c\
src/sort/find_cheapest.c\
src/sort/find_min_max.c\
src/sort/sort_three_five.c\
src/sort/sort_utils.c\
src/sort/sort.c\
src/free.c\
src/main.c

BNS_SRC = src/checker_bonus.c\
src/free_bonus.c\
src/checker/create_stack/create_stack_bonus.c\
src/checker/create_stack/create_stack_utils_bonus.c\
src/checker/create_stack/parse_str_bonus.c\
src/checker/gnl/get_next_line_utils.c\
src/checker/gnl/get_next_line.c\
src/checker/operations/push_bonus.c\
src/checker/operations/swap_bonus.c\
src/checker/operations/rotate_bonus.c\
src/checker/operations/rev_rotate_bonus.c\
src/checker/operations/exec_both_bonus.c\

OBJ = $(SRC:.c=.o)
BNS_OBJ = $(BNS_SRC:.c=.o)

FT_PRINTF := ./lib/ft_printf
LIBFT := ./lib/libft
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g
LDFLAGS = -L../LeakSanitizer -llsan -lc++ -Wno-gnu-include-next -I ../LeakSanitize
FSANFLAG += -fsanitize=address -Ofast

all: ft_printf libft $(NAME)

bonus: libft $(BNS_NAME)

ft_printf:
	@$(MAKE) -C $(FT_PRINTF)

libft:
	@$(MAKE) -C $(LIBFT)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FT_PRINTF)/ft_printf.a $(LIBFT)/libft.a -o $(NAME)

$(BNS_NAME): $(BNS_OBJ)
	$(CC) $(BNS_OBJ) $(LIBFT)/libft.a -o $(BNS_NAME)

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(FT_PRINTF) clean
	@$(MAKE) -C $(LIBFT) clean

clean_bonus:
	rm -f $(BNS_OBJ)
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(FT_PRINTF) fclean
	@$(MAKE) -C $(LIBFT) fclean

fclean_bonus: clean_bonus
	rm -f $(BNS_NAME)
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

re_bonus: fclean_bonus bonus

.PHONY: all clean fclean re ft_printf libft bonus fclean_bonus clean_bonus re_bonus

# all - compile starter (execute other rules)

# CFLAGS is used automatically

# ar -rcs adds files in archve and replace them
# if they have already been there
# (if the library already exists)
# c creates the library if there is no one
# s creates a sorted index
# that's why we can call ar -rcs again and add there bonus obj files
