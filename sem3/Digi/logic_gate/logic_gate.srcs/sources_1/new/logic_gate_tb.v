module RegisterFile_tb;
    reg [5:0] Read1, Read2, WriteReg;
    reg [31:0] WriteData;
    reg RegWrite, clk;
    wire [31:0] Data1, Data2;

    // Instantiate the RegisterFile module
    RegisterFile uut (
        .Read1(Read1),
        .Read2(Read2),
        .WriteReg(WriteReg),
        .WriteData(WriteData),
        .RegWrite(RegWrite),
        .clk(clk),
        .Data1(Data1),
        .Data2(Data2)
    );

    // Clock generation
    always #5 clk = ~clk;

    // Task to display all register values
    task display_registers;
        integer i;
        begin
            $display("Time: %0t | Register File Contents:", $time);
            for (i = 0; i < 8; i = i + 1) begin
                $display("RF[%0d] = %d", i, uut.RF[i]);
            end
            $display("-------------------------------");
        end
    endtask

    initial begin
        // Enable waveform dump
        $dumpfile("RegisterFile_tb.vcd");
        $dumpvars(0, RegisterFile_tb);

        // Initialize signals
        clk = 0;
        RegWrite = 0;
        Read1 = 6'd0;
        Read2 = 6'd1;
        WriteReg = 6'd0;
        WriteData = 32'd0;

        // Scenario 1: Read data when no write occurs
        #10;
        display_registers(); // Display current register contents
        $display("space");

        // Scenario 2: Perform a write operation with RegWrite enabled
        WriteReg = 6'd2;
        WriteData = 32'd42;
        RegWrite = 1;
        #10; // Wait for clock edge
        RegWrite = 0;
        display_registers(); // Display updated register contents
        $display("space");

        // Scenario 3: Ensure no write occurs when RegWrite is disabled
        WriteReg = 6'd3;
        WriteData = 32'd100;
        #10;
        display_registers(); // Confirm no changes
        $display("space");

        // Scenario 4: Verify RF[0] cannot be modified
        WriteReg = 6'd0;
        WriteData = 32'd1234;
        RegWrite = 1;
        #10; // Wait for clock edge
        RegWrite = 0;
        display_registers(); // Ensure RF[0] remains 0
        $display("space");

        $stop;
    end
endmodule

