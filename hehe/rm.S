.intel_syntax noprefix

.global write
.global rmdir
.global unlink
.global _exit

write:
mov rax, 1
syscall
ret

rmdir:
mov rax, 84
syscall
ret

unlink:
mov rax, 87
syscall
ret

_exit:
mov rax, 60
syscall
