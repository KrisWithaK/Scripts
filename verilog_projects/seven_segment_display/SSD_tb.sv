`timescale 10ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 06/04/2020 08:54:59 PM
// Design Name: 
// Module Name: SSD_tb
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


module SSD_tb;

logic clk;
logic btn0, btn1;
logic [6:0] ck_io;
integer i;
integer j;

Seven_Seg_Display SevSegDis(.clk(clk), .btn0(btn0), .btn1(btn1), .ck_io(ck_io));


initial begin
    
    btn0 = 0;
    btn1 = 0;
    clk = 0;

    for(i = 0; i < 25; i++) begin
        #10 btn0 = ~btn0;
    end

    #10 btn1 = 1;

    for(j = 0; j < 10; j++) begin
        #1 clk = ~clk;
    end

    #10 btn1 = 0;

    for(j = 0; j < 10; j++) begin
        #1 clk = ~clk;
    end


end


initial begin

    for(j = 0; j < 900; j++) begin
        #1 clk = ~clk;
    end


end

endmodule
