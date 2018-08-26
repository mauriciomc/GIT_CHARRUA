
module SPRAM256X16 (NRST, CS, RD, WR, EN, AD, DI, READY, DO, ramvdd, ramgnd);
output [15:0]   DO;
input [15:0]    DI;
output          READY;
input  [7:0]    AD;
input           CS, EN, NRST, WR, RD;
input           ramvdd, ramgnd;

wire READY_HIGH;
wire READY_LOW;

assign READY = READY_HIGH & READY_LOW;


SPRAM256X8 HIGH (.NRST(NRST), .CS(CS), .RD(RD), .WR(WR), .EN(EN), .AD(AD),.DI(DI[15:8]),.READY(READY_HIGH),.DO(DO[15:8]), .ramvdd(ramvdd), .ramgnd(ramgnd));
SPRAM256X8 LOW  (.NRST(NRST), .CS(CS), .RD(RD), .WR(WR), .EN(EN), .AD(AD),.DI(DI[7:0]),.READY(READY_LOW),.DO(DO[7:0]), .ramvdd(ramvdd), .ramgnd(ramgnd));


endmodule
