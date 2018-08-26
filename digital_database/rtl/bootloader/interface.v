
module interface (
		   input sclk,
		   input nrst,
		   input [15:0] wdata_i,
		   input prog,
		   output reg [7:0] address_o,
		   output reg [15:0] wdata_o,
		   output pwrite_o
		 );

	integer tmp;
	reg pwrite_o_tmp;
	assign pwrite_o = ~pwrite_o_tmp;

	
	always @(posedge sclk or negedge nrst) begin
		
		if(!nrst) begin
			tmp = 0;
			address_o <= 0;
			wdata_o <= 0;
			pwrite_o_tmp = 1;
		end
		else if(sclk) begin
			if(prog) begin		
				pwrite_o_tmp = 1;
				tmp = tmp + 1;
				if(tmp == 16) begin
					#20 address_o <= wdata_i[7:0];
				end
				if(tmp == 32) begin
					tmp = 0;
					pwrite_o_tmp = 0;
					#20 wdata_o <= wdata_i;
				end
				
			end
		end
	end
	
endmodule
