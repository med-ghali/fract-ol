SRCS := main.c fractal_utils.c map.c mandelbrot.c julia.c color.c events.c tricorn.c

OBJS := $(SRCS:.c=.o)


C_FLAGS := -Wall -Wextra -Werror

NAME := fractal

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c fractal.h keys.h 
	$(CC) $(C_FLAGS) -c $<

bonus : all

clean :
	rm -f $(OBJS) 

fclean : clean
	rm -f $(NAME)

re : fclean all
