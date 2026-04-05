.intel_syntax noprefix

.global mount
.global fork
.global execve
.global _exit

mount:
mov rax, 165
syscall
ret

execve:
mov rax, 59
syscall
ret

fork:
mov rax, 57
syscall
ret

_exit:
mov rax, 60
syscall
