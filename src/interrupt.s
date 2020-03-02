%macro ISR_ERRCODE 1
	[GLOBAL isr%1]
	isr%1:
		cli
		push byte %1
		jmp isr_common_stub
		
%macro ISR_NOERRCODE 1
	[GLOBAL isr%1]
	isr%1:
		cli		// clear interupt flag
		push byte  0 // dummy byte to have same kind of stack
		push byte %1 // interupt number
		jmp isr_common_stub // doing some pushing and calling higer level inte
%endmacro

isr_common_stub:
	pusha

	mov		ax,		ds
	push	eax

	mov		ax,		0x10
	mov		ds,		ax
	mov		es,		ax
	mov		fs,		ax
	mov		gs,		ax

	call	isr_handler

	pop		eax
	mov		ds,		ax
	mov		es,		ax
	mov		fs,		ax
	mov		gs,		ax

	popa
	add		eax,	8
	sti
	iret

