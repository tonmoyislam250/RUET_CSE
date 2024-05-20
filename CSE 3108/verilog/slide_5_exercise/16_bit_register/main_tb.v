module Register16_tb;

    reg [15:0] in_data;
    reg clk;
    reg reset;
    wire [15:0] out_data;

    Register16 uut (
        .in_data(in_data),
        .clk(clk),
        .reset(reset),
        .out_data(out_data)
    );

    initial begin
        clk = 0;
        reset = 1;
        in_data = 16'h1234;
        
        #10 reset = 0; // De-assert reset
        #10 in_data = 16'hABCD; // Input new data
        #100 $finish; // End simulation
    end

    always #5 clk = ~clk; // Clock toggles every 5 time units

endmodule
