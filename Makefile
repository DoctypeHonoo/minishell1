##
## EPITECH PROJECT, 2022
## B-PSU-101-MPL-1-1-minishell1-guillaume.lemoine
## File description:
## Makefile
##

CFLAGS	= -W -Wall -Werror -Wextra -Iinclude/

SRC		=	main.c

OBJ		=	$(SRC:.c=.o)

BIN		= 	mysh

LIB 	=	./lib/libmy.a

all: $(BIN)

$(BIN): $(OBJ) $(LIB)
	@$(CC) -o $(BIN) $(OBJ) -L./lib -lmy
	@echo Make Success

$(LIB):
	@make -C ./lib/my

clean:
	@$(RM) *.o
	@make clean -C lib/my
	@echo Clean Done

fclean: clean
	@$(RM) $(BIN)
	@make -C ./lib/my fclean
	@$(RM) $(LIB)
	@echo Fclean Done

re: fclean all
