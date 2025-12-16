.intel_syntax noprefix

.global write
.global read
.global fork
.global execve
.global real_waitid
.global _mkdir
.global chdir
.global rmdir
.global getcwd
.global _exit

write:
mov rax, 1
syscall
ret

read:
mov rax, 0
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

real_waitid:
mov rax, 247
mov r10, rcx
syscall
ret

_mkdir:
mov rax, 83
syscall
ret

chdir:
mov rax, 80
syscall
ret

rmdir:
mov rax, 84
syscall
ret

getcwd:
mov rax, 79
syscall
ret

_exit:
mov rax, 60
syscall
