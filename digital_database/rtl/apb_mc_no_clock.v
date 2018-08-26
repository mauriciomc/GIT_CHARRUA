`timescale 1 ns / 10 ps
module APB_MEM_CONTROL (
	//clock,
	//resetN,
	A,
	D,
	Q,
	WEn,
	CEn,
	PWrite,
	PSel,
	PEnable,
	PAddress,
	PWData,
	PReady,
	PSLERR,
	PRData
);

//global inputs
//input clock, resetN;

//memory interface
output WEn, CEn;
output [7:0] A;
output [15:0] D;
input [15:0] Q;

//APB interface
input PWrite, PSel, PEnable;
input [8:0] PAddress;
//output PSLERR, PReady;
output PSLERR;
output PReady;
//modified by Mauricio
//original: output [15:0] PRData, PWData;
//modified to
output [15:0] PRData;
input [15:0] PWData;


//Signals assign
assign PReady = 1'b1;
assign PSLERR = 1'b0;
assign PRData = Q;
assign D = PWData;
assign A = PAddress[7:0];

//Translation Signals Assigns.
//This equations respect timings of the APB protocol using only combinational logic.

assign WEn = ~PWrite;
assign CEn = ~(PSel && (PWrite == PEnable));

endmodule

