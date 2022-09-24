/*
    Function: AD9767 DAC output
    Author: Addison
*/
module ad9767_output(
    input  wire        clk_sample,  // sampling clock
    input  wire        rst_n     ,  // asynchronous reset (active low)
    input  wire [13:0] data_send ,  // unprecessed data from modules
    output reg  [13:0] da_data   ,  // DAC output data
    output wire        da_clk    ,  // clock send to AD9767
    output wire        da_wrt       // write signal of AD9767
);

    always @(posedge clk_sample or negedge rst_n) begin
        if (~rst_n) begin
            da_data <= 14'd0;
        end else begin
            da_data <= {~data_send[13], data_send[12:0]};
        end
    end

    assign da_clk = clk_sample;
    assign da_wrt = clk_sample;
    
endmodule