module boolean_equation (
    input wire A,
    input wire B,
    input wire C,
    input wire D,
    output wire Z
);

assign Z = (A & C) | (B & D);

endmodule