/*
	Function: Uart receive module for FPGA, receive 8 bit a time
	Author: Addison Shen
*/

module uart_recv(
	input  wire	      clk      ,
	input  wire       rst_n    ,
	
	input  wire	      uart_rxd ,
	output reg  [9:0] uart_data,
	output reg		  uart_done
);
	
	parameter CLK_FREQ = 50_000_000         ;
	parameter UART_BPS = 115_200            ;
	parameter BPS_CNT  = CLK_FREQ / UART_BPS;
	
	reg [7:0] rx_data    ;
	reg [3:0] rx_cnt     ;
	reg	[8:0] clk_cnt    ;
	reg       rx_flag    ;
	reg       uart_rxd_d0;
	reg       uart_rxd_d1;
	wire      start_flag ;
	
	assign start_flag = (~uart_rxd_d0) & uart_rxd_d1;
	
	always @(posedge clk or negedge rst_n) begin	
		if(~rst_n) begin
			uart_rxd_d0 <= 1'b0;
			uart_rxd_d1 <= 1'b0;
		end else begin
			uart_rxd_d0 <= uart_rxd	  ;
			uart_rxd_d1 <= uart_rxd_d0;
		end
	end
	
	/* 
	 *	when detect negative edge, start receiving process
	 *	pause receiving process after 8 bits received
	*/ 
	always @(posedge clk or negedge rst_n) begin	
		if(~rst_n) begin
			rx_flag <= 1'b0;
		end else begin
			if(start_flag) begin
				rx_flag <= 1'b1;
			end else if((rx_cnt == 4'd9) && (clk_cnt == BPS_CNT / 2)) begin
				rx_flag <= 1'b0;
			end else begin
				rx_flag <= rx_flag;
			end
		end
	end
	
	always @(posedge clk or negedge rst_n) begin	
		if(~rst_n) begin
			clk_cnt <= 9'd0;
		end else if(rx_flag) begin
			if(clk_cnt < BPS_CNT - 1) begin
				clk_cnt <= clk_cnt + 1'b1;
			end else begin
				clk_cnt <= 1'b0;
		    end
		end else begin
			clk_cnt <= 9'd0;
		end
	end
	
	always @(posedge clk or negedge rst_n) begin	
		if(~rst_n) begin
			rx_cnt <= 4'd0;
		end else if(rx_flag) begin
			if(clk_cnt == BPS_CNT - 1) begin
				rx_cnt <= rx_cnt + 1'b1;
			end else begin
				rx_cnt <= rx_cnt;
			end
		end else begin
			rx_cnt <= 4'd0;
		end
	end
	
	// store data received in order
	always @(posedge clk or negedge rst_n) begin	
		if(~rst_n) begin
			rx_data <= 8'd0;
		end else if(rx_flag) begin
			if(clk_cnt == BPS_CNT / 2) begin
				case(rx_cnt)
					4'd1: rx_data[0] <= uart_rxd_d1;
					4'd2: rx_data[1] <= uart_rxd_d1;
					4'd3: rx_data[2] <= uart_rxd_d1;
					4'd4: rx_data[3] <= uart_rxd_d1;
					4'd5: rx_data[4] <= uart_rxd_d1;
					4'd6: rx_data[5] <= uart_rxd_d1;
					4'd7: rx_data[6] <= uart_rxd_d1;
					4'd8: rx_data[7] <= uart_rxd_d1;
					default: 					   ;
				endcase
			end else begin
				rx_data <= rx_data;
			end
		end else begin
			rx_data <= 8'd0;
		end
	end

	// enable output process after 8 bits received
	always @(posedge clk or negedge rst_n) begin	
		if(~rst_n) begin
			uart_data <= 8'd0;
			uart_done <= 1'b0;
		end else if(rx_cnt == 4'd9) begin
			uart_data <= rx_data;
			uart_done <= 1'b1	;
		end else begin
			uart_data <= 8'd0;
			uart_done <= 1'b0;
		end
	end

endmodule