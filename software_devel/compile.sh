#! /bin/sh

./bin/novocharrua2.o $1

./bin/adjust16.sh saida2.txt

rm saida2.txt

output=$(basename $1 .asm)

mv program.bin $output.bin

