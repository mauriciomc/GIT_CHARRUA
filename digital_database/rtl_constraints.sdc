
# CLOCK
create_clock -name clk -period 50 -waveform {0 25} [find / -port CLK]
create_clock -name tclk -period 50 -waveform {0 25} [find / -port TCLK]

set_clock_transition 1.0 -rise [get_clocks tlk]
set_clock_transition 1.0 -rise [get_clocks tlk]

set_clock_transition 1.0 -fall [get_clocks clk]
set_clock_transition 1.0 -fall [get_clocks clk]

set_clock_uncertainty -setup 1.5 [get_clocks tclk]
set_clock_uncertainty -setup 1.5 [get_clocks tclk]

set_clock_uncertainty -hold  0.1 [get_clocks clk]
set_clock_uncertainty -hold  0.1 [get_clocks clk]

set_clock_latency 1.0 -rise [get_clocks tclk]
set_clock_latency 1.0 -rise [get_clocks tclk]

set_clock_latency 1.0 -fall [get_clocks clk]
set_clock_latency 1.0 -fall [get_clocks clk]

# INPUTS

set_input_transition 1.736 -rise [all_inputs]
set_input_transition 1.736 -fall [all_inputs]

set_input_delay -clock clk 2.0 [all_inputs]
set_input_delay -clock tclk 2.0 [all_inputs]

# OUTPUTS

set_output_delay -clock clk -min 3.0 [all_outputs]
set_output_delay -clock tclk -min 3.0 [all_outputs]
set_output_delay -clock clk -max 5.0 [all_outputs]
set_output_delay -clock tclk -max 5.0 [all_outputs]

# 5 fF
set_load -pin_load 0.005 [all_outputs]

