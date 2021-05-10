all: doska

doska: board.c
	gcc -Wall -Werror board.c -o board