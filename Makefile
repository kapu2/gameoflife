#------------------------------------------------------------------------------

SOURCE=main.cpp main.h Board.cpp Board.h Life.cpp Life.h
MYPROGRAM=gameoflife
MYINCLUDES=~
FLAGS=-pedantic -Wall -g -ggdb

CC=g++

#------------------------------------------------------------------------------



all: $(MYPROGRAM)



$(MYPROGRAM): $(SOURCE)

	$(CC) $(FLAGS) -I$(MYINCLUDES) $(SOURCE) -o$(MYPROGRAM)

clean:

	rm -f $(MYPROGRAM)

