/*
    Function: Top module for 2FSK modulation
    Author: Addison Shen
*/
module fsk_top(
    input  wire        sys_clk  ,   // system clock
    input  wire        sys_rst_n,   // asynchronous reset (active low)
    input  wire        uart_rxd ,   // data received from uart port
    output wire [13:0] da_data1 ,   // DAC output data
    output wire        da_clk1  ,   // clock send to AD9767
    output wire        da_wrt1      // write signal of AD9767
);

    /* Variable define */
    wire        clk_sample;
    wire [13:0] data_fsk  ;

    /* Generate sampling clock */
    clk_wiz_0 clk_gen_inst
    (
        .clk_sample (clk_sample),   // output clk_sample
        .resetn     (sys_rst_n ),   // input resetn
        .clk_in1    (sys_clk   )    // input clk_in1
    );

    /* Generate FSK modulation wave */
    fsk_mod #(
        .phase_incre1 (16'd18432),
        .phase_incre2 (16'd22528)
    ) fsk_mod_inst (
        .clk_sample (clk_sample),  // sampling clock
        .rst_n      (sys_rst_n ),  // asynchronous reset (active low)
        .data_in    (uart_rxd  ),  // serial input
        .data_out   (data_fsk  )   // FSK data output
    );

    /* Match FSK data with AD9767 */
    ad9767_output ad9767_inst
    (
        .clk_sample(clk_sample),  // sampling clock
        .rst_n     (sys_rst_n ),  // asynchronous reset (active low)
        .data_send (data_fsk  ),  // unprecessed data from modules
        .da_data   (da_data1  ),  // DAC output data
        .da_clk    (da_clk1   ),  // clock send to AD9767
        .da_wrt    (da_wrt1   )   // write signal of AD9767
    );

endmodule