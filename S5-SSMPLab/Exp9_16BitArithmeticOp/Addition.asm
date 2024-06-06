DATA SEGMENT
A       DW      1234H
B       DW      6A12H
SUM     DW      ?
CARRY   DB      00H
DATA ENDS

CODE SEGMENT
ASSUME  CS:CODE, DS:DATA

START:  MOV     AX,DATA
        MOV     DS,AX
        MOV     AX,A
        MOV     BX,B
        ADD     AX,BX
        INC     SKIP
        INC     CARRY
SKIP:   MOV     SUM,AX
        INT     03H
        CODE ENDS
        END START
