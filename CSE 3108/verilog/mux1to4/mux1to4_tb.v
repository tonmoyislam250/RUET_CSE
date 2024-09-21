`timescale 1ns/1ps
module mux1to4_tb;
reg [3:0] i;
reg [1:0] s;
wire y;

mux1to4 uut
(
    .i(i),
    .s(s),
    .y(y)
 );

 initial begin
    $dumpfile("mux1to4_tb.vcd");
    $dumpvars(0, mux1to4_tb);

    i = 4'b0001;
    s = 2'b00;
    #20;

    i = 4'b0010;
    s = 2'b01;
    #20;

    i = 4'b0100;
    s = 2'b10;
    #20;

    i = 4'b1000;
    s = 2'b11;
 end 
 initial begin
    $monitor("i = %b    |   s = %b  |   y = %b\n", i, s, y);
 end
endmodule