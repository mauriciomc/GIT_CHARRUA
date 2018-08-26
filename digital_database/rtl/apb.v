module apb
  (
    input CLK,
    input RESET,
    input HOLDn,
    input WRITE,
    input EN,
    input [8:0]ADDR,
    input PREADY,
    input [15:0]PRDATA,
    input [15:0]WDATA, 
    output [15:0]PADDR,
    output [2:0]PPROT, 
    output reg PWRITE,
    output reg PSEL,
    output reg PENABLE,
    output [15:0]PWDATA, // comes to datapath and go to memory
    output [15:0]RDATA // data comes to memory and go to control
 );

localparam [1:0]	IDLE = 2'b00,
			SETUP = 2'b01,
			ACCESS = 2'b10;

reg [1:0]state, next_state;
reg en_w;
 
assign PADDR = {{5{1'b0}}, ADDR};
assign PPROT = 3'b010;
assign PWDATA = WDATA;
assign RDATA = PRDATA;

//STATE
always @(posedge CLK or negedge RESET)
 begin
  if(!RESET)
    state <= IDLE;
  else
    begin
      if(!HOLDn)
	state <= state;
      else
	state <= next_state;
      if(WRITE)
       en_w <= 1'b1;
      else	
       en_w <= 1'b0;
    end
 end

//NEXT_STATE
always @(state or EN or PREADY)
 begin
  case(state)
    IDLE: begin
	    if(EN)
	      next_state = SETUP;
	    else
	      next_state = IDLE;
	  end
    SETUP: next_state = ACCESS;
    ACCESS: begin
	      if(!PREADY)
		next_state = ACCESS;
	      else
                begin
		 if(EN)
		  next_state = SETUP;
		 else
		  next_state = IDLE;
	        end
	    end
    default: next_state = IDLE;
  endcase
 end


//OUTPUTS
always @(state or en_w)
 begin
  PWRITE = 1'b0;
  case(state)
    IDLE: begin
	   PSEL = 1'b0;
	   PENABLE = 1'b0;
	  end
    SETUP:begin
	   PSEL = 1'b1;
	   PENABLE = 1'b0;
	   if(en_w)
	    PWRITE = 1'b1;
	  end
    ACCESS:begin
	    PSEL = 1'b1;
	    PENABLE = 1'b1;
	   if(en_w)
	    PWRITE = 1'b1;
	   end
    default: begin
	   PSEL = 1'b0;
	   PENABLE = 1'b0;
	  end
  endcase
 end

endmodule
