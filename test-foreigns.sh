#!/bin/sh
space() { echo; echo; echo; }

echo native
make clean all CFLAGS='-O3 -fno-align-functions -fno-toplevel-reorder -fno-optimize-sibling-calls'
./jitchards < hello.jch
space

echo 32
make clean all CFLAGS='-m32 -O3 -fno-align-functions -fno-toplevel-reorder -fno-optimize-sibling-calls'
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

echo ppc
./test-foreign.sh powerpc ppc -O3
space

echo ppc64
./test-foreign.sh powerpc ppc '-mpowerpc64 -O3'
space

echo alpha
./test-foreign.sh alphaev56-unknown alpha
space

echo arm
make clean all CC=arm-linux-gnueabi-gcc CFLAGS='-static -O3 -fno-toplevel-reorder'
qemu-arm ./jitchards < hello.jch
space

if [ "`which owcc`" ]
then
    echo OpenWatcom
    make clean all CC=owcc CFLAGS='-b win32 -DNOMMAP -fno-stack-check -O0' 2> /dev/null && mv jitchards jitchards.exe
    WINEPREFIX="$PWD/wine" WINEDEBUG=-all wine jitchards.exe < hello.jch
    rm -f jitchards.exe
else
    echo 'WARNING: Not testing OpenWatcom'
fi
space

if [ "`which tcc`" ]
then
    echo tcc
    make clean all CC=tcc CFLAGS=-O2
    ./jitchards < hello.jch
else
    echo 'WARNING: Not testing tcc'
fi
space

make clean
