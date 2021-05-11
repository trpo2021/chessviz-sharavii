BO = obj/scr/board.o
MO = obj/scr/main.o
BRO = obj/scr/board_read.o
BOT = obj/test/board_test.o
MOT = obj/test/main.o
BROT = obj/test/board_read_test.o
CH = bin/Chess
CT = bin/ctest

all: $(CH)

test: bin/ctest
	./bin/ctest
bin/Chess:bin obj obj/scr $(BO) $(MO) $(BRO)
	gcc -Wall -Werror -g3 -O0 -o bin/Chess $(MO) $(BO) $(BRO)
bin/ctest:bin obj obj/test $(BOT) $(MOT) $(BROT)
	gcc -Wall -Werror -o $(CT) $(BOT) $(MOT) $(BROT)
bin:
	mkdir bin
obj/scr/board.o: scr/board.c
	gcc -Wall -Werror -o $(BO) -c scr/board.c
obj/scr/main.o: scr/main.c
	gcc -Wall -Werror -o $(MO) -c scr/main.c
obj/scr/board_read.o:
	gcc -Wall -Werror -o $(BRO) -c scr/board_read.c
obj/test/board_test.o: scr/board.c
	gcc -Wall -Werror -o $(BOT) -c test/board.c
obj/test/main.o: scr/main.c
	gcc -Wall -Werror -o $(MOT) -c test/main.c
obj/test/board_read_test.o:
	gcc -Wall -Werror -o $(BROT) -c test/board_read.c
obj:
	mkdir obj
obj/scr:
	mkdir obj/scr
obj/test:
	mkdir obj/test
.PHONY : clean test
clean:
	rm -rf bin/
	rm -rf obj/
