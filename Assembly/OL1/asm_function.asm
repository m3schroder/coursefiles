global print 

segment .text

print:

	mov rsi,rdi
	mov rdx,77
	mov rax,1
	mov rdi,1

	syscall
	ret
