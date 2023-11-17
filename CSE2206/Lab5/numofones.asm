.MODEL SMALL
.STACK 100H
.DATA
    MSG1  DB "ENTER THE NUMBER = $"
    MSG2  DB 10D,13D,"THE NUMBER IS = $"
    MSG3  DB 10D,13D,"THE NUMBER OF 1's IS = $"
    COUNT DB 0
.CODE
MAIN PROC
              MOV  AX,@DATA
              MOV  DS,AX
              MOV  BX,0
              MOV  AH,1
    WHILE_:   
              INT  21H
              CMP  AL,13D
              JE   END_WHILE
              AND  AL,15D
              SHL  BX,1
              OR   BL,AL
              INC  COUNT
              JMP  WHILE_
    END_WHILE:
              MOV  AH,9
              LEA  DX,MSG2
              INT  21h

              MOV  CX,16
              MOV  AH,2
    ROLOOP:   
              RCL  BX,1
              JC   PRINT_ONE
              MOV  DL,'0'
              INT  21H
              JMP  CONT
    PRINT_ONE:
              MOV  AH, 2
              MOV  DL,'1'
              INT  21H
    CONT:     
              LOOP ROLOOP
              
              MOV  AH,9
              LEA  DX,MSG3
              INT  21H
              
              XOR  AX,AX
              MOV  CX,16
    TOP:      
              ROL  BX,1
              JNC  NEXT
              INC  AX
    NEXT:     
              LOOP TOP

              MOV  AH, 2
              MOV  DL, AL
              ADD  DL,'0'
              INT  21H
              MOV  AH, 4CH
              INT  21H
MAIN ENDP
END MAIN