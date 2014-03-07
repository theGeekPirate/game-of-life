CFLAGS=-Wall -pedantic -g -O2
#LDLIBS=-lm

BIN=gameoflife

$(BIN): main.o utility.o rules.o
	$(CC) $(CFLAGS) $(LDLIBS) $^ -o $@

main.o: utility.h utility.c rules.h rules.c

clean:
	$(RM) *.o
	$(RM) $(BIN)
