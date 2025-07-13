`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 21.10.2024 15:54:08
// Design Name: 
// Module Name: logic_gate_tb
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module logic_gate_or_tb();
reg a,b;
wire y;
logic_gate_or h (a,b,y);
initial begin
a=1'd0;b=1'd0;
#10;
a=1'd0;b=1'd1;
#10;
a=1'd1;b=1'd0;
#10;
a=1'd1;b=1'd1;
#10;

$stop;
end
endmodule
