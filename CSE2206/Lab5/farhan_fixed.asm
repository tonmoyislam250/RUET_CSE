.model small
.stack 100h  
.data
    cr    equ 0dh
    lf    equ 0ah
    count dw  0
    m1    db  'Input binary number : $'
    m2    db  cr,lf,'Reverse binary number is : $'
    m3    db  cr,lf,'Count of zero is : $'

.code
main proc
               mov  ax, @data
               mov  ds, ax
    
               mov  ah, 9
               lea  dx, m1
               int  21h
    
               mov  bx, 0         ;clear bx
               mov  cx, 8
    again:     
               mov  ah, 1
               int  21h
               cmp  al, 13d
               je   end_again
               inc  count
               and  al, 0fh
               shl  bx, 1         ;rotate bx to left by 1 bit
               or   bl, al
               loop again
    end_again: 

               mov  cx, 8
    reverse:   
               shr  bl, 1         ;get a bit into cf
               rcl  al, 1         ;rotate it into bl
               loop reverse
               mov  bl, al
    
               mov  ah, 9
               lea  dx, m2
               int  21h
               mov  bh,bl
               mov  cx, count
    print:     
               rcl  bl, 1
               jc   level2        ; cf = 1 output = 1
               jmp  level1
    level1:    
               mov  ah, 2
               mov  dl, '0'
               int  21h
               jmp  continue
    level2:    
               mov  ah, 2
               mov  dl, '1'
               int  21h
               jmp  continue
    continue:  
               loop print
               mov  bl,bh






    ;            mov  ah, 9
    ;            lea  dx, m2
    ;            int  21h
    ;            mov  bh,bl
    ;            mov  cx, count
    ; print2:
    ;            rcl  bl, 1
    ;            jc   level3        ; cf = 1 output = 1
    ;            jmp  level4
    ; level3:
    ;            mov  ah, 2
    ;            mov  dl, '0'
    ;            int  21h
    ;            jmp  continue2
    ; level4:
    ;            mov  ah, 2
    ;            mov  dl, '1'
    ;            int  21h
    ;            jmp  continue2
    ; continue2:
    ;            loop print2
    ;            mov  bl,bh


               mov  ah, 9         ; msg for counting zero
               lea  dx, m3
               int  21h
               mov  al, 0
               mov  cx, count
    count_zero:
               rol  bl, 1
               jc   next
               inc  al
    next:      
               loop count_zero
       
               mov  ah, 2
               add  al,'0'
               mov  dl, al
               int  21h
       
    exit:      
               mov  ah, 4ch
               int  21h
main endp
end main