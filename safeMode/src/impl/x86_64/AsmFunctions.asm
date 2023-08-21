global restart


section .text
bits 64


restart:
    mov rax, 0x1234
    mov rdi, 0x0
    xor rsi, rsi
    xor rdx, rdx
    mov eax, 0x0

    syscall