module and_gate_tb;
reg a, b;
wire out;

main uut (
    .a(a),
    .b(b),
    .out(out)
);

initial begin
    $monitor("Time=%0t, a=%b, b=%b, out=%b", $time, a, b, out);
    $dumpfile("and_gate_tb.vcd");
    $dumpvars(0, and_gate_tb);
    #10 a = 0; b = 0;
    #10 a = 0; b = 1;
    #10 a = 1; b = 1;
    #10 $finish;
end

endmodule
