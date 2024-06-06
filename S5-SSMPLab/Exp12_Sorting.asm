DATA SEGMENT
        A       DW      0004H,0009H,0001H,0003H,0002H
DATA ENDS

CODE SEGMENT
        ASSUME CS:CODE, DS:DATA
        START:
                MOV AX, DATA
                MOV DS, AX
                MOV SI, 0000H
                MOV BX, A[SI]
                DEC BX
        X2:
                MOV CX, BX
                MOV SI,02H
        X1:
                MOV AX,A[SI]
                INC SI
                INC SI
                CMP AX, A[SI]
                JA X3
                XCHG AX, A[SI]
                MOV A[SI-2], AX
        X3:
                LOOP X1
                DEC BX
                JNZ X2
		MOV AX,4CH
                INT 21H

CODE ENDS
END START