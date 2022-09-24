/*
    Function: FSK modulation module
    Author: Addison Shen
*/
module fsk_mod #(
    parameter phase_incre1 = 16'd18432,
    parameter phase_incre2 = 16'd22528
) (
    input  wire        clk_sample,  // sampling clock
    input  wire        rst_n     ,  // asynchronous reset (active low)
    input  wire        data_in   ,  // serial input
    output wire [13:0] data_out     // FSK data output
);
    /* Wire define */
    wire [15:0] phase_incre;    // phase increment
    wire [15:0] data_out_r ;    // output data from DDS compiler

    /* Configure DDS compiler to generate sin wave */
    dds_compiler_0 dds_compiler_inst (
        .aclk                (clk_sample ),     // input wire aclk
        .aresetn             (rst_n      ),     // input wire aresetn
        .s_axis_phase_tvalid (1'b1       ),     // input wire s_axis_phase_tvalid
        .s_axis_phase_tdata  (phase_incre),     // input wire [15 : 0] s_axis_phase_tdata
        .m_axis_data_tvalid  (           ),     // output wire m_axis_data_tvalid
        .m_axis_data_tdata   (data_out_r )      // output wire [15 : 0] m_axis_data_tdata
    );

    /*  
     *  Set phase increment according to output frequency
     *  phase increment = fout*2^(phase bit)/fs - 1
     *  fs = 64MHz, fout1 = 27.5MHz, fout2 = 32.5MHz, bit = 16 
    */
    assign phase_incre = data_in ? phase_incre1 : phase_incre2;

    /* Output data bit convert */
    assign data_out = data_out_r[13:0];

endmodule