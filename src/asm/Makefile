NAME = ../../asm

SRC =	main.c \
		usage.c \
		reading/read.c \
		reading/ft_open_res_file.c \
		coding/parse.c \
		coding/help_paste.c \
		coding/write_fo_file.c \
		coding/ft_itoa_base_ll.c \
		t_asm/t_asm.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -c

CC = gcc

INC_LIB = ../../libft/

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) -o $(NAME) -I $(INC_LIB) -L ../../libft/ -lft $(OBJ) ../../libft/libftprintf.a

%.o: src/%.c
	@$(CC) $(FLAGS) -I $(INC) -o $@ -c $<

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
