
###	ARGUMENTS	###
NAME		= so_long
NAME_BONUS	= checker
CFLAGS		= -Wall -Werror -Wextra -g3
CC			= cc
INCLUDES	= -I/usr/include -Imlx
MLX_FLAGS	= -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

###	SOURCES		###
SRCS		= main.c gnl/get_next_line.c gnl/get_next_line_utils.c \
				map_check.c map_check_utils.c error.c utils.c \
				game.c display_map.c freez.c mini_libft.c init_map.c utils_bis.c
OBJS		= $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

###	RULES		###
all	: ${NAME}

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLX_FLAGS) -lm -lz -o $(NAME)


clean	:
	rm -f ${OBJS} 

fclean	: clean
	rm -f ${NAME}

re	: fclean all

.PHONY	: all clean fclean re