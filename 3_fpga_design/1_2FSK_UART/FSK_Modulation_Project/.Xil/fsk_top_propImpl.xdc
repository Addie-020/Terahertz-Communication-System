set_property SRC_FILE_INFO {cfile:f:/2_FPGA_Projects/2_Advanced_Projects/1_2FSK_UART/FSK_Modulation_Project/FSK_Modulation_Project.srcs/sources_1/ip/clk_wiz_0/clk_wiz_0.xdc rfile:../FSK_Modulation_Project.srcs/sources_1/ip/clk_wiz_0/clk_wiz_0.xdc id:1 order:EARLY scoped_inst:clk_gen_inst/inst} [current_design]
current_instance clk_gen_inst/inst
set_property src_info {type:SCOPED_XDC file:1 line:57 export:INPUT save:INPUT read:READ} [current_design]
set_input_jitter [get_clocks -of_objects [get_ports clk_in1]] 0.2
