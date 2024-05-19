module demux1to4_if (
    input wire in,
    input wire [1:0] sel,
    output reg [3:0] out
);

always @(*) begin
    out = 4'b0000;
    if (sel == 2'b00)
        out[0] = in;
    else if (sel == 2'b01)
        out[1] = in;
    else if (sel == 2'b10)
        out[2] = in;
    else if (sel == 2'b11)
        out[3] = in;
end

endmodule
