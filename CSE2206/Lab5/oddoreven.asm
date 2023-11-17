.MODEL SMALL
.STACK 100H
.DATA
    MSG1 DB "ENTER THE NUMBER = $"
    MSG2 DB 10D,13D,"THE NUMBER IS ODD.$"
    MSG3 DB 10D,13D,"THE NUMBER IS EVEN.$"
.CODE
MAIN PROC
              MOV  AX,@DATA
              MOV  DS,AX
              MOV  AH,9
              LEA  DX,MSG1
              INT  21h
              MOV  BX,0
              MOV  AH,1
    WHILE_:   
              INT  21H
              CMP  AL,13D
              JE   END_WHILE
              AND  AL,15D
              SHL  BX,1
              OR   BL,AL
              JMP  WHILE_
    END_WHILE:
              TEST BX,1b
              JZ   EVE
              JMP  ODD
    ODD:      
              MOV  AH,9
              LEA  DX,MSG2
              INT  21h
              JMP  QUIT
    EVE:      
              MOV  AH,9
              LEA  DX,MSG3
              INT  21h
              JMP  QUIT
    QUIT:     
              MOV  AH, 4CH
              INT  21H
MAIN ENDP
END MAIN