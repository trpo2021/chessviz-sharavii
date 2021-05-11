BO = obj/scr/board.o
MO = obj/scr/main.o
BRO = obj/scr/board_read.o
CH = bin/Chess

all: $(CH)

bin/Chess:bin bin $(BO) $(MO) $(BRO)
	gcc -Wall -Werror -g3 -O0 -o bin/Chess $(MO) $(BO) $(BRO)
bin:
	mkdir bin
bin/board.o: scr/board.c
	gcc -Wall -Werror -o $(BO) -c scr/board.c
bin/main.o: scr/main.c
	gcc -Wall -Werror -o $(MO) -c scr/main.c
bin/board_read.o:
	gcc -Wall -Werror -o $(BRO) -c scr/board_read.c
bin:
	mkdir obj
.PHONY : clean
clean:
	rm -rf bin/
	rm -rf obj/*.o