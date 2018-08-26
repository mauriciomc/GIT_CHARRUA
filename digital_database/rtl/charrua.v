module charrua 
      #(
	  parameter integer BITS_PC = 11,
	  parameter integer BITS_INST = 16
	)
	(
	  input CLOCK,
	  input RESETn,
	  input HOLDn,
	  //GENERAL MEMORY INTERFACES
	  input [15:0]PRDATA_G,
	  input PREADY_G,
	  output [15:0]PADDR_G,	
	  output [2:0] PPROT_G,
	  output PSEL_G,
	  output PENABLE_G,
	  output PWRITE_G,
	  output [15:0]PWDATA_G,
	  //PROGRAM MEMORYINTERFACES
	  input [15:0]PRDATA_PM,
	  input PREADY_PM,
	  output [15:0]PADDR_PM,	
	  output [2:0] PPROT_PM,
	  output PSEL_PM,
	  output PENABLE_PM,
	  output PWRITE_PM,
	  output [15:0]PWDATA_PM,
	  input TEST_EN,           //Added to manipulate the INSTRUCTION REGISTER using the scan chain and test signals
	  output PC_OF,
	  output PC_UF
	);

/////// WIRES  //////////


/////// Control_Unit ///////
 
 wire [1:0]ZN;
 wire [10:0]OPERAND, PC;
 wire SEL_OP_MEM, en_ACC, en_IN, EN_APB_DATA_MEM, EN_APB_INST_MEM, SEL_JMP, en_PC;
 wire [4:0]OPCODE;		
 wire [2:0]state;             
///////////////////////////

///////     ALU     ///////
 
 wire [15:0]ACC;
///////////////////////////

// WIRES APB PROGRAM MEMM //
 
 wire [BITS_INST-1:0]DATA_PM, DATA_G;
////////////////////////////

////  APB GENERAL MEM  ////
 
 wire WRITE_G;

/////// INDIRECT ADDRESS FOR VECTOR OPERATION ////////

wire [7:0]INDR;
wire EN_INDR, SEL_INDR;
wire SEL_BRANCH;

//////////////////////module/////



datapath #16 Data_Path (.CLOCK(CLOCK), 
			.RESETn(RESETn), 
			.HOLDn(HOLDn), 
			.OPCODE(OPCODE), 
			.OPERAND(OPERAND), 
			.SEL_JMP(SEL_JMP), 
			.EN_APB_DATA_MEM(EN_APB_DATA_MEM),	
		        .EN_APB_INST_MEM(EN_APB_INST_MEM), 
			.EN_PC(en_PC), 
			.EN_IN(en_IN), 
			.SEL_OP_MEM(SEL_OP_MEM), 
			.EN_ACC(en_ACC), 
			.PRDATA_G(DATA_G), 
			.PC(PC), 
			.ACC(ACC), 
			.ZN(ZN), 
			.EN_INDR(EN_INDR), 
			.INDR(INDR), 
			.SEL_BRANCH(SEL_BRANCH), 
			.state_in(state),
			.pc_of(PC_OF),
			.pc_uf(PC_UF) );

///////////////////////////////////////////////////////////
/////////	 	CONTROL UNIT		//////////
/////////////////////////////////////////////////////////

 control Control_Unit (.CLK(CLOCK), .RESET(RESETn), .HOLDn(HOLDn) , .DATA(DATA_PM), 
		       .ZN(ZN), .READY_INST(PREADY_PM), .READY_DATA(PREADY_G), .SEL_JMP(SEL_JMP), 
		       .SEL_OP_MEM(SEL_OP_MEM), .WRITE(WRITE_G), 
		       .OPCODE(OPCODE), .OPERAND(OPERAND), 
		       .EN_APB_INST_MEM(EN_APB_INST_MEM), .EN_APB_DATA_MEM(EN_APB_DATA_MEM), .en_PC(en_PC),
		       .en_ACC(en_ACC), 
		       .en_IN(en_IN),
		       .EN_INDR(EN_INDR),
		       .SEL_INDR(SEL_INDR),
		       .SEL_BRANCH(SEL_BRANCH),
		       .state_out(state) );

//////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
/////////	 APB(INST) PROGRAM MEM		//////////
/////////////////////////////////////////////////////////

 apb APB_PROG_MEM(.CLK(CLOCK), .RESET(RESETn), .HOLDn(HOLDn), .WRITE(1'b0), //ENABLE WRITE 
		  .EN(EN_APB_INST_MEM), .ADDR(PC), .PREADY(PREADY_PM), 
		  .PRDATA(PRDATA_PM), .WDATA(16'h0000), .PADDR(PADDR_PM),         //WDATA and WRITE signals must be controlled by the BOOTLOADER
		  .PPROT(PPROT_PM), .PWRITE(PWRITE_PM), .PSEL(PSEL_PM), 
		  .PENABLE(PENABLE_PM), .PWDATA(PWDATA_PM), .RDATA(DATA_PM) 
		  );
//////////////////////////////////////////////////////////

wire [8:0] GM_ADDR;
assign GM_ADDR = SEL_INDR ? INDR : OPERAND;

///////////////////////////////////////////////////////////
/////////	 APB GENERAL MEM		//////////
/////////////////////////////////////////////////////////

apb APB_GEN_MEM(.CLK(CLOCK), .RESET(RESETn), .HOLDn(HOLDn) ,.WRITE(WRITE_G), //ENABLE WRITE 
		   .EN(EN_APB_DATA_MEM), .ADDR(GM_ADDR), .PREADY(PREADY_G), 
		   .PRDATA(PRDATA_G), .WDATA(ACC), .PADDR(PADDR_G), 
		   .PPROT(PPROT_G), .PWRITE(PWRITE_G), .PSEL(PSEL_G), 
		   .PENABLE(PENABLE_G), .PWDATA(PWDATA_G), .RDATA(DATA_G) 
		  );

//////////////////////////////////////////////////////////




endmodule



