NAME = test.o
CC = gcc
CFLAGS = -Wall -Wextra -Werror
TEST = test.c
SRC_DIR = ../src
SRCS = $(SRC_DIR)/get_next_line.c\
		$(SRC_DIR)/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

debug: CFLAGS += -g
debug: all

print: $(OBJS)
	echo $(OBJS)

all: $(NAME)

$(NAME): $(TEST) $(OBJS)
	$(CC) $(CFLAGS) $(TEST) -I $(SRC_DIR) $(OBJS) -o $(NAME)

$(addprefix $(SRC_DIR),$(OBJS)): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
