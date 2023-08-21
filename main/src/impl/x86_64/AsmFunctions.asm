global restart
global loadKernel

section .data
    kernelPath db "/boot/kernel/testmode.bin"
    kernelAdress equ 0x1912

section .text
bits 64


restart:
    mov rax, 0x1234
    mov rdi, 0x0
    xor rsi, rsi
    xor rdx, rdx
    mov eax, 0x0

    ; syscall

loadKernel:
    mov rax, 0x0200
    mov rsi, kernelPath
    mov rbx, kernelAdress
    xor rcx, rcx

    ret