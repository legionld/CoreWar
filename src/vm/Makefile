NAME = ../../corewar

SRC =	main.c \
		read_champion.c \
		print_bytes.c \
		battle.c \
		battle_operations.c \
		carrs.c \
		operations1.c \
		operations2.c \
		operations3.c \
		read_input.c \
		read_numbers.c \
		write_operations.c \
		flags.c \
		creator.c \
		drawable.c \
		errors.c \
		viewer.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -c

CC = gcc

INC_LIB = ../../libft/

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) -o $(NAME) -I $(INC_LIB) -L ../../libft/ -lft $(OBJ) ../../libft/libftprintf.a -lncurses

%.o: src/%.c
	@$(CC) $(FLAGS) -I $(INC) -o $@ -c $<

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
