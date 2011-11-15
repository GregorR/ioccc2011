#!/bin/sh
space() { echo; echo; echo; }

echo native
make clean all CFLAGS='-O3 -fno-align-functions -fno-optimize-sibling-calls -fno-peephole2'
./jitchards < hello.jch
space

echo 32
make clean all CFLAGS='-m32 -O3 -fno-align-functions -fno-optimize-sibling-calls -fno-peephole2'
./jitchards < hello.jch
space

echo sparc
./test-foreign.sh sparc sparc32plus
space

echo mips
./test-foreign.sh mips mips '-O1 -fno-delayed-branch'
space

echo mipsel
./test-foreign.sh mipsel mipsel '-O1 -fno-delayed-branch'
space
