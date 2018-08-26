module alu
	#(
	  parameter integer BITS = 16
	)
	(
	 input [BITS-1:0]a,
	 input [BITS-1:0]acc_in,
	 input  [4:0]opcode,
	 output [BITS-1:0]acc_out
	  );

 reg [BITS-1:0]out;


 assign acc_out = out[BITS-1:0];

 always @(a, acc_in, opcode)
  begin
   case(opcode)
    5'b00010: out = a;
    5'b00011: out = a;
    5'b00100: out = acc_in + a;
    5'b00101: out = acc_in + a;
    5'b00110: out = acc_in - a;
    5'b00111: out = acc_in - a;
    5'b01111: out = ~acc_in;
    5'b10000: out = acc_in & a;
    5'b10001: out = acc_in & a;
    5'b10010: out = acc_in | a;
    5'b10011: out = acc_in | a;
    5'b10100: out = acc_in ^ a;
    5'b10101: out = acc_in ^ a;
    5'b10110: out = acc_in << a;
    5'b10111: out = acc_in >> a;
    5'b11001: out = a;
    default: out = acc_in;
   endcase
  end
endmodule
