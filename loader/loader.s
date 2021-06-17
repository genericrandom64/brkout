[org 0x7c00:0]
[bits 16]
; stack setup
mov bp, 0x9000
mov sp, bp

; gfx
mov al, 13h
mov ax, 13h
int 10h



; load kernel
mov bx, 0x1000
mov ah, 2
mov al, 31
mov cx, 2
int 13h

mov cx, 136
mov dx, 93
mov bx, logo
write_str:
mov al, byte [bx]
add bx, 1
add cx, 1
push bx
mov bh, 1
mov ah, 0xc
cmp al, 254
je line_done
ja ecapes
back:
pop bx
int 10h
jmp write_str
line_done:
add dx, 1
mov cx, 136
mov al, 0
jmp back


; escape the confines of reality
ecapes:
cli
lgdt [gdt_descriptor]
mov eax, cr0
or eax, 1
mov cr0, eax
jmp CODE:initialize_purple_motion

[bits 32]
PURPLE_MOTION: call 0x1000

; handmade image
logo: db 15,15,15,15,0,0,15,15,15,15,0,0,15,15,15,15,15,0,0,15,15,15,0,0,15,0,0,0,15,0,15,15,15,15,15,0,15,0,0,0,15,0,15,15,15,15,15,254,15,0,0,0,15,0,15,0,0,0,15,0,15,0,0,0,0,0,15,0,0,0,15,0,15,0,0,0,15,0,15,0,0,0,15,0,15,0,0,0,15,0,0,0,15,0,0,254,15,0,0,0,15,0,15,0,0,0,15,0,15,0,0,0,0,0,15,0,0,0,15,0,15,0,0,0,15,0,15,0,0,0,15,0,15,0,0,0,15,0,0,0,15,0,0,254,15,15,15,15,0,0,15,15,15,15,0,0,15,15,15,15,0,0,15,15,15,15,15,0,15,15,15,15,0,0,15,0,0,0,15,0,15,0,0,0,15,0,0,0,15,0,0,254,15,0,0,0,15,0,15,0,0,0,15,0,15,0,0,0,0,0,15,0,0,0,15,0,15,0,0,0,15,0,15,0,0,0,15,0,15,0,0,0,15,0,0,0,15,0,0,254,15,0,0,0,15,0,15,0,0,0,15,0,15,0,0,0,0,0,15,0,0,0,15,0,15,0,0,0,15,0,15,0,0,0,15,0,15,0,0,0,15,0,0,0,15,0,0,254,15,15,15,15,0,0,15,0,0,0,15,0,15,15,15,15,15,0,15,0,0,0,15,0,15,0,0,0,15,0,15,15,15,15,15,0,15,15,15,15,15,0,0,0,15,0,0,255

%include "loader/las.s"
