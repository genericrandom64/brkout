[ "$1" = "run" ] && qemu-system-x86_64 -hda brkout

[ "$1" = "clean" ] && rm obj/* brkout

[ "$1" = "loader" ] && nasm -fbin loader/loader.s -o obj/loader

# DO NOT do this in git version
#[ "$1" = "write-disk" ] && doas dd if=brkout of=/dev/null

[ "$1" = "kernel" ] && 	nasm -felf asm/entry.s &&
			nasm -felf asm/interrupt.s &&
			mv asm/*.o . &&
			for i in src/*.c; do i386-elf-gcc -c $i -ffreestanding -Iinclude -Os | true; done &&
			mv *.o obj

[ "$1" = "link" ] && i386-elf-ld -o obj/kern_img -Ttext 0x1000 obj/entry.o $(ls obj/*.o | grep -v entry.o) --oformat binary && cat obj/loader obj/kern_img > brkout

[ -z "$1" ] && $0 loader | true && $0 kernel | true && $0 link | true

[ "$1" = "dr" ] && $0 clean | true && $0 | true && $0 run | true
