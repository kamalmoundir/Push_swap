NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

LIBFT       = libft/libft.a
SRC_DIR     = src/
SRC_FILES   = functions_util.c functions_util_1.c functions_util_2.c \
              rules_1.c rules_2.c rules_3.c rules_4.c \
              sort.c quicksort_median.c push_swap.c ft_atoi.c

SRC         = $(addprefix $(SRC_DIR), $(SRC_FILES))
INCLUDE     = -I./includes/
OBJS        = $(SRC:.c=.o)
RM          = rm -f

all: $(NAME)

$(NAME): $(LIBFT)   $(OBJS)  
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INCLUDE)

$(LIBFT):
	@make -C libft/

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE) 

clean:
	@make -C libft/ clean
	$(RM) $(OBJS)

fclean: clean
	@make -C libft/ fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
