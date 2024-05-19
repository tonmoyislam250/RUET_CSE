module tb_demux1to4;

reg in;
reg [1:0] sel;
wire [3:0] out;

demux1to4 uut (
    .in(in),
    .sel(sel),
    .out(out)
);

initial begin
    in = 1;
    sel = 2'b00;
    #10 sel = 2'b01;
    #10 sel = 2'b02;
    #10 sel = 2'b11;
    #10 $stop;
end

initial begin
    $monitor("Time = %0t: in = %b, sel = %b, out = %b", $time, in, sel, out);
end

endmodule
