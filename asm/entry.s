[bits 32]
[extern kernel_entry]
global _start
_start:
call kernel_entry
jmp $
