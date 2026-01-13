.intel_syntax noprefix

.global open
.global write
.global copy_file_range
.global close
.global _exit

open:
mov rax, 2
syscall
ret

write:
mov rax, 1
syscall
ret

copy_file_range:
mov rax, 326
syscall
ret

close:
mov rax, 3
syscall
ret

_exit:
mov rax, 60
syscall
