module reg_16bit (
    input wire [15:0] data_in,
    input wire clk,
    input wire reset,
    output reg [15:0] data_out
);

always @(posedge clk or posedge reset)
begin
    if (reset)
        data_out <= 0;
    else
        data_out <= data_in;
end

endmodule
