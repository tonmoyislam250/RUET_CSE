.MODEL SMALL
.STACK 100H
.DATA
    A    DW 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
.CODE
MAIN PROC
              MOV  AX, @DATA
              MOV  DS, AX
              LEA  SI, A
              MOV  BX , 10
              CALL REVERSE
              MOV  AH,4CH
              INT  21H
MAIN ENDP
REVERSE PROC
    ;reverses a word array
    ;input: SI - offset of array
    ;       BX - number of elements
    ;output: reversed array

              PUSH AX           ;save registers
              PUSH BX
              PUSH CX
              PUSH SI
              PUSH DI
              MOV  DI, SI
              MOV  CX, BX
              DEC  BX
              SHL  BX, 1        ; BX * 2
              ADD  DI, BX
              SHR  CX, 1        ; CX / 2 (since we're swapping pairs of elements)

    XCHG_LOOP:
              MOV  AX, [SI]     ; load element at SI
              XCHG AX, [DI]     ; exchange with element at DI
              MOV  [SI], AX     ; store the original DI element at SI
              ADD  SI, 2        ; move SI to the next element
              SUB  DI, 2        ; move DI to the previous element
              LOOP XCHG_LOOP    ; repeat until CX becomes zero

              POP  DI           ;restore registers
              POP  SI
              POP  CX
              POP  BX
              POP  AX
              RET

REVERSE ENDP

END MAIN
```
