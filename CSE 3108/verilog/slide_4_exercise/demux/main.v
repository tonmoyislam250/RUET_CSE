module demux1to4 (
    input wire in,
    input wire [1:0] sel,
    output wire [3:0] out
);

assign out = (sel == 2'b00) ? 4'b0001 << 0 & {4{in}} :
             (sel == 2'b01) ? 4'b0001 << 1 & {4{in}} :
             (sel == 2'b10) ? 4'b0001 << 2 & {4{in}} :
             (sel == 2'b11) ? 4'b0001 << 3 & {4{in}} : 4'b0000;

endmodule
