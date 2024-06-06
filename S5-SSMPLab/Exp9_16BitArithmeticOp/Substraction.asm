DATA SEGMENT
        A       DW      974BH
        B       DW      587CH
        DIFF    DB      ?
        BORR    DB      00H
DATA ENDS

CODE SEGMENT
        ASSUME CS:CODE, DS:DATA
        START:
                MOV     AX,DATA
                MOV     DS,AX
                MOV     AX,A
                MOV     BX,B
                SUB     AX,BX
                JNC     SKIP
                INC     BORR
        SKIP:   MOV     DIFF,AX
                INT     03H
CODE ENDS
END START
