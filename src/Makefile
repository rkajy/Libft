CC = cc
CFLAGS = 
SRCS = 	*.c
OBJS = $(SRCS:.c=.o)
NAME = libft.a

all: $(OBJS)
	ar rcs $(NAME) $(OBJS)
clean:
	rm -f $(OBJS) $(B_OBJS)
fclean: clean
	rm -f $(NAME)
$(NAME): all
re: fclean all
