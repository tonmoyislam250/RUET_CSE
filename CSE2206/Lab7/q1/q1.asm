.MODEL SMALL
.STACK 100H
.DATA
    STRING1 DB "Hello World$"
    STRING2 DB 20 DUP(?)
    MSG     DB 13,10,"NUMBER OF VOWELS: $"
.CODE
MAIN PROC
                 MOV  AX, @DATA
                 MOV  DS, AX
                 LEA  SI, STRING1
                 MOV  CX, 0
                 MOV  BL, 0

    LEG:         
                 MOV  AL,[SI]
                 CMP  AL, '$'
                 JE   INIT_REV
                 INC  SI
                 INC  CX
                 CMP  AL, 'a'
                 JE   IS_VOWEL
                 CMP  AL, 'e'
                 JE   IS_VOWEL
                 CMP  AL, 'i'
                 JE   IS_VOWEL
                 CMP  AL, 'o'
                 JE   IS_VOWEL
                 CMP  AL, 'u'
                 JE   IS_VOWEL
                 CMP  AL, 'A'
                 JE   IS_VOWEL
                 CMP  AL, 'E'
                 JE   IS_VOWEL
                 CMP  AL, 'I'
                 JE   IS_VOWEL
                 CMP  AL, 'O'
                 JE   IS_VOWEL
                 CMP  AL, 'U'
                 JE   IS_VOWEL

    NOT_VOWEL:   
                 JMP  LEG_CONTINUE

    IS_VOWEL:    
                 INC  BX

    LEG_CONTINUE:
                 JMP  LEG

    INIT_REV:    
                 MOV  DI, OFFSET STRING2
    REVERSE:     
                 DEC  SI
                 MOV  AL, [SI]
                 MOV  [DI], AL
                 INC  DI
                 LOOP REVERSE

                 MOV  BYTE PTR [DI], '$'
                 MOV  AH, 09H
                 LEA  DX, STRING2
                 INT  21H
                 LEA  DX, MSG
                 INT  21H
                 
                 MOV  AH, 02H
                 MOV  DL, BL
                 ADD  DL, '0'
                 INT  21H

                 MOV  AH, 4CH
                 INT  21H
MAIN ENDP
END MAIN
