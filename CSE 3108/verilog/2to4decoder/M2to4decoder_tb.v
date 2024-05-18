module M2to4decoder_tb;

reg [1:0] in;
wire [3:0] out;

main uut (
    .in(in),
    .out(out)
);

initial begin
    $dumpfile("M2to4decoder_tb.vcd");
    $dumpvars(0, M2to4decoder_tb);
    in = 2'b00;
    #10;
    $display("Input: %b, Output: %b", in, out);
    in = 2'b01;
    #10;
    $display("Input: %b, Output: %b", in, out);
    in = 2'b10;
    #10;
    $display("Input: %b, Output: %b", in, out);
    in = 2'b11;
    #10;
    $display("Input: %b, Output: %b", in, out);
    $finish;
end

endmodule
