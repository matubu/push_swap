NAME = push_swap

OBJ = bin/push_swap.o bin/split.o bin/lst.o bin/stack.o bin/math.o bin/stack_oper.o bin/lst_oper.o bin/lst_get.o

BIN = bin
FLAGS = -Wall -Wextra -Werror

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

.PHONY: all bonus clean fclean re
