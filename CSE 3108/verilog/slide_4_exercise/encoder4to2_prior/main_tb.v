module tb_encoder4to2;

reg [3:0] in;
wire [1:0] out;
wire valid;

encoder4to2 uut (
    .in(in),
    .out(out),
    .valid(valid)
);

initial begin
    in = 4'b0000;
    #10 in = 4'b0001;
    #10 in = 4'b0010;
    #10 in = 4'b0100;
    #10 in = 4'b1000;
    #10 in = 4'b0011;
    #10 in = 4'b0110;
    #10 in = 4'b1111;
    #10 $stop;
end

initial begin
    $monitor("Time = %0t: in = %b, out = %b, valid = %b", $time, in, out, valid);
end

endmodule
