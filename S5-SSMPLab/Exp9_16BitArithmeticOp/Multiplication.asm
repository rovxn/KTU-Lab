DATA SEGMENT
        A       DW      3456H
        B       DW      1234H
        H       DW      ?
        L       DW      ?
        MULTI   DD      ?
DATA    ENDS
CODE    SEGMENT
        ASSUME  CS:CODE,DS:DATA
        START:
                MOV AX,DATA
                MOV DS,AX
                MOV AX,A
                MOV BX,B
                MUL BX
                MOV H,DX
                MOV L,AX
        SKIP:
                MOV MULTI,AX
                INT 03H
CODE ENDS
END START
