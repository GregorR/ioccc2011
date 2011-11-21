CC=gcc
CFLAGS=-g -ansi
LIBS=-lm
LDFLAGS=

OBJS=jitdc.o

all: jitdc

jitdc: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(LIBS) -o jitdc

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) jitdc
