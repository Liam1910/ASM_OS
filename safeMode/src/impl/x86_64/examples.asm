global examples

section .data
	key dq 1548254
	keyType dq 0
	rlkt dq 3096508

	err dq 0

section .text
bits 64

examples:
	mov rax, [key]
	mov rbx, [keyType]

	mov rbx, rax
	add rbx, rax

	cmp rbx, [rlkt]
	je realType
	jne error

	ret

realType:
	mov rax, [err]

	ret

error:
	mov rdx, [err]
	add rdx, 1
	mov rax, rdx

	ret




; General-Purpose Registers:

;   RAX: Accumulator register
;   RBX: Base register
;   RCX: Count register
;   RDX: Data register
;   RSI: Source index register
;   RDI: Destination index register
;   RBP: Base pointer register
;   RSP: Stack pointer register
;   R8-R15: Additional general-purpose registers

; Segment Registers:

;   CS: Code segment register
;   DS: Data segment register
;   SS: Stack segment register
;   ES: Extra segment register
;   FS: Additional segment register
;   GS: Additional segment register

; Special-Purpose Registers:

;   RIP: Instruction pointer register
;   RFLAGS: Flags register
;   CR0-CR8: Control registers
;   DR0-DR7: Debug registers
;   TR0-TR7: Task registers