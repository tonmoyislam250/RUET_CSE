module register 
(
	input wire clk,
	input wire reset,
	input wire [6:0] d,
	output reg [6:0] q
);

always @(posedge clk, posedge reset)
begin
	if (reset)
    	q <= 7'b0000_000;
	else
    	q <= d;   
end
    
endmodule
