module bootloader ( 
		input CLK,
		input NRST,	
		input PROG, 	
		input MOSI,
		output MISO,
		output [7:0] address_o,
		output [15:0] wdata_o,
		output pwrite_o
);

wire [15:0]wdata;

interface INTERFACE(
		   .sclk (CLK),
		   .nrst (NRST),
		   .wdata_i (wdata),
		   .prog(PROG),
		   .address_o (address_o),
		   .wdata_o (wdata_o),
		   .pwrite_o(pwrite_o)
		 );

spi_slave SPI (
		.nrst(NRST),
		.prog (PROG), 
		.sclk (CLK),
		.mosi (MOSI),
		.miso (MISO),
		.wdata (wdata)
	);

endmodule
