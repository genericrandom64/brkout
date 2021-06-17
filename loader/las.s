[bits 16]

gdt_start:
	dq 0
gdt_code:
	dd 0x0000ffff
	db 0, 10011010b, 11001111b, 0
gdt_data:
	dd 0x0000ffff
	db 0, 10010010b, 11001111b, 0
gdt_end:
gdt_descriptor:
	dw gdt_end - gdt_start - 1
	dd gdt_start

CODE equ gdt_code - gdt_start
DATA equ gdt_data - gdt_start

[bits 32]
initialize_purple_motion:
	mov ax, DATA
	mov ds, ax
	mov ss, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ebp, 0x90000
	mov esp, ebp
	call PURPLE_MOTION

times 510 - ($-$$) db 0
dw 0xaa55
