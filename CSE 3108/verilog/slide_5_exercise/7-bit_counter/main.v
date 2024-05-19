`include "adder.v"
`include "register.v"
module counter
(
	input wire CLK,
	input wire Reset,
	output wire [6:0] q
);

	wire [6:0] d_temp, q_temp;
	register register_circuit1 (CLK, Reset, d_temp, q_temp);
	addOne adder_circuit1 (q_temp, d_temp);
	assign q = q_temp;

endmodule
