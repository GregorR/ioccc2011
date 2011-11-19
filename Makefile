CC=gcc
CFLAGS=-g -ansi
LIBS=-lm
LDFLAGS=

OBJS=full.o

all: jitchards

jitchards: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(LIBS) -o jitchards

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) jitchards
