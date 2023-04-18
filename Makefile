
CC = cc
NAME = push_swap
BONUS_NAME = checker

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

BNS_SRC = src/checker/checker.c\
src/checker/get_next_line_utils.c\
src/checker/get_next_line_.c\
src/free.c\
src/main_checker.c

OBJ = $(SRC:.c=.o)
FT_PRINTF := ./lib/ft_printf
LIBFT := ./lib/libft
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g
LDFLAGS = -L../LeakSanitizer -llsan -lc++ -Wno-gnu-include-next -I ../LeakSanitize
FSANFLAG += -fsanitize=address -Ofast

all: ft_printf libft $(NAME)

ft_printf:
	@$(MAKE) -C $(FT_PRINTF)

libft:
	@$(MAKE) -C $(LIBFT)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FT_PRINTF)/ft_printf.a $(LIBFT)/libft.a -o $(NAME)

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(FT_PRINTF) clean
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(FT_PRINTF) fclean
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re ft_printf libft

# all - compile starter (execute other rules)

# CFLAGS is used automatically

# ar -rcs adds files in archve and replace them
# if they have already been there
# (if the library already exists)
# c creates the library if there is no one
# s creates a sorted index
# that's why we can call ar -rcs again and add there bonus obj files
