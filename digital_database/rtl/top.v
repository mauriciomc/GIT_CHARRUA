//////////////////////////////////////////////////////////////////////////////////
//// Part of the PMUB project CEITEC                                          ////
////                                                                          ////
//// Description:                                                             ////
//// Charrua SoC Top level.                                                   ////
//// **This project is a 'real case' benchmark for evaluating the cell        ////   
////   Library named CTC06LA ordered by the CEITEC.SA foundry                 ////
////                                                                          ////
//// Version: 1.1                                                             ////
////                                                                          ////
//// Author(s):                                                               ////
//// Mauricio Carvalho, mauricio.m.c@gmail.com                                ////
//// Thiago Nagel Oliveira, thiago.oliveira@nscad.org.br                      //// 
////                                                                          ////
//// Observations:                                                            ////
//// This file was developed over the processor functional document.          ////
//// Several comments on this code refers to that documentation.              ////
//// ref1. documents/PMUB_Charrua.pdf                                         ////
//// ref2. documents/functional_charrua_processor.odt                         ////
//// ref3. documents/structural_charrua_processor.odt                         ////
//////////////////////////////////////////////////////////////////////////////////

module top(CLK, RST, HOLDn, PROG, MOSI, MISO, BRSTn, PORT_OUT, PORT_IN, PC_OF, PC_UF, TEN, TRST, TCLK, SDI, SDO, SE, PAD_TEST_OUT);

  input CLK, RST, HOLDn, PROG, MOSI, BRSTn, TEN, TRST, TCLK, SDI, SE;
  input [7:0] PORT_IN;
  output MISO, PC_OF, PC_UF, SDO, PAD_TEST_OUT;
  output [7:0] PORT_OUT;

  wire CLK, RST, HOLDn, PROG, MOSI, BRSTn, TEN, TRST, TCLK, SDI, SE, PAD_TEST_OUT;
  wire [7:0] PORT_IN;
  wire MISO, PC_OF, PC_UF, SDO;
  wire [7:0] PORT_OUT;


  wire CLK_c, RST_c, HOLDn_c, PROG_c, MOSI_c, BRSTn_c, TEN_c, TRST_c, TCLK_c, SDI_c, SE_c;
  wire [7:0] PORT_IN_c;
  wire MISO_c, PC_OF_c, PC_UF_c, SDO_c;
  wire [7:0] PORT_OUT_c;
  
  // NAND TREE CONNECTION from Port_in_0 - Port_in_7, MOSI, BRST, PROG, CLK,
  // RST, HOLD, TCLK, TRST, SE, TEN, SDI ---> PAD_TEST_OUT
  wire  PORT_IN_0_PO, 
        PORT_IN_1_PO,
	PORT_IN_2_PO, 
	PORT_IN_3_PO, 
	PORT_IN_4_PO,
	PORT_IN_5_PO,
	PORT_IN_6_PO, 
	PORT_IN_7_PO, 
	MOSI_PO,
	BRST_PO,
	PROG_PO, 
	CLK_PO,
	RST_PO, 
	HOLD_PO, 
	TCLK_PO, 
	TRST_PO, 
	SE_PO, 
	TEN_PO, 
	SDI_PO ;

wire VDD5R, GND5R, GND5O, VDD5O;

wire logic_0_1_net, logic_1_1_net;

SoC SOC(CLK_c, RST_c, HOLDn_c, PROG_c, MOSI_c, MISO_c, BRSTn_c, PORT_OUT_c, PORT_IN_c, PC_OF_c, PC_UF_c, TEN_c, TRST_c, TCLK_c, SDI_c, SDO_c, SE_c);

ICP PORT_IN_0_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.PAD(PORT_IN[0]),
	.PI(logic_1_1_net),
	.Y(PORT_IN_c[0]),
	.PO(PORT_IN_0_PO));

ICP PORT_IN_1_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.PAD(PORT_IN[1]),
	.PI(PORT_IN_0_PO),
	.Y(PORT_IN_c[1]),
	.PO(PORT_IN_1_PO));

ICP PORT_IN_2_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.PAD(PORT_IN[2]),
	.PI(PORT_IN_1_PO),
	.Y(PORT_IN_c[2]),
	.PO(PORT_IN_2_PO));

ICP PORT_IN_3_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.PAD(PORT_IN[3]),
	.PI(PORT_IN_2_PO),
	.Y(PORT_IN_c[3]),
	.PO(PORT_IN_3_PO));

ICP PORT_IN_4_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.PAD(PORT_IN[4]),
	.PI(PORT_IN_3_PO),
	.Y(PORT_IN_c[4]),
	.PO(PORT_IN_4_PO));

ICP PORT_IN_5_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.PAD(PORT_IN[5]),
	.PI(PORT_IN_4_PO),
	.Y(PORT_IN_c[5]),
	.PO(PORT_IN_5_PO));

ICP PORT_IN_6_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.PAD(PORT_IN[6]),
	.PI(PORT_IN_5_PO),
	.Y(PORT_IN_c[6]),
	.PO(PORT_IN_6_PO));

ICP PORT_IN_7_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.PAD(PORT_IN[7]),
	.PI(PORT_IN_6_PO),
	.Y(PORT_IN_c[7]),
	.PO(PORT_IN_7_PO));

ICP MOSI_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.PAD(MOSI),
	.PI(PORT_IN_7_PO),
	.Y(MOSI_c),
	.PO(MOSI_PO));


ICP BRSTn_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.PAD(BRSTn),
	.PI(MOSI_PO),
	.Y(BRSTn_c),
	.PO(BRST_PO));

ICP PROG_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.PAD(PROG),
	.PI(BRST_PO),
	.Y(PROG_c),
	.PO(PROG_PO));

ICP CLK_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.PAD(CLK),
	.PI(PROG_PO),
	.Y(CLK_c),
	.PO(CLK_PO));

ICP RST_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.PAD(RST),
	.PI(CLK_PO),
	.Y(RST_c),
	.PO(RST_PO));

ICP HOLDn_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.PAD(HOLDn),
	.PI(RST_PO),
	.Y(HOLDn_c),
	.PO(HOLD_PO));

ICP TCLK_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.PAD(TCLK),
	.PI(HOLD_PO),
	.Y(TCLK_c),
	.PO(TCLK_PO));

ICP TRST_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.PAD(TRST),
	.PI(TCLK_PO),
	.Y(TRST_c),
	.PO(TRST_PO));

ICP SE_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.PAD(SE),
	.PI(TRST_PO),
	.Y(SE_c),
	.PO(SE_PO));

ICP TEN_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.PAD(TEN),
	.PI(SE_PO),
	.Y(TEN_c),
	.PO(TEN_PO));

ICP SDI_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.PAD(SDI),
	.PI(TEN_PO),
	.Y(SDI_c),
	.PO(SDI_PO));

BT8P PAD_TEST_OUT_PAD (.VDD5O(VDD5O),
        .CLAMPC(),
        .VDD5R(VDD5R),
        .GND5R(GND5R),
        .GND5O(GND5O),
        .A(SDI_PO),
        .EN(logic_0_1_net),
        .PAD(PAD_TEST_OUT));

BT8P MISO_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.A(MISO_c),
	.EN(logic_0_1_net),
	.PAD(MISO));

BT8P PCOF_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.A(PC_OF_c),
	.EN(logic_0_1_net),
	.PAD(PC_OF));

BT8P PORT_OUT_0_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.A(PORT_OUT_c[0]),
	.EN(logic_0_1_net),
	.PAD(PORT_OUT[0]));

BT8P PORT_OUT_1_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.A(PORT_OUT_c[1]),
	.EN(logic_0_1_net),
	.PAD(PORT_OUT[1]));

BT8P PORT_OUT_2_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.A(PORT_OUT_c[2]),
	.EN(logic_0_1_net),
	.PAD(PORT_OUT[2]));

BT8P PORT_OUT_3_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.A(PORT_OUT_c[3]),
	.EN(logic_0_1_net),
	.PAD(PORT_OUT[3]));

BT8P PORT_OUT_4_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.A(PORT_OUT_c[4]),
	.EN(logic_0_1_net),
	.PAD(PORT_OUT[4]));

BT8P PORT_OUT_5_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.A(PORT_OUT_c[5]),
	.EN(logic_0_1_net),
	.PAD(PORT_OUT[5]));

BT8P PORT_OUT_6_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.A(PORT_OUT_c[6]),
	.EN(logic_0_1_net),
	.PAD(PORT_OUT[6]));

BT8P PORT_OUT_7_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.A(PORT_OUT_c[7]),
	.EN(logic_0_1_net),
	.PAD(PORT_OUT[7]));

BT8P PCUF_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.A(PC_UF_c),
	.EN(logic_0_1_net),
	.PAD(PC_UF));

BT8P SDO_PAD (.VDD5O(VDD5O),
	.CLAMPC(),
	.VDD5R(VDD5R),
	.GND5R(GND5R),
	.GND5O(GND5O),
	.A(SDO_c),
	.EN(logic_0_1_net),
	.PAD(SDO));

   LOGIC_0 tie_0_cell (.Q(logic_0_1_net));
   LOGIC_1 tie_1_cell (.Q(logic_1_1_net));

endmodule
