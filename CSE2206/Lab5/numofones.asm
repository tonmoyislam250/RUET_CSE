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
               LEA  DX,MSG1
               MOV  AH,9
               INT  21H
               MOV  BX,0
               MOV  AH,1
               INT  21H
    ENTER_BIN: 
               CMP  AL, 20H
               JE   END_BIN
               AND  AL, 0FH
               SHL  BX,1
               OR   BL,AL
               INT  21H
               INC  COUNT
               JMP  ENTER_BIN
    END_BIN:   

               MOV  AH,9
               LEA  DX,MSG2
               INT  21H

               MOV  CX,17
               MOV  AH,2
    ROLOOP:    
               RCL  BX,1
               JC   PRINT_ONE
               JNC  PRINT_ZERO
    PRINT_ONE: 
               MOV  DL,'1'
               INT  21H
               JMP  CONTINUE
    PRINT_ZERO:
               MOV  DL,'0'
               INT  21H
               JMP  CONTINUE
    CONTINUE:  
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