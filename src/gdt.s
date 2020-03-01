
; Setting the gdtr to gdt pointer
; the gdt pointer is passed from the init_gdt() function from descriptor_table
; gdt_flush function is called from descriptor_tables.c


[GLOBAL gdt_flush]
[GLOBAL idt_flush]

get_flush:
	mov eax, [esp + 4]
	lgdt [eax] ; Loading the new GDT pointer

	; 16 * 8 = 64 * 2 it means the second descriptor which is data descriptor
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	jmp 0x08:.flush ; Loading the CS reg with 0x08 and IP with .flush location
.flush:
	ret

idt_flush:
	mov eax, [esp + 4]
	lidt [eax]
	ret
