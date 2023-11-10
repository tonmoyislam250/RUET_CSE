.MODEL SMALL
.STACK 100H
.DATA
    CR   EQU 0DH
    LF   EQU 0AH
    MSG1 DB  'Enter 1st digit: $'
    MSG2 DB  0AH,'Enter 2nd digit: $'
    MSG3 DB  0DH,0AH,'Enter 3rd digit: $'
    MSG4 DB  0AH,'The largest digit is: $'

.CODE
MAIN PROC
                      MOV AX, @DATA
                      MOV DS, AX
    ; Show message 1 and input 1st digit
                      LEA DX, MSG1
                      MOV AH, 9
                      INT 21H
                      MOV AH, 1
                      INT 21H
                      MOV BL, AL
    ; Show message 2 and input 2nd digit
                      LEA DX, MSG2
                      MOV AH, 9
                      INT 21H
                      MOV AH, 1
                      INT 21H
                      MOV BH, AL
    ; Show message 3 and input 3rd digit
                      LEA DX, MSG3
                      MOV AH, 9
                      INT 21H
                      MOV AH, 1
                      INT 21H
                      MOV CL, AL
    ; Compare the digits
                      MOV AL, BL               ; Move 1st digit to AL
                      CMP BH, AL               ; Compare with 2nd digit
                      JG  check_3rd_largest
                      MOV AL, BH               ; Move 2nd digit to AL
                      CMP CL, AL               ; Compare with 3rd digit
    ;JG  print_largest
                    ; 1st digit is the largest
                      JMP print_1st
    check_3rd_largest:
                      CMP CL, BH               ; Compare 3rd digit with 2nd digit
                      JG  print_3rd_largest

                    ; 2nd digit is the largest
                      JMP print_2nd
    print_1st:        
                      MOV DL, CR
                      MOV AH, 2
                      INT 21H
                      MOV DL, LF
                      INT 21H

                      LEA DX, MSG4            ;print massage 4
                      MOV AH, 9
                      INT 21H

                      MOV AH, 2                ; Print function
                      MOV DL, BL
                      INT 21H
                      JMP done
    print_2nd:        
                      MOV DL, CR        
                      MOV AH, 2
                      INT 21H
                      MOV DL, LF
                      INT 21H

                      LEA DX, MSG4             ;print massage 4
                      MOV AH, 9
                      INT 21H

                      MOV AH, 2                ; Print function
                      MOV DL, BH
                      INT 21H
                      JMP done
    print_3rd_largest:
                      MOV DL, CR
                      MOV AH, 2
                      INT 21H
                      MOV DL, LF
                      INT 21H
                      
                      LEA DX, MSG4             ;print massage 4
                      MOV AH, 9
                      INT 21H

                      MOV AH, 2                ; Print function
                      MOV DL, CL
                      INT 21H
    done:             
                     ; Newline
                      MOV DL, CR
                      MOV AH, 2
                      INT 21H
                      MOV DL, LF
                      INT 21H
    ; Exit
                      MOV AH, 4CH
                      INT 21H

MAIN ENDP
END MAIN