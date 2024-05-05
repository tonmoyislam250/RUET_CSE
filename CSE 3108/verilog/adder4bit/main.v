//4bit full adder
module main (
    input A0,
    input 
);
assign S = A ^ B ^ Cin;
assign Cout = (A & B) | (B & Cin) | (A & Cin);
    
endmodule