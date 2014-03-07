CFLAGS=-Wall -pedantic -g -O2
#LDLIBS=-lm

BIN=gol

$(BIN): main.o 
	$(CC) $(CFLAGS) $(LDLIBS) $^ -o $@

#main.o: file_io.h utility.h boundary.h solution.h
#file_io.o: utility.h

clean:
	$(RM) *.o
	$(RM) $(BIN)
