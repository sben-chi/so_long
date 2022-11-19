
NAME = so_long
BNAME = bonus/so_long

CFLAGS = -Wall -Wextra -Werror

CC = gcc

MANDATORY_PART = so_long.c

BOTH = moves.c sl_utils.c gnl.c draw_map.c map.c ft_itoa.c

BONUS_PART = bonus/so_long_bonus.c

M_OFILES = ${MANDATORY_PART:.c=.o}

O_BOTH = ${BOTH:.c=.o}

B_OFILES =  ${BONUS_PART:.c=.o}

all: $(NAME)

$(NAME): $(M_OFILES) $(O_BOTH)
	$(CC) $(M_OFILES) $(O_BOTH) -Imlx -lmlx -framework OpenGl -framework Appkit -o $(NAME) -g  

bonus: $(B_OFILES) $(O_BOTH)
	$(CC) $(B_OFILES) $(O_BOTH) -Imlx -lmlx -framework OpenGl -framework Appkit -o $(BNAME) -g 
re: fclean all

fclean: clean
	rm -f $(NAME) $(BNAME)

clean:
	rm -f $(M_OFILES) $(B_OFILES) $(O_BOTH)
