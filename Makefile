CC=gcc
CFLAGS=-g
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
