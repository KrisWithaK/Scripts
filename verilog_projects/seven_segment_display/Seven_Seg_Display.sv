`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 06/04/2020 06:31:17 PM
// Design Name: 
// Module Name: Seven_Seg_Display
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
//
//          LED Layout
//
//             ck_io[6]
//    ck_io[5]          ck_io[4]
//             ck_io[3]
//    ck_io[1]          ck_io[2]        
//             ck_io[0]
//
//////////////////////////////////////////////////////////////////////////////////


module Seven_Seg_Display(
    input clk,
    input btn0, btn1,
    output [6:0] ck_io
    );

    enum {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE} 
            cur_state, nex_state;

    logic [6:0] leds;
    logic increment, reset, increment_down; // increment means btn0 is being pressed
                                            // reset means btn1 is being pressed
                                            // increment_down means btn0 is being held down (for more than 1 clock cycle)
    assign ck_io = leds;
    assign increment = btn0;
    assign reset = btn1;

    // sequential
    always_ff @( posedge clk ) begin
        
        if(reset) // if reset, then we default to state ZERO
            cur_state <= ZERO;
        else if(increment & ~increment_down) // else, if btn0 is pressed down for the first time, change state
            cur_state <= nex_state;
        else
            cur_state <= cur_state; // otherwise keep the state the same

        if(increment) // if the increment is being held down, increment_down is 1
            increment_down <= 1;
        else if(~increment) // if the increment is not being help, increment_down is 0
            increment_down <= 0;
        else
            increment_down <= increment_down; // otherwise increment_down stays the same
    end

    // combinational
    always_comb begin
        // moore state machine
        case (cur_state) 
            ZERO: begin 
                nex_state = ONE;
                leds = 7'b1110111; // hex = 77
            end
            ONE: begin 
                nex_state = TWO;
                leds = 7'b0010100; // hex = 14
            end
            TWO: begin 
                nex_state = THREE;
                leds = 7'b1011011; // hex = 5b
            end
            THREE: begin 
                nex_state = FOUR;
                leds = 7'b1011101; // hex = 5d
            end
            FOUR: begin 
                nex_state = FIVE;
                leds = 7'b0111100; // hex = 3c
            end
            FIVE: begin 
                nex_state = SIX;
                leds = 7'b1101101; // hex = 6d
            end
            SIX: begin 
                nex_state = SEVEN;
                leds = 7'b0101111; // hex = 2f
            end
            SEVEN: begin 
                nex_state = EIGHT;
                leds = 7'b1010100; // hex = 54
            end
            EIGHT: begin 
                nex_state = NINE;
                leds = 7'b1111111; // hex = 7f
            end
            NINE: begin 
                nex_state = ZERO;
                leds = 7'b1111100; // hex = 7c
            end
            
            default: begin
                nex_state = ZERO;
                leds = 7'b0001000; // hex = 08
            end
        endcase
    end





    








endmodule
