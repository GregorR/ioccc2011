CC=gcc
CFLAGS=-g -ansi -pedantic
LDFLAGS=

OBJS=full.o

all: jitchards

jitchards: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o jitchards

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) jitchards
