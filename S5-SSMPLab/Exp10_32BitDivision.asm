DATA SEGMENT
        A       DD      00000009H
        B       DW      0003H
        Q       DW      ?
        R       DW      ?
DATA ENDS

CODE SEGMENT
        ASSUME CS:CODE, DS:DATA
        START:  MOV     AX,DATA
                MOV     DS,AX
                LEA     SI,A
                MOV     AX,[SI]
                MOV     DX,[SI+2]
                IDIV    B
        SKIP:   MOV     Q,AX
                MOV     R,DX
                INT     03H
CODE ENDS
END START
