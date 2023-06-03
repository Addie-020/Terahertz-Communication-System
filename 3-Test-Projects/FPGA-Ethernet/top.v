`timescale 1ns / 1ps

module top (
	// System Ports
	input            sys_clk_p  ,   	// System clock: positive port
	input            sys_clk_n  ,   	// System clock: negative port
	input            clk_en     ,		// Clock Enable
	input            rst_n      ,		// Asynchronous reset active low
	// SMI Ports
	input            eth_modi   ,
	output           eth_mdc    ,
	output       reg eth_rst    ,
	// RGMII Ports
	input  [3:0]     rgmii_rxd  ,
	input            rgmii_rxc  ,
	input            rgmii_rxctl,
	output [3:0]     rgmii_txd  ,
	output           rgmii_txc  ,
	output           rgmii_txctl
);


/* Define Parameters */

wire       sys_clk;
wire       locked;
reg  [4:0] rst_delay;


/* Set Ethernet Reset */

always @(posedge sys_clk or negedge rst_n) begin
	if(~rst_n) begin
		rst_delay <= 5'd0;
	end else begin
		rst_delay <= rst_delay+5d'1;
	end
end

always @(posedge sys_clk or negedge rst_n) begin
	if(~rst_n) begin
		eth_rst <= 1'd0;
	end else if(rst_delay==5'd19) begin
		eth_rst <= 1'd1;
	end else begin
		eth_rst <= eth_rst;
	end
end

endmodule : top