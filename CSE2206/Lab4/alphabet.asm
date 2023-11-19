.MODEL SMALL
.STACK 100H
.CODE
MAIN PROC
                MOV AH,2
                MOV DL,'?'
                INT 21H            ;display ‘?’
                MOV AH,1
                INT 21H            ; read 1st char. & put it in BL
                MOV BL,AL
                INT 21H
                MOV CL,AL          ;read 2nd char. in AL
                CMP BL,CL
                JG  SWITCH         ;if not orderd
                JMP CONTINUE
       SWITCH:  
                MOV BH,BL
                MOV BL,CL
                MOV CL,BH
       CONTINUE:
                MOV AH,2
                MOV DL, 0AH        ;enter
                INT 21H
                MOV DL,BL
                ADD DL,20H
                INT 21H
                MOV DL,CL
                ADD DL,20H
                INT 21H
                MOV AH,4CH
                INT 21H
MAIN ENDP
END MAIN