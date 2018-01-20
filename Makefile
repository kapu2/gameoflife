#------------------------------------------------------------------------------

SOURCE=main.cpp main.h Board.cpp Board.h
MYPROGRAM=gameoflife
MYINCLUDES=~

CC=g++

#------------------------------------------------------------------------------



all: $(MYPROGRAM)



$(MYPROGRAM): $(SOURCE)

	$(CC) -I$(MYINCLUDES) $(SOURCE) -o$(MYPROGRAM)

clean:

	rm -f $(MYPROGRAM)

