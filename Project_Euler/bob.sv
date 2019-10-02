module trafficlight 
  (input reset,
   input clk, 
   output R,
   output Y, 
   output G
  );
  
  enum [2:0] logic {RED, YELLOW, GREEN} colorstate; //enumerated datatypes in SystemVerilog are often used for 
  											   //state machines 
   

  colorstate currcol, colnext;
  int count, countnext;

  always_ff(@posedge clk)begin
    count <= countnext;  
    currcol <= colnext;
  end 
  
  always_comb begin
	//default values 
    R=0;
    Y=0;
    G=0;
    if (reset)begin
      countnext = 0;
      colnext = RED; 
    end 
    
    countnext=count+1;
    colnext=currcol; 



    //MEALY MACHINE 
    case (currcol)
    RED:begin
      R=1; 
      if (currcount == 63)begin 
        countnext=0;
      	colnext= GREEN;
      end 
    end
	YELLOW:begin
      Y=1; 
      if (currcount == 15)begin 
        countnext=0;
      	colnext= RED;
      end 
    end
    GREEN:begin
      G=1; 
      if (currcount == 63)begin 
        countnext=0;
      	colnext= YELLOW;
      end       
    end
      
    endcase 
  
  end

endmodule



module mod1(
input A1, B1, A2, A3, B1, B2, B3,
input clk, 
output C1, C2, C3, Q, QNOT
);

logic Quu;// Qnext;

always_ff @( posedge clock ) begin 
Q <= A3;
QNOT <= ~A3;

end

always_comb begin
C1= A1 & B1;
C2 = A2 | B2;
C3 = ~B3;
    
end


endmodule