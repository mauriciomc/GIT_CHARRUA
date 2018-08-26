`timescale 1 ns / 1 ps
module control 
	    ( 
	      input CLK,
	      input RESET,
	      input HOLDn,
	      input [15:0]DATA,
	      input [1:0] ZN,
	      input READY_INST,
	      input READY_DATA,
	      output reg SEL_JMP,	
	      output reg SEL_OP_MEM,
	      output reg WRITE,
	      output [4:0]OPCODE,
	      output [10:0]OPERAND,
	      output reg EN_APB_INST_MEM,
	      output reg EN_APB_DATA_MEM,
	      output reg en_PC,
	      output reg en_ACC,
	      output reg en_IN,
	      input TEST_EN,            //Added to manipulate the INSTRUCTION REGISTER using the scan chain and test signals
	      output reg EN_INDR,
	      output reg SEL_INDR,
	      output reg SEL_BRANCH,
	      output [2:0]state_out       	      
	    );

localparam [2:0]	IDLE	= 3'b000,
			PRE_FET = 3'b001,
			FETCH = 3'b010,
			DECODE = 3'b011,
			EXECUTE = 3'b100;

reg [2:0]state, next_state;
wire Z, N;

reg en_INST;
reg [15:0] INST;

always @(posedge CLK, negedge RESET)
 begin
  if(!RESET) begin
    INST <=  {16{1'b0}} ;
  end
  else if(CLK)
   begin
    if(en_INST) begin
      INST <= DATA;
    end
    else begin
      INST <= INST;
    end
  end
end

assign state_out = state;

assign OPCODE = INST[15:11];
assign OPERAND = INST[10:0];
assign Z = ZN[1]; 
assign N = ZN[0];

//STATE
always @(posedge CLK, negedge RESET)
 begin
  if(!RESET)
    state <= IDLE;
  else
   if(!HOLDn)
    state <= state;
   else
    state <= next_state;
 end


//NEXT_STATE
always @(state, INST, READY_DATA)
 begin
  case(state)
   IDLE : next_state = PRE_FET;
   PRE_FET: next_state = FETCH;
   FETCH: if(READY_INST)
	    next_state = DECODE;
	  else
	    next_state = FETCH;
   DECODE: begin
	    #50
               /*          JMP                     BEQ                   BGT                   BGE                   BLT                         BLE     */
	    if( (OPCODE == 5'b01110) || (OPCODE == 5'b01000) || (OPCODE == 5'b01010) || (OPCODE == 5'b01011) || (OPCODE == 5'b01100) ||  (OPCODE == 5'b01101))
	      next_state = IDLE;
	    else
		/*         LD                      ADD                   SUB                    AND                   OR                        XOR                       STO                   STOV                      LDOV                    INDRWR    */
	     if( ((OPCODE == 5'b00010) || (OPCODE == 5'b00100) || (OPCODE == 5'b00110) || (OPCODE == 5'b10000) || (OPCODE == 5'b10010) || (OPCODE == 5'b10100) || (OPCODE == 5'b00001) || (OPCODE == 5'b11000) || (OPCODE == 5'b011001) || (OPCODE == 5'b11101) ) && !READY_DATA)
	       next_state = DECODE;
	    else
	       next_state = EXECUTE;
	   end
   EXECUTE:next_state = PRE_FET;
   default: next_state = IDLE;
  endcase
 end

//OUTPUTS
always @(state, INST, READY_DATA)
 begin	
  SEL_JMP = 1'b1;
  SEL_BRANCH = 1'b1;
  SEL_OP_MEM = 1'b1;
  EN_APB_INST_MEM = 1'b0; 
  EN_APB_DATA_MEM = 1'b0;
  en_PC = 1'b0;
  en_ACC = 1'b0;
  en_IN = 1'b0;
  en_INST = 1'b0;
  WRITE = 1'b0;
  EN_INDR=1'b0;
  SEL_INDR=1'b0;

  case(state)
   IDLE : begin
	   EN_APB_INST_MEM = 1'b1; 
	  
	  end	
 
   FETCH: begin
	      en_INST = 1'b1;
	      en_PC = 1'b1;
	  /*    if((OPCODE == 5'b01110) || ((OPCODE == 5'b01000) && Z) || ((OPCODE == 5'b01010)  && !Z) || ((OPCODE == 5'b01010) && (!Z && !N)) || 
		((OPCODE == 5'b01011) && !N) || ((OPCODE == 5'b01100) && N) ||  ((OPCODE == 5'b01101) && (Z || N)))
	       en_PC = 1'b0;
	      else
	       en_PC = 1'b1;*/
	  end 
   DECODE: begin
		#50 
            /*               LD                   ADD                      ADDI                     AND                     OR                     XOR                   LDV           */
	   if( (OPCODE == 5'b00010) || (OPCODE == 5'b00100) || (OPCODE == 5'b00110) || (OPCODE == 5'b10000) || (OPCODE == 5'b10010) || (OPCODE == 5'b10100) || (OPCODE == 5'b11001 ) ) // MEMORY[OPERAND]
		SEL_OP_MEM = 1'b0; 
           /*              STO              STOV         */
//	   if(OPCODE == 5'b00001 || OPCODE == 5'b11000) //STORE ACC
//	        WRITE = 1'b1; 
                         
           /*                LD                    ADD                     ADDI                     AND                     OR                     XOR                   LDV           */
	   if( ((OPCODE == 5'b00010) || (OPCODE == 5'b00100) || (OPCODE == 5'b00110) || (OPCODE == 5'b10000) || (OPCODE == 5'b10010) || (OPCODE == 5'b10100) || (OPCODE == 5'b11001 )) && READY_DATA) // MEMORY[OPERAND]
		EN_APB_DATA_MEM = 1'b1; 
 		
 			// INDRWR
	   if(OPCODE == 5'b11101)
		EN_INDR=1;
	   
           /*               STO               STOV      */
	   if( (OPCODE == 5'b11001) || (OPCODE == 5'b11000) && READY_DATA )
             begin
		SEL_INDR=1'b1;
		EN_INDR=1'b1;
	   end 
	  
           if( (OPCODE == 5'b00001) || (OPCODE == 5'b11000) && READY_DATA) //STORE ACC
	     begin
		EN_APB_DATA_MEM = 1'b1; 
		#100 WRITE = 1'b1; 
	     end
 
           /*             LDV                  STOV      */
	 
	  //So para deixar mais organizado  
     	  if(OPCODE == 5'b01110) // JMP
	   begin 
		SEL_JMP = 1'b0; 
		en_PC = 1'b1; 
	   end
	  
          if(OPCODE == 5'b01000) // BEQ
	  begin
	    if(Z)
	    begin 
		en_PC = 1'b1; 
		SEL_BRANCH = 1'b0;
	    end
	  end

	  if(OPCODE == 5'b01001) // BNE
	  begin
	    if(!Z)
	    begin 
		en_PC = 1'b1; 
		SEL_BRANCH = 1'b0;
	    end
	  end

	
	  if(OPCODE == 5'b01010) // BGT
	  begin 
	    if(!Z && !N)
	    begin 
		en_PC = 1'b1; 
		SEL_BRANCH = 1'b0;
	    end
	  end

	  if(OPCODE == 5'b01011) // BGE
	  begin
	    if(!N)
	    begin 
		en_PC = 1'b1; 
		SEL_BRANCH = 1'b0;
	    end
	  end

	  if(OPCODE == 5'b01100) // BLT
	  begin
	    if(N)
	    begin 
		en_PC = 1'b1; 
		SEL_BRANCH = 1'b0;
	    end
	  end

	  if(OPCODE == 5'b01101) // BLE
	  begin
	    if(Z || N)
	    begin 
		en_PC = 1'b1; 
		SEL_BRANCH = 1'b0;
	    end
	  end

	    en_IN = 1'b1;
	  end
   EXECUTE: begin
            //#50
	    EN_APB_INST_MEM = 1'b1;
	    en_ACC = 1'b1;
	    if( (OPCODE == 5'b11001) || (OPCODE == 5'b11000) && READY_DATA )
             begin
		SEL_INDR=1'b1;
	    end 

	    end

  endcase
 end

endmodule
