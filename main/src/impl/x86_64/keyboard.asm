global keyboard32
global keyboard64

section .text
bits 32

keyboard32:
    xor eax, eax
    int 0x16
    cmp ah, 0x01
    jz exit32

    ; Other key detecting code

    jmp keyboard32

exit32:
    ret


bits 64

keyboard64:
    xor eax, eax
    mov ah, 0x10
    int 0x16
    cmp ah, 0x01
    jz exit64

    ; Other key detecting code

    jmp keyboard64

exit64:
    ret