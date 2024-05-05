module adder1bit_tb;

reg A, B, Cin;
wire S, Cout;
main uut (
    .A(A),
    .B(B),
    .Cin(Cin),
    .S(S),
    .Cout(Cout)
);
initial begin
    $monitor("Time=%0t, A=%b, B=%b, Cin=%b, S=%b, Cout=%b", $time, A, B, Cin, S, Cout);
    $dumpfile("adder1bit_tb.vcd");
    $dumpvars(0, adder1bit_tb);
    #10 A = 0; B = 0; Cin = 0;
    #10 A = 0; B = 0; Cin = 1;
    #10 A = 0; B = 1; Cin = 0;
    #10 A = 0; B = 1; Cin = 1;
    #10 A = 1; B = 0; Cin = 0;
    #10 A = 1; B = 0; Cin = 1;
    #10 A = 1; B = 1; Cin = 0;
    #10 A = 1; B = 1; Cin = 1;
    #10 $finish;
end

endmodule
