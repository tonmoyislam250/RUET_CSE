module mux4to1_if (
    input wire [1:0] sel,
    input wire [3:0] in,
    output reg out
);

always @(*) begin
    if (sel == 2'b00)
        out = in[0];
    else if (sel == 2'b01)
        out = in[1];
    else if (sel == 2'b10)
        out = in[2];
    else
        out = in[3];
end

endmodule
