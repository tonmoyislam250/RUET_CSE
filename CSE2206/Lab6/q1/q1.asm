.MODEL SMALL
.STACK 100H
.DATA
    isPrime  DB 'Prime$'
    notPrime DB 'Not Prime$'
.CODE
INDEC PROC
                PUSH BX
                PUSH CX
                PUSH DX
@BEGIN:
                MOV  AH, 2
                MOV  DL, '?'
                INT  21h
                XOR  BX, BX
                XOR  CX, CX
                MOV  AH, 1
                INT  21h
                CMP  AL, '-'
                JE   @MINUS
                CMP  AL, '+'
                JE   @PLUS
                JMP  @REPEAT2
@MINUS:
                MOV  CX, 1
@PLUS:
                INT  21h
@REPEAT2:
                CMP  AL, '0'
                JNGE @NOT_DIGIT
                CMP  AL, '9'
                JNLE @NOT_DIGIT
                AND  AX, 000FH
                PUSH AX
                MOV  AX, 10
                MUL  BX
                POP  BX
                ADD  BX, AX
                MOV  AH, 1
                INT  21h
                CMP  AL, 0DH
                JNE  @REPEAT2
                MOV  AX, BX
                OR   CX, CX
                JE   @EXIT
                NEG  AX
@EXIT:
                POP  DX
                POP  CX
                POP  BX
                RET
@NOT_DIGIT:
                MOV  AH, 2
                MOV  DL, 0DH
                INT  21h
                MOV  DL, 0AH
                INT  21h
                JMP  @BEGIN
INDEC ENDP

CHECK_PRIME PROC
                MOV  CX, 2
                MOV  DX, 0
                CMP  AX, 1
                JE   @NOT_PRIME
@CHECK_DIVISOR:
                MOV  BX, AX
                DIV  CX
                CMP  DX, 0
                JE   @NOT_PRIME
                INC  CX
                MOV  AX, BX
                CMP  CX, AX
                JG   @IS_PRIME
                JMP  @CHECK_DIVISOR
@IS_PRIME:
                MOV  AH, 9
                LEA  DX, isPrime
                INT  21h
                JMP  @EXIT2
@NOT_PRIME:
                MOV  AH, 9
                LEA  DX, notPrime
                INT  21h
@EXIT2:
                RET
CHECK_PRIME ENDP


MAIN PROC
                MOV  AX, @DATA
                MOV  DS, AX
                CALL INDEC
                CALL CHECK_PRIME
                MOV  AH, 4CH
                INT  21H
MAIN ENDP
END MAIN
