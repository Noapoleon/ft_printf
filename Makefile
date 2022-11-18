# Project structure
NAME	=	libftprintf.a
INCDIR	=	incs
SRCDIR	=	srcs
OBJDIR	=	objs
LIBFT	=	libft

# Files
SRCS	:=	ft_printf.c \
			ft_printf_utils.c \
			ft_printf_utils2.c \
			conv_parser.c \
			handler_utils.c \
			handler_nums.c \
			handler_chars.c \
			field_utils.c 
OBJS	:=	$(SRCS:.c=.o)
SRCS	:=	$(addprefix $(SRCDIR)/, $(SRCS))
OBJS	:=	$(addprefix $(OBJDIR)/, $(OBJS))

# Compiler options
CC		=	cc
CFLAGS	=	-g3 -Wall -Wextra -Werror -I./$(INCDIR)

# Other
RM		= rm -rf
AR		= ar rcs

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	make -C $(LIBFT)
	cp $(LIBFT)/libft.h incs/libft.h
	cp $(LIBFT)/libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

bonus: all

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)/libft.a

re: fclean all

test:
	$(CC) $(CFLAGS) test.c -I./incs -L./ -lftprintf

.PHONY: all re clean fclean
