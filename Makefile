################################################################################
# Malloc library                                                               #
################################################################################
ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif
NAME = libft_malloc_${HOSTTYPE}.so
LINK_NAME = libft_malloc.so

PATH_SRCS = ./src/
PATH_INTERNALS = ./src/internal/
PATH_OBJS = ./obj/

SRCS = malloc.c
OBJS = ${SRCS:%.c=$(PATH_OBJS)%.o}

INTERNALS_SRCS = get_page_size.c
INTERNALS_OBJS = ${INTERNALS_SRCS:%.c=$(PATH_OBJS)%.o}
################################################################################
# Malloc tests                                                                 #
################################################################################
TEST_NAME = malloc_test

PATH_TEST_SRCS = ./test/
PATH_OBJS = ./obj/

TEST_SRCS = main.c
TEST_OBJS = ${TEST_SRCS:%.c=$(PATH_OBJS)%.o}

RPATH = $(shell pwd)
################################################################################

INCLUDE = -I ./incl/
FLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(OBJS) $(INTERNALS_OBJS)
	@$(CC) $(FLAGS) -shared -o $(NAME) $(OBJS) $(INTERNALS_OBJS)
	@ln -s $(NAME) $(LINK_NAME)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -fPIC -o $@
	@echo "\033[1;92m[SUCCESS] Object" $< "created!\033[0m"

$(PATH_OBJS)%.o: $(PATH_INTERNALS)%.c
	@mkdir -p $(PATH_OBJS)
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -fPIC -o $@
	@echo "\033[1;92m[SUCCESS] Object" $< "created!\033[0m"

test: all $(TEST_NAME)
	@valgrind --soname-synonyms=somalloc=lifbt_malloc.so ./$(TEST_NAME)

$(TEST_NAME): $(TEST_OBJS)
	@$(CC) $(FLAGS) $(INCLUDE) -rpath $(RPATH) -L. -lft_malloc -o $(TEST_NAME) $(TEST_OBJS)
	@echo "\033[1;92m[SUCCESS] Object" $< "created!\033[0m"

$(PATH_OBJS)%.o: $(PATH_TEST_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[1;92m[SUCCESS] Object" $< "created!\033[0m"

clean:
	@rm -rf $(PATH_OBJS)
	@echo "\33[1;93m[SUCCESS] Objects removed!\33[0m"

fclean: clean
	@rm -f $(NAME) $(LINK_NAME) $(TEST_NAME)
	@echo "\033[1;93m[SUCCESS] Library removed!\33[0m"

re: fclean all

.PHONY: all clean fclean re
