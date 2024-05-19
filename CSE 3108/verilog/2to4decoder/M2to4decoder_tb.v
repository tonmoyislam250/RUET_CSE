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
    in = 2'b01;
    #10;
    in = 2'b10;
    #10;
    in = 2'b11;
    #10;
    $finish;
end
initial begin
    $monitor("in=%b, out=%b", in, out);
end
endmodule
