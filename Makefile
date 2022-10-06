# Project structure
NAME	= libftprintf.a
SRCDIR	= srcs
OBJDIR	= objs
INCDIR	= incs
LIBDIR	= libs
BINDIR	= bins

# Other
RM		= rm -rf
AR		= ar rcs
LIBFT	= libft

# Files
SRCS	=	ft_printf.c \
			ft_printf_utils.c \
			ft_printf_chars.c \
			ft_printf_nums.c
OBJS	= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
HEDS	= $(INCDIR)/ft_printf.h

# Compiler options
CC		= gcc
LIBS	= -lft
CFLAGS	= -Wall -Wextra -Werror -I./$(INCDIR) -L./$(LIBDIR) $(LIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEDS)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): makebuilddirs makelibft $(OBJS)
	$(AR) $(BINDIR)/libft.a $(OBJS)
	mv $(BINDIR)/libft.a $(BINDIR)/$(NAME)

makelibft:
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a ./$(LIBDIR)/libft.a
	cp $(LIBFT)/libft.a ./$(BINDIR)/libft.a

makebuilddirs:
	mkdir -p $(OBJDIR) $(BINDIR)

test:
	$(CC) -Wall -Wextra -Werror test.c -L./$(BINDIR) -lftprintf -I./$(INCDIR)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	$(RM) $(BINDIR)/$(NAME)
	$(RM) $(LIBDIR)/libft.a
	$(RM) $(LIBFT)/libft.a

re: fclean all

.PHONY: all clean fclean re $(NAME) makelibft makebuilddirs test
