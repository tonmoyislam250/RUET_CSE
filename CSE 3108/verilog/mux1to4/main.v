module mux1to4(
    input [3:0] i,
    input [1:0] s,
    output reg y
);
//assign y = ((~s[1]) & (~s[0]) & i[0]) | ((~s[1]) & (s[0]) & i[1]) | ((s[1]) & (~s[0]) & i[2]) | ((s[1]) & (s[0]) & i[3]);

always@(*)
    begin
        if(s == 2'b00)   y = i[0];
        else if(s == 2'b01)   y = i[1];
        else if(s == 2'b10)   y = i[2];
        else   y = i[3];
    end
endmodule