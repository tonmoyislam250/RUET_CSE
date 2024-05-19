module mux4to1 (
    input wire [1:0] sel,
    input wire [3:0] in,
    output wire out
);

assign out = in[sel];

endmodule
