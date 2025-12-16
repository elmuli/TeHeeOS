.intel_syntax noprefix

.global write
.global read
.global open
.global close
.global _exit

write:
mov rax, 1
syscall
ret

read:
mov rax, 0
syscall
ret

open:
mov rax, 2
syscall
ret

close:
mov rax, 3
syscall
ret

_exit:
mov rax, 60
syscall
