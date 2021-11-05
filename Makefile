NAME = push_swap

OBJ = bin/push_swap.o bin/split.o bin/lst.o bin/stack.o bin/math.o bin/stack_oper.o bin/lst_oper.o bin/lst_get.o

BIN = bin
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

ECHO = echo
RED = \033[31m
GRE = \033[32m
GRA = \033[37m
BLU = \033[34m
EOC = \033[0m

all: $(NAME)

bin/%.o: %.c
	@$(ECHO) "$(BLU)● Compiling $^ 🔧$(EOC)"
	@rm -rf $(NAME) $(OBJ_UNUSED)
	@mkdir -p $(BIN)
	@gcc $(FLAGS) -c $^ -o $@

$(NAME): $(OBJ)
	@$(ECHO) "$(GRE)● Compiling to binary ⚙️ $(EOC)"
	@gcc $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@$(ECHO) "$(RED)● Removing /$(BIN) 📁$(EOC)"
	@rm -rf $(BIN)

fclean: clean
	@$(ECHO) "$(RED)● Removing binary ⚙️ $(EOC)"
	@rm -rf $(NAME)

re: fclean all

score: all
	./push_swap 41 57 81 67 4 21 15 88 32 53 97 99 49 8 73 29 33 80 37 22 31 65 87 60 69 66 45 47 34 23 92 17 64 2 61 42 54 95 7 11 70 35 24 12 96 44 20 71 46 89 19 82 56 86 5 39 43 28 36 72 83 40 59 58 100 25 55 85 77 63 9 76 26 38 84 3 50 27 1 51 18 90 6 68 74 13 93 91 75 16 14 10 78 94 79 52 48 30 98 62 | wc -l

.PHONY: all bonus clean fclean re
