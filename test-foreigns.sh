#!/bin/sh
space() { echo; echo; echo; }

echo native
make clean all CFLAGS=-O3
./jitchards < 5.dc
space

echo 32
make clean all CFLAGS='-m32 -O3'
./jitchards < 5.dc
space

echo clang
make clean all CC=clang CFLAGS=-O3
./jitchards < 5.dc
space

echo clang-32
make clean all CC=clang CFLAGS='-m32 -O3'
./jitchards < 5.dc
space

#echo sparc
#./test-foreign.sh sparc sparc32plus
#space

echo mips
./test-foreign.sh mips mips -O3
space

echo mipsel
./test-foreign.sh mipsel mipsel -O3
space

echo ppc
./test-foreign.sh powerpc ppc -O3
space

echo ppc64
./test-foreign.sh powerpc ppc '-mpowerpc64 -O3'
space

echo alpha
./test-foreign.sh alphaev56-unknown alpha -O3
space

echo sh4
./test-foreign.sh sh4-unknown sh4
space

echo arm
make clean all CC=arm-linux-gnueabi-gcc CFLAGS='-static -O3'
qemu-arm ./jitchards < 5.dc
space

if [ "`which owcc`" ]
then
    echo OpenWatcom
    make clean all CC=owcc CFLAGS='-b win32 -DNOMMAP -DAH -fno-stack-check' 2> /dev/null && mv jitchards jitchards.exe
    WINEPREFIX="$PWD/wine" WINEDEBUG=-all wine jitchards.exe < 5.dc
    rm -f jitchards.exe
else
    echo 'WARNING: Not testing OpenWatcom'
fi
space

if [ "`which tcc`" ]
then
    echo tcc
    make clean all CC=tcc CFLAGS=-O2
    ./jitchards < 5.dc
else
    echo 'WARNING: Not testing tcc'
fi
space

make clean
