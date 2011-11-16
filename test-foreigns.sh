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

if [ "`which owcc`" ]
then
    echo OpenWatcom
    make clean all CC=owcc CFLAGS='-b win32 -DNOMMAP -fno-stack-check -O0' && mv jitchards jitchards.exe
    WINEPREFIX="$PWD/wine" WINEDEBUG=-all wine jitchards.exe < hello.jch
else
    echo 'WARNING: Not testing OpenWatcom'
fi
space
