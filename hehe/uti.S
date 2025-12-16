.intel_syntax noprefix

.global _mkdir
.global _chdir
.global _exit

_mkdir:
mov rax, 83
syscall
ret

_chdir:
mov rax, 80
syscall
ret

_exit:
mov rax, 60
syscall
