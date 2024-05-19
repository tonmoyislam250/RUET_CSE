module testbench;
reg A;
reg B;
reg C;
reg D;
wire Z;
boolean_equation uut (
    .A(A),
    .B(B),
    .C(C),
    .D(D),
    .Z(Z)
);

initial begin
    A = 0;
    B = 0;
    C = 0;
    D = 0;
    #10 A = 0; B = 0; C = 0; D = 0;
    #10 A = 0; B = 0; C = 0; D = 1;
    #10 A = 0; B = 0; C = 1; D = 0;
    #10 A = 0; B = 0; C = 1; D = 1;
    #10 A = 0; B = 1; C = 0; D = 0;
    #10 A = 0; B = 1; C = 0; D = 1;
    #10 A = 0; B = 1; C = 1; D = 0;
    #10 A = 0; B = 1; C = 1; D = 1;
    #10 A = 1; B = 0; C = 0; D = 0;
    #10 A = 1; B = 0; C = 0; D = 1;
    #10 A = 1; B = 0; C = 1; D = 0;
    #10 A = 1; B = 0; C = 1; D = 1;
    #10 A = 1; B = 1; C = 0; D = 0;
    #10 A = 1; B = 1; C = 0; D = 1;
    #10 A = 1; B = 1; C = 1; D = 0;
    #10 A = 1; B = 1; C = 1; D = 1;
    #10 $stop;
end

initial begin
    $monitor("A=%b, B=%b, C=%b, D=%b, Z=%b", A, B, C, D, Z);
end

endmodule
