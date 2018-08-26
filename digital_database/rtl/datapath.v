module datapath 
      #(
	 parameter integer BITS = 16
       )
	(
	  input CLOCK,
	  input RESETn,
	  input HOLDn,
	  input [4:0]OPCODE,
	  input [10:0]OPERAND,
	  input SEL_JMP,
	  input EN_APB_DATA_MEM,	
	  input EN_APB_INST_MEM,
	  input EN_PC,
	  input EN_IN,
	  input SEL_OP_MEM,
	  input EN_ACC,
	  input [BITS-1 :0] PRDATA_G,
	  output [10:0] PC,
	  output reg[BITS-1 :0] ACC,
	  output reg [1:0]ZN,
	  output reg [7:0]INDR,
	  input EN_INDR,
	  input SEL_BRANCH,
	  input [2:0]state_in,
	  output pc_of,
	  output pc_uf
	);


wire [BITS-1 :0] next_ACC, out_ext, out_mux_mem;
wire  [10:0] out_mux_pc, out_soma;
wire [11:0] out_branch;
reg  [BITS-1 :0] in_alu;
reg  [10:0] reg_pc;

//reg [10:0] old_pc;
//wire pc_of;
//wire pc_uf;


always @(posedge CLOCK, negedge RESETn)
begin
	if(!RESETn)
		INDR<=0;
	else begin
		if(EN_INDR) begin
			if(OPCODE==5'b11101)
				INDR <= PRDATA_G[7:0];
			else if(OPCODE == 5'b11001 || OPCODE == 5'b11000)
				INDR <= INDR + OPERAND[7:0];
		end
	end
end


/* So, the story goes:                                                    -255 to +254   
if branch taken, then verify PC Overflow:              next_pc = pc + 1 + operand[9:0] ; if next_pc has breached the upper memory range (i.e. > than 255), then next_pc = pc + 1 + operand[9:0] - 255 and pc_of = 1.  --next_pc[10:8]=0
   if there wasn't a PC overflow, verify PC Underflow: next_pc = pc + 1 + operand[9:0] ; if next_pc has breached the lower memory range (i.e. < than   0), then next_pc = pc + 1 + operand[9:0] + 255 and pc_uv = 1.  --next_pc[10:8]=0

Otherwise, if JUMP taken, then next_pc = operand[7:0] else next_pc = next_pc + 1;  
*/

wire [10:0] OP_branch;
assign out_mux_pc =  SEL_JMP ? (SEL_BRANCH ? out_soma[7:0] : (pc_of ? out_branch[10:0] + (10'h201) : (pc_uf ? out_branch[10:0] + 10'hFF : out_branch[10:0] ))) : OPERAND[7:0] ;
assign PC = reg_pc;

//Overflow: if branch operation taken, then if next_pc is > 255 && next_pc < 514, means that an overflow occurred
assign pc_of = SEL_BRANCH==0 ? ((out_branch[10:0] > 10'hFF) && (out_branch[10:0] < 10'h200) ? 1 : 0) : (reg_pc==8'hFF && state_in==3'b100 ? 1 : 0 );

//Underflow: if branch operation taken, then if next_pc is <= 767 (or -1)  and greater or equal to 512 (-255), means that an underflow occurred (obs: Unsigned comparison)
assign pc_uf = SEL_BRANCH==0 ? ((out_branch[11] == 1)? 1 : 0) : 0;

assign out_soma = reg_pc + 1;

assign out_branch = reg_pc + {{(3){OPERAND[8]}}, OPERAND[8:0]};





always @(posedge CLOCK, negedge RESETn)
 begin
  if(!RESETn)
    reg_pc <=  {BITS{1'b0}} ;
  else
   begin
    if(EN_PC && HOLDn)
      reg_pc <= out_mux_pc[7:0];
    else
      reg_pc <= reg_pc;

   end

 end


assign out_ext = {{(5){OPERAND[10]}} ,OPERAND};

assign out_mux_mem =  SEL_OP_MEM ? out_ext : PRDATA_G;

always @(posedge CLOCK, negedge RESETn)
 begin
  if(!RESETn)
    in_alu <=  {BITS{1'b0}} ;
  else
   begin
    if(EN_IN)
      in_alu <= out_mux_mem;
    else
      in_alu <= in_alu;
   end
 end

always @(posedge CLOCK, negedge RESETn)
 begin
  if(!RESETn)
    ACC <=  {BITS{1'b0}} ;
  else
   begin
    if(EN_ACC)
      ACC <= next_ACC;
    else
      ACC <= ACC;
   end
 end


alu #16 ALU(.a(in_alu), .acc_in(ACC), .opcode(OPCODE), .acc_out(next_ACC));
 
always @(posedge CLOCK, negedge RESETn)
 begin
  if(!RESETn)
      ZN <= 2'b00;
    else
     begin
      if(ACC == 0)
	ZN <= 2'b10;
      else
       begin
        if(ACC[BITS-1] == 1)
         ZN <= 2'b01;
        else
	 ZN <= 2'b00;
       end
     end
   end

endmodule






