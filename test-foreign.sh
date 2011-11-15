#!/bin/sh
CROSSC="$1"
CROSSQ="$2"
CROSSF="$3"

make clean all CC=$CROSSC'-linux-gnu-gcc' CFLAGS='-static '"$CROSSF"
qemu-"$CROSSQ" ./jitchards < hello.jch
