NAME = $(TEST:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
TEST := test.c
SRC_DIR = ../src
SRCS = $(SRC_DIR)/get_next_line.c\
	   $(SRC_DIR)/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
BS = 10
NAME_BONUS = test_bonus.o
SRCS_BONUS = $(SRC_DIR)/get_next_line_bonus.c\
		     $(SRC_DIR)/get_next_line_utils_bonus.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)


debug: CFLAGS += -g
debug: all

check: CFLAGS += -D BUFFER_SIZE=$(BS)
check: all

all: $(NAME)

$(NAME): $(TEST) $(OBJS)
	$(CC) $(CFLAGS) $(TEST) -I $(SRC_DIR) $(OBJS) -o $(NAME)

$(addprefix $(SRC_DIR),$(OBJS)): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(TEST) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(TEST) -I $(SRC_DIR) $(OBJS_BONUS) -o $(NAME_BONUS)

$(addprefix $(SRC_DIR),$(OBJS_BONUS)): $(SRCS_BONUS)
	$(CC) $(CFLAGS) -c $(SRCS_BONUS)