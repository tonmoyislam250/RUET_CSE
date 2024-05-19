module d_ff_reset_en 
(
	input wire clk,
	input wire reset,
	input wire en,
	input wire d,
	output reg q
);

always @(posedge clk, posedge reset)
begin
	if (reset)
    	q <= 1'b0;
	else if (en)
    	q <= d;   
end    
endmodule
