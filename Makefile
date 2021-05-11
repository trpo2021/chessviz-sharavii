BO = obj/board.o
MO = obj/main.o
BRO = obj/board_read.o
CH = bin/Chess

all: $(CH)

bin/Chess:bin obj $(BO) $(MO) $(BRO)
	gcc -Wall -Werror -g3 -O0 -o bin/Chess $(MO) $(BO) $(BRO)
bin:
	mkdir bin
obj/board.o: scr/board.c
	gcc -Wall -Werror -o $(BO) -c scr/board.c
obj/main.o: scr/main.c
	gcc -Wall -Werror -o $(MO) -c scr/main.c
obj/board_read.o:
	gcc -Wall -Werror -o $(BRO) -c scr/board_read.c
obj:
	mkdir obj
.PHONY : clean
clean:
	rm -rf bin/
	rm -rf build/*.ogi