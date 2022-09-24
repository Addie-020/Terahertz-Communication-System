// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2020.1 (win64) Build 2902540 Wed May 27 19:54:49 MDT 2020
// Date        : Sun Nov 21 22:53:03 2021
// Host        : DESKTOP-HEGMK6F running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub
//               f:/2_FPGA_Projects/2_Advanced_Projects/1_2FSK_UART/1_Vivado_Project/FSK_Modulation_Project/FSK_Modulation_Project.srcs/sources_1/ip/ila_0/ila_0_stub.v
// Design      : ila_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7a35tfgg484-2
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "ila,Vivado 2020.1" *)
module ila_0(clk, probe0)
/* synthesis syn_black_box black_box_pad_pin="clk,probe0[13:0]" */;
  input clk;
  input [13:0]probe0;
endmodule
