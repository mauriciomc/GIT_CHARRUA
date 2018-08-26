.data
   a - 10
   b - 20
   c - 30
   d - 256
.inst
LDI 0
STO a
LDI 3
STO b
LDI 5
STO c
LD a
ADDI 1
STO a
ADDI 5
STO b
NOP
LD c
ADDI 3
ADD c
ADD b
STO c
LD d
ADD a
ADD b
ADD c
STO d
