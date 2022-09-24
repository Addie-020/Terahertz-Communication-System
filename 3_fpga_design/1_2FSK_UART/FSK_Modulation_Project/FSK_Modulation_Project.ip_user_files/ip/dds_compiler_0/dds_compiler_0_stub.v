// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2020.1 (win64) Build 2902540 Wed May 27 19:54:49 MDT 2020
// Date        : Sat Nov 20 11:47:05 2021
// Host        : DESKTOP-HEGMK6F running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub
//               f:/2_FPGA_Projects/2_Advanced_Projects/1_2FSK_UART/1_Vivado_Project/FSK_Modulation_Project/FSK_Modulation_Project.srcs/sources_1/ip/dds_compiler_0/dds_compiler_0_stub.v
// Design      : dds_compiler_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7a35tfgg484-2
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* x_core_info = "dds_compiler_v6_0_20,Vivado 2020.1" *)
module dds_compiler_0(aclk, aresetn, s_axis_phase_tvalid, 
  s_axis_phase_tdata, m_axis_data_tvalid, m_axis_data_tdata)
/* synthesis syn_black_box black_box_pad_pin="aclk,aresetn,s_axis_phase_tvalid,s_axis_phase_tdata[15:0],m_axis_data_tvalid,m_axis_data_tdata[15:0]" */;
  input aclk;
  input aresetn;
  input s_axis_phase_tvalid;
  input [15:0]s_axis_phase_tdata;
  output m_axis_data_tvalid;
  output [15:0]m_axis_data_tdata;
endmodule
