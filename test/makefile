CC=gcc
CFLAGS=-I./include -Wall -Wextra -DNON_MATLAB_PARSING -DMAX_EXT_API_CONNECTIONS=255
LDFLAGS=-lpthread

SRCDIR=.
SRC=$(wildcard $(SRCDIR)/*.c)
OBJ=$(SRC:.c=.o)
BIN=cocobot-test-control

.PHONY: all clean mrproper

all: $(BIN)

$(BIN):$(OBJ)
	gcc $(LDFLAGS) $^ -o $@

%.o: %.c
	gcc -c $(CFLAGS) $<

clean:
	@ rm -f $(OBJ) *~

mrproper:
	@ rm -f $(BIN)
