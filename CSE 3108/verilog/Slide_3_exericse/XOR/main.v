module boolean_equation (
    input wire X,
    input wire Y,
    output wire Z
);

assign Z = (X & Y) | (~X & ~Y);

endmodule
