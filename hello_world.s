	.arch armv8-a
	.file	"hello_world.c"
	.text
	.align	2
	.p2align 4,,11
	.global	sum
	.type	sum, %function
sum:
.LFB23:
	.cfi_startproc
	add	w0, w0, w1
	ret
	.cfi_endproc
.LFE23:
	.size	sum, .-sum
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align	3
.LC0:
	.string	"Hello, World! %d\n"
	.section	.text.startup,"ax",@progbits
	.align	2
	.p2align 4,,11
	.global	main
	.type	main, %function
main:
.LFB24:
	.cfi_startproc
	stp	x29, x30, [sp, -16]!
	.cfi_def_cfa_offset 16
	.cfi_offset 29, -16
	.cfi_offset 30, -8
	mov	w2, 30
	adrp	x1, .LC0
	mov	x29, sp
	add	x1, x1, :lo12:.LC0
	mov	w0, 2
	bl	__printf_chk
	mov	w0, 0
	ldp	x29, x30, [sp], 16
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
