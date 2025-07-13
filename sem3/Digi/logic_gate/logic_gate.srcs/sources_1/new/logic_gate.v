module RegisterFile(
    input wire [5:0] Read1, Read2, WriteReg,
    input wire [31:0] WriteData,
    input wire RegWrite, clk,
    output wire [31:0] Data1, Data2
);
    reg [31:0] RF [63:0]; // 64 registers, each 32-bit wide

    // Ensure Register 0 always outputs 0
    initial begin
        RF[0] = 32'd0;
        RF[2] = 32'd6;
        RF[3] = 32'd9;
    end

    // Assign output values
    assign Data1 = RF[Read1];
    assign Data2 = RF[Read2];

    // Write operation
    always @(posedge clk) begin
        if (RegWrite && WriteReg != 6'd0) begin
            RF[WriteReg] <= WriteData;
        end
    end
endmodule

