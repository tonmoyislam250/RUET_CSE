module d_flip_flop_tb;

parameter CLK_PERIOD = 10;
parameter SIM_TIME = 100;

reg clk;
reg d;
wire q;

d_flip_flop DUT (
    .clk(clk),
    .d(d),
    .q(q)
);

always #((CLK_PERIOD / 2)) clk = ~clk;

initial begin
    clk = 0;
    d = 0;
    
    #5 d = 1;
    #10 d = 0;
    #10 $finish;
end

always @(posedge clk) begin
    $display("At time %t, q = %b", $time, q);
end

endmodule