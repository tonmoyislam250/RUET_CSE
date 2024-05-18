module main (
    input [1:0] in,
    output [3:0] out
);

assign out[0] = ~in[1] & ~in[0];  // 00
assign out[1] = ~in[1] &  in[0];  // 01
assign out[2] =  in[1] & ~in[0];  // 10
assign out[3] =  in[1] &  in[0];  // 11

endmodule
