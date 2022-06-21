##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

CC				=	gcc
AR				=	ar
ARFLAGS			=	rsc libmy.a *.o

all: make_lib

make_lib:
	@$(CC)   *.c -c
	@$(AR) $(ARFLAGS)
	@cp libmy.a ../libmy.a
	@echo LIB Done

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf ../libmy.a
	@rm -rf libmy.a

re: fclean all
