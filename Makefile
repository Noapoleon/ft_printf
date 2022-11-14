# Project structure
NAME	=	libftprintf.a
INCDIR	=	incs
SRCDIR	=	srcs
OBJDIR	=	objs
LIBFT	=	libft

# Files
SRCS	:=	ft_printf.c \
			ft_printf_utils.c \
			handler_utils.c \
			handler_nums.c \
			handler_chars.c \
			handler_hexs.c
OBJS	:=	$(SRCS:.c=.o)
SRCS	:=	$(addprefix $(SRCDIR)/, $(SRCS))
OBJS	:=	$(addprefix $(OBJDIR)/, $(OBJS))

# Compiler options
CC		=	cc -g3
CFLAGS	=	-Wall -Wextra -Werror -I./$(INCDIR)

# Other
RM		= rm -rf
AR		= ar rcs

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp $(LIBFT)/libft.h incs/libft.h
	cp $(LIBFT)/libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)/libft.a

re: fclean all

.PHONY: all re clean fclean

test:
	cc -g3 -Wall -Wextra -Werror test.c -L./ -lftprintf -I./incs
lists:
	echo $(SRCS)
	echo $(OBJS)
