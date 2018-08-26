#! /bin/sh

cat saida2.txt | cut -b 2-6 > OPCODE
cat saida2.txt | cut -b 22-32 > OPERAND

INIT=`wc -l OPCODE | cut -d' ' -f1`

paste OPCODE OPERAND | tr -d '\t' > program.bin

rm OPCODE OPERAND

 
for (( i=$INIT; i<256; i++)); do
	echo "0000000000000000" >> program.bin
done
