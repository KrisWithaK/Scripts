;
; The code given to you here implements the histogram calculation that
; we developed in class.  In programming lab, we will add code that
; prints a number in hexadecimal to the monitor.
;
; Your assignment for this program is to combine these two pieces of
; code to print the histogram to the monitor.
;
; If you finish your program,
;    ** commit a working version to your repository  **
;    ** (and make a note of the repository version)! **


	.ORIG	x3000		; starting address is x3000


;
; Count the occurrences of each letter (A to Z) in an ASCII string
; terminated by a NUL character.  Lower case and upper case should
; be counted together, and a count also kept of all non-alphabetic
; characters (not counting the terminal NUL).
;
; The string starts at x4000.
;
; The resulting histogram (which will NOT be initialized in advance)
; should be stored starting at x3F00, with the non-alphabetic count
; at x3F00, and the count for each letter in x3F01 (A) through x3F1A (Z).
;
; table of register use in this part of the code
;    R0 holds a pointer to the histogram (x3F00)
;    R1 holds a pointer to the current position in the string
;       and as the loop count during histogram initialization
;    R2 holds the current character being counted
;       and is also used to point to the histogram entry
;    R3 holds the additive inverse of ASCII '@' (xFFC0)
;    R4 holds the difference between ASCII '@' and 'Z' (xFFE6)
;    R5 holds the difference between ASCII '@' and '`' (xFFE0)
;    R6 is used as a temporary register
;

        LD          R0,HIST_ADDR      	; point R0 to the start of the histogram

	; fill the histogram with zeroes
        AND         R6,R6,#0		; put a zero into R6
        LD          R1,NUM_BINS		; initialize loop count to 27
        ADD         R2,R0,#0		; copy start of histogram into R2

	; loop to fill histogram starts here
HFLOOP
        STR         R6,R2,#0		; write a zero into histogram
        ADD         R2,R2,#1		; point to next histogram entry
        ADD         R1,R1,#-1		; decrement loop count
        BRp         HFLOOP		; continue until loop count reaches zero

	; initialize R1, R3, R4, and R5 from memory
        LD          R3,NEG_AT		; set R3 to additive inverse of ASCII '@'
        LD          R4,AT_MIN_Z		; set R4 to difference between ASCII '@' and 'Z'
        LD          R5,AT_MIN_BQ		; set R5 to difference between ASCII '@' and '`'
        LD          R1,STR_START		; point R1 to start of string

	; the counting loop starts here
COUNTLOOP
        LDR         R2,R1,#0		; read the next character from the string
        BRz         PRINT_HIST		; found the end of the string

        ADD         R2,R2,R3		; subtract '@' from the character
        BRp         AT_LEAST_A		; branch if > '@', i.e., >= 'A'
NON_ALPHA
        LDR         R6,R0,#0		; load the non-alpha count
        ADD         R6,R6,#1		; add one to it
        STR         R6,R0,#0		; store the new non-alpha count
        BRnzp       GET_NEXT		; branch to end of conditional structure
AT_LEAST_A
        ADD         R6,R2,R4		; compare with 'Z'
        BRp         MORE_THAN_Z         ; branch if > 'Z'

; note that we no longer need the current character
; so we can reuse R2 for the pointer to the correct
; histogram entry for incrementing
ALPHA
        ADD         R2,R2,R0		; point to correct histogram entry
        LDR         R6,R2,#0		; load the count
        ADD         R6,R6,#1		; add one to it
        STR         R6,R2,#0		; store the new count
        BRnzp       GET_NEXT		; branch to end of conditional structure

; subtracting as below yields the original character minus '`'
MORE_THAN_Z
        ADD         R2,R2,R5		; subtract '`' - '@' from the character
        BRnz        NON_ALPHA		; if <= '`', i.e., < 'a', go increment non-alpha
        ADD         R6,R2,R4		; compare with 'z'
        BRnz        ALPHA		; if <= 'z', go increment alpha count
        BRnzp       NON_ALPHA		; otherwise, go increment non-alpha

GET_NEXT
        ADD         R1,R1,#1		; point to next character in string
        BRnzp       COUNTLOOP		; go to start of counting loop



PRINT_HIST

; you will need to insert your code to print the histogram here

; do not forget to write a brief description of the approach/algorithm
; for your implementation, list registers used in this part of the code,
; and provide sufficient comments




          LD        R1,ASCII_SRT      ; R1<--x0040, ascii code for '@'
          LD        R3,HIST_ADDR      ; R3<--x3F00, pointer for histogram

ISLESS
          ADD       R0,R3,NULL_TERM   ; R0<--R3-xC0E6, to see if we finished
          BRp       DONE

          LDI       R0,R3,#0
          OUT
          LD        R0,SPACE
          OUT




; print_hex.asm
; Prints out a hexadecimal number store in register R3 to the console.
; The hexadecimal number has to be converted to an appropriate ASCII
; character in order for the number to be displayed correctly.

; Inputs:
;   R3 - hexadecimal number
;   R0 - Holder for each set of 4 bits from the Hex number
;   R4 - counter to iterate though all sets of 4 bits
;   R2 - counter to iterate though the 4 bits in each set
;   R5 - holds the offset from memory

; Outputs:
;   [0 - F]{4} printed to console



MAIN

          AND	      R2,R2,#0	       ; R2 <-- #0, Clears R2
          ADD	      R4,R2,#4	       ; R4 <-- #4, initializes outer counter
OUTER	    ADD	      R0,R2,#0	       ; R0 <-- #0, clears R0, sets beginning of outer loop
          ADD	      R2,R2,#4	       ; R2 <-- #4, initializes inner counter

INNER	    ADD	      R0,R0,R0	       ; R0 <-- R0 + R0, shift bits left
          ADD	      R3,R3,#0	       ; R3 <-- R3, finds the nzp value of R3, sets beginning of inner loop
          BRzp	    POS		           ; if R3 is negative, set LSB to '1' in R0, if not, keep the LSB a '0'
          ADD	      R0,R0,#1	       ; R0 <-- R0 + #1
POS	      ADD	      R3,R3,R3	       ; R3 <-- R3 + R3, Shift bits left
          ADD	      R2,R2,#-1	       ; R2 <-- R2 + #-1, decrement inner counter
          BRp	      INNER		         ; If R2 is positive, loop to INNER

          ADD	      R6,R0,#-9	       ; Subtracts 9 to see if R0 is greater or less than 9
          BRp	      LETTERS
          LD	      R5,ASCII_NUM	   ; loads R5 with ascii offset for numbers
          ADD	      R0,R0,R5	       ; adds the number offset to get to the ascii character
          BRnzp	    NUMBERS		       ; Skips adding the letters offset
LETTERS	  LD	      R5, ASCII_LET	   ; loads R5 with ascii offset for letters
          ADD	      R0,R0,R5	       ; adds the letters offset to get to the ascii character

NUMBERS	  OUT			                   ; if R2 is not positive, print R0
          ADD	      R4,R4,#-1	       ; Decrement outer counter
          BRp	      OUTER		         ; if outer counter is positive, loop to OUTER








          LD        R0,NEW_LINE
          OUT
          ADD       R1,R1,#1
          ADD       R3,R3,#1
          BRnzp     ISLESS













DONE
        HALT			; done


; the data needed by the program
NUM_BINS	.FILL #27	; 27 loop iterations
NEG_AT		.FILL xFFC0	; the additive inverse of ASCII '@'
AT_MIN_Z	.FILL xFFE6	; the difference between ASCII '@' and 'Z'
AT_MIN_BQ	.FILL xFFE0	; the difference between ASCII '@' and '`'
HIST_ADDR	.FILL x3F00     ; histogram starting address
STR_START	.FILL x4000	; string starting address
ASCII_SRT .FILL x0040 ; ASCII code for '@'
NULL_TERM .FILL xC0E6 ; 2's Compliment of 3F1B, the memory location after histogram
SPACE     .FILL x0020 ; ASCII code for space
NEW_LINE  .FILL x000A ; ASCII code for newline

; for testing, you can use the lines below to include the string in this
; program...
; STR_START	.FILL STRING	; string starting address
; STRING		.STRINGZ "This is a test of the counting frequency code.  AbCd...WxYz."



	; the directive below tells the assembler that the program is done
	; (so do not write any code below it!)

	.END
