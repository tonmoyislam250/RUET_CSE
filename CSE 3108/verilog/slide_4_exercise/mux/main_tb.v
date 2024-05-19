module tb_mux4to1;

reg [1:0] sel;
reg [3:0] in;
wire out;

mux4to1 uut (
    .sel(sel),
    .in(in),
    .out(out)
);

initial begin
    sel = 2'b00; in = 4'b1010;
    #10 sel = 2'b01; in = 4'b1010;
    #10 sel = 2'b10; in = 4'b1010;
    #10 sel = 2'b11; in = 4'b1010;
    #10 $stop;
end

initial begin
    $monitor("Time = %0t: sel = %b, in = %b, out = %b", $time, sel, in, out);
end

endmodule
