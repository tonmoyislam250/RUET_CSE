module testbench;

reg X;
reg Y;
wire Z;

boolean_equation uut (
    .X(X),
    .Y(Y),
    .Z(Z)
);

initial begin
    X = 0;
    Y = 0;
    #10 X = 0; Y = 0;
    #10 X = 0; Y = 1;
    #10 X = 1; Y = 0;
    #10 X = 1; Y = 1;
    #10 $stop;
end

initial begin
    $monitor("X=%b, Y=%b, Z=%b", X, Y, Z);
end

endmodule
