module reg_16bit_tb;

reg [15:0] data_in;
reg clk;
reg reset;
wire [15:0] data_out;
reg [15:0] expected_output;
reg done;
reg [3:0] clk_divider;

initial begin
    $dumpfile("main_tb.vcd");
    $dumpvars(0, reg_16bit_tb);
    
    data_in = 16'hABCDE;
    clk = 0;
    reset = 1;
    expected_output = 16'h0000;
    done = 0;
    clk_divider = 4'b0000;
    #20 reset = 0;
end

always #5 clk = ~clk;

always @(posedge clk) begin
    if (!done) begin
        if (clk_divider == 4'b0000) begin
            clk_divider <= 4'b1111;
            data_in <= data_in + 1;
        end else begin
            clk_divider <= clk_divider - 1;
        end
    end
end

reg_16bit UUT (
    .data_in(data_in),
    .clk(clk),
    .reset(reset),
    .data_out(data_out)
);

always @(posedge clk) begin
    if (data_out !== expected_output) begin
        $display("Error: Expected output %h, got %h", expected_output, data_out);
        $finish;
    end else if (data_out === 16'hFFFF && !done) begin
        $display("Test passed.");
        done = 1;
        $finish;
    end
end

endmodule
