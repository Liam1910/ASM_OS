program_info:
    mov ah, 2
    mov dl, 11
    mov rsi, hwString
    .inner_loop:
        mov al, 2
        call [PRINT_STRING_ADDR]
        inc ah
        cmp rsi, hwStringEnd+1
        je .done
        jmp .inner_loop
    .done:
    ret


hwString db "Hello, World!"
hwStringEnd: db 0x0
