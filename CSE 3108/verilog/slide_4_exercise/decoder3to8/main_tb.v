module tb_decoder3to8;

reg [2:0] in;
wire [7:0] out;

decoder3to8 uut (
    .in(in),
    .out(out)
);

initial begin
    in = 3'b000;
    #10 in = 3'b001;
    #10 in = 3'b010;
    #10 in = 3'b011;
    #10 in = 3'b100;
    #10 in = 3'b101;
    #10 in = 3'b110;
    #10 in = 3'b111;
    #10 $stop;
end

initial begin
    $monitor("Time = %0t: in = %b, out = %b", $time, in, out);
end

endmodule
