# PROJECT STRUCTURE
NAME	=	test
NAME_B	=	test_b
TESTDIR	=	tests

# COMPILER
CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror -g3

SRCS	=	nlPrintfTester.c \
			$(TESTDIR)/tests_s.c
OBJS	=	$(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: m

m: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
