//////////////////////////////////////////////////////////////////////////////////
////                                                                          ////
//// Description:                                                             ////
//// SoC: Charrua CPU + XFAB memories + APB Protocol + Bootloader             ////
////                                                                          ////
//// Version: 1.0                                                             ////
////                                                                          ////
//// Author(s):                                                               ////
//// Mauricio Carvalho, mauricio.m.c@gmail.com                                ////
////                                                                          ////
//// Observations:                                                            ////
//// No specs, use it at your own risk!                                       ////
////                                                                          ////
////                                                                          ////
//////////////////////////////////////////////////////////////////////////////////

`timescale 1 ns / 10 ps

module SoC #( 
		parameter integer nADDR = 8,
		parameter integer nDATA = 16
	    )
	    ( 
		input   CLK,
		input   RST,
		input   HOLDn,

		// TEST SIGNALS
		input   TEST_EN,
		input 	TCLK,

		// BOOTLOADER SIGNALS
		input   PROG,
		output  BUSY,
			//bootloader spi signals		
		input	MOSI,
		input	SCLK,
		output	MISO,
		input   BRSTn,

		// OUTPUT PORT
		output reg [nADDR-1:0] PORT_OUT,
		
		// INPUT PORT
		input [nADDR-1:0] PORT_IN,

		// Over and Underflow pins
		output PC_OF,
		output PC_UF
	);


	// wires inputs and outputs
	//	wire CLK,RST,HOLDn,TEST_EN,TCLK,PROG,BUSY,SCLK,CE_n,MISO,MOSI;
	//	wire [nDATA-1:0] PORT_OUT;

	// internal wires
		
		//Memory signals
			wire ramVDD, ramGND;	

		//Program memory signals
			wire [nADDR-1:0] pm_addr;
			wire [nDATA-1:0] pm_Data;
			wire [nDATA-1:0] pm_Q;
			wire pm_ce;
			wire pm_we; 
			wire pm_ready;


		//General memory signals
			wire [nADDR-1:0] gm_addr;
			wire [nDATA-1:0] gm_Data;
			wire [nDATA-1:0] gm_Q;
			wire gm_ce;
			wire gm_we;
			wire gm_ready;

		
		//APB interface w/ program memory
			wire pm_PWrite, pm_PSel, pm_PEnable;
			wire [15:0] pm_PAddress ;
			wire pm_PSLERR, pm_PReady;
			wire [15:0] pm_PRData, pm_PWData;

		//APB interface w/ general memory
			wire gm_PWrite, gm_PSel, gm_PEnable;
			wire [15:0] gm_PAddress;
			wire gm_PSLERR, gm_PReady;
			wire [15:0] gm_PRData, gm_PWData;




			
////////////////////////////////////////////////////////////////////
////////////    ASSIGNS ////////////////////////////////////////////
	assign ramVDD = 1'b1;
	assign ramGND = 1'b0;		


///////////////////////////////////////////////////////////////////
///////////////  CPU INSTANCE --- CHARRUA ---- ////////////////////
//charrua #(8,16) CPU (


//Netlist
charrua CPU (
		      .CLOCK(CLK),
	   	      .RESETn(RST),
	   	      .HOLDn(HOLDn),
  	   	      .PRDATA_G(gm_PRData),
	   	      .PREADY_G(gm_PReady),
	   	      .PADDR_G(gm_PAddress),	
	   	      .PPROT_G(),               // ????
	   	      .PSEL_G(gm_PSel),
	              .PENABLE_G(gm_PEnable),
	              .PWRITE_G(gm_PWrite),
	              .PWDATA_G(gm_PWData),
	 	      .PRDATA_PM(pm_PRData),
	   	      .PREADY_PM(pm_PReady),
	              .PADDR_PM(pm_PAddress),	
	              .PPROT_PM(),               // ????
	              .PSEL_PM(pm_PSel),
	              .PENABLE_PM(pm_PEnable),
	              .PWRITE_PM(pm_PWrite),
	              .PWDATA_PM(pm_PWData),
		      .TEST_EN(TEST_EN),            //Added to manipulate the INSTRUCTION REGISTER using the scan chain and test signals
		      .PC_OF(PC_OF),  //Overflow flag
		      .PC_UF(PC_UF)   //Underflow flag
		);

////////////////////////////////////////////////////////////////////

///// OUTPUT PORT ///////////////
wire gm_we_tmp;
//Disable writing in memory if the address is outside the memory range. 
//Then put ACC contents to the output port
assign gm_we = gm_PAddress[8] ? 1 : gm_we_tmp;

always @(posedge CLK or negedge RST) begin
	if(!RST) 
		PORT_OUT <= 0;
	else begin
		if(gm_PAddress[8] && !gm_we_tmp)
		    PORT_OUT <= gm_Data[7:0];
		else 
		    PORT_OUT <= PORT_OUT;
	end
end

//// INPUT PORT ////////////////
wire [nDATA-1:0] gm_Q_tmp;
//If selected address is outside the memory range, then the ACC will receive input port contents
assign gm_Q = gm_PAddress[8] ? PORT_IN : gm_Q_tmp;


///////////////////////////////////////////////////////////////////
/////////	 APB GENERAL MEM CONTROLLER WITHOUT CLOCK     /////
///////////////////////////////////////////////////////////////////

APB_MEM_CONTROL APB_GMEM_CTRL  (.A(gm_addr[7:0]),
				.D(gm_Data),
				.Q(gm_Q),
				.WEn(gm_we_tmp),
				.CEn(gm_ce),
				.PWrite(gm_PWrite),	
				.PSel(gm_PSel),
				.PEnable(gm_PEnable),
				.PAddress(gm_PAddress),
				.PWData(gm_PWData),
				.PReady(gm_PReady),
				.PSLERR(gm_PSLERR),
				.PRData(gm_PRData)
);


////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
/////////	 APB PROGRAM MEM CONTROLLER WITHOUT CLOCK     //////
////////////////////////////////////////////////////////////////////

APB_MEM_CONTROL APB_PMEM_CTRL (	.A(pm_addr[7:0]),
				.D(pm_Data),
				.Q(pm_Q),
				.WEn(pm_we),
				.CEn(pm_ce),
				.PWrite(pm_PWrite),	
				.PSel(pm_PSel),
				.PEnable(pm_PEnable),
				.PAddress(pm_PAddress),
				.PWData(pm_PWData),
				.PReady(pm_PReady),
				.PSLERR(pm_SLERR),
				.PRData(pm_PRData)
);

///////////////////////////////////////////////////////////
////// XFAB SPRAM256x16 MEMORY MODELS //////////////////////

/// SIGNALS AND ASSIGNS
wire PMEM_WR;
wire [15:0]PMEM_DI;
wire [7:0]PMEM_AD;
wire boot_we;
wire [7:0]boot_addr;
wire [15:0]boot_data;

assign PMEM_WR = PROG ? boot_we : 0;
assign PMEM_AD = PROG ? boot_addr : pm_addr;
assign PMEM_DI = PROG ? boot_data : pm_Data;


///////////////////////////////////////////////////////////
/////////	 BOOTLOADER 			//////////
/////////////////////////////////////////////////////////

bootloader BOOTLOADER ( 
		.CLK (CLK),
		.NRST (BRSTn),	
		.PROG (PROG), 	
		.MOSI (MOSI),
		.MISO (MISO),
		.address_o (boot_addr),
		.wdata_o (boot_data),
		.pwrite_o (boot_we)
);

//////////////////////////////////////////////////////////
//////////       MEMORIES  ///////////////////////////////
//////////////////////////////////////////////////////////

SPRAM256X16 PMEM (
                          .CS(CLK),
                          .NRST(RST),
                          .EN(1'b0),
                          .RD(~PMEM_WR),
                          .WR(PMEM_WR),
                          .AD(PMEM_AD),//pm_addr),
                          .DI(PMEM_DI),//pm_Data),
                          .ramvdd(ramVDD),
                          .ramgnd(ramGND),
                          .DO(pm_Q),
                          .READY(pm_ready)
         );

SPRAM256X16 GMEM (
                          .CS(~CLK),
                          .NRST(RST),
                          .EN(1'b0),
                          .RD(gm_we),
                          .WR(~gm_we),
                          .AD(gm_addr),
                          .DI(gm_Data),
                          .ramvdd(ramVDD),
                          .ramgnd(ramGND),
                          .DO(gm_Q_tmp),
                          .READY(gm_ready)
         );




endmodule

