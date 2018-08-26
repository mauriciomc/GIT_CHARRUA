
module spi_slave (
		input nrst,
		input prog, 
		input sclk,
		input mosi,
		output reg miso,
		output [15:0] wdata
	);

	
	reg [15:0] wdata_tmp;
	assign wdata = wdata_tmp;
	always @(posedge sclk or negedge nrst) begin
		if (!nrst) begin
			wdata_tmp <= 0;
			miso <= 0;
		end
		else if(sclk) begin
			if(prog) begin 
				wdata_tmp[0] <= mosi; 
				wdata_tmp[1] <= wdata_tmp[0];
				wdata_tmp[2] <= wdata_tmp[1];
				wdata_tmp[3] <= wdata_tmp[2];
				wdata_tmp[4] <= wdata_tmp[3];
				wdata_tmp[5] <= wdata_tmp[4];
				wdata_tmp[6] <= wdata_tmp[5];
				wdata_tmp[7] <= wdata_tmp[6];
				wdata_tmp[8] <= wdata_tmp[7]; 
				wdata_tmp[9] <= wdata_tmp[8];
				wdata_tmp[10] <= wdata_tmp[9];
				wdata_tmp[11] <= wdata_tmp[10];
				wdata_tmp[12] <= wdata_tmp[11];
				wdata_tmp[13] <= wdata_tmp[12];
				wdata_tmp[14] <= wdata_tmp[13];
				wdata_tmp[15] <= wdata_tmp[14];
				miso <= wdata_tmp[15];
			end
	        end
	end
endmodule
	
