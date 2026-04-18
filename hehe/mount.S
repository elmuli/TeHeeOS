.intel_syntax noprefix

.global mount
.global _exit

mount:
mov rax, 165
syscall
ret

_exit:
mov rax, 60
syscall
