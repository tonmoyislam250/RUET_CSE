module Register16(
    input wire [15:0] in_data,
    input wire clk,
    input wire reset,
    output reg [15:0] out_data
);

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            out_data <= 16'h0000;
        end
        else begin
            out_data <= in_data;
        end
    end

endmodule
