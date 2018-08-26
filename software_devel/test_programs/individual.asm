.data
   A - 5
   B - 6
   C - 7
   D - 8
   E - 9
   F - 10
   G - 11
   H - 12
   I - 13
   J - 14
   K - 15
   L - 16
   M - 17
   N - 18
   END - 255
.inst
ORI 962
STO H
AND C  
BNE lab_BER 
lab_BER: 
NOT
SLL 1678
STO E
NOT  
BNE lab_BE2 
NOT
LDI 30
lab_BE2: 
XORI 1091
SLL 1244
ADDI 838
NOT
OR K
AND L
NOT
LDI 1213
ANDI 1252
NOP  
BLT lab_BFM 
STO I
ORI 1442
ORI 183
lab_BFM: 
SUB E
AND E
SLL 1468
XORI 1940
XORI 2024  
BGE lab_BFV 
XOR H
lab_BFV: 
NOT
NOP
NOP
LD F
ORI 1835
NOP  
BNE lab_BF6 
lab_BF6:   
BEQ lab_BF7 
lab_BF7: 
OR G
SUBI 1443  
BEQ lab_BGG   
BLT lab_BGF 
lab_BGF: 
STO N
lab_BGG: 
NOT
NOP  
BGT lab_BGN 
NOP  
BGT lab_BGN 
lab_BGN: 
NOP
NOP
NOT  
BGE lab_BGV 
OR F  
BEQ lab_BGW 
lab_BGV: 
SUBI 697
lab_BGW: 
ADDI 649
AND H
AND E
OR N  
BLE lab_BG5 
lab_BG5: 
NOT
NOT
SRL 1594  
BEQ lab_BHB 
lab_BHB: 
SRL 1680
LDI 2047   
STO END
OK: JMP OK

