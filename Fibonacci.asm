; Assembly x86 64 bit program that prints Fibonacci series (10 numbers- change value moved to rcx (line 21) for changing the number of outcomes)
; Uses printf and jump statements
; Scroll to end for commands and output


global main
	extern printf

section .data
  format:	db '%15ld', 10, 0
  title:	db 'fibonacci numbers', 10, 0
	
section .text
main:
	push rbp 		; set up stack
	mov rdi, title 		; arg 1 is a pointer
	mov rax, 0 		; no vector registers in use
	call printf

	mov rcx, 10 	; counts 10 integers
	mov rax, 0 		; rax will hold the current number
	mov rbx, 1 		; rbx will hold the next number
  printf
  
	;  We need to call printf, but we are using rax, rbx, and rcx.
	;  printf may destroy rax and rcx so we will save these before the call and restore them afterwards.
  
	push rax 		      ; 32-bit stack operands are not encodable
	push rcx 		      ; in 64-bit mode, so we use the "r" names
	mov rdi, format 	; arg 1 is a pointer
	mov rsi, rax 		  ; arg 2 is the current number
	mov eax, 0 		    ; no vector registers in use
	call printf
	pop rcx
	pop rax
	mov rdx, rax 		; save the current number
	mov rax, rbx 		; next number is now current
	add rbx, rdx 		; get the new next number
	dec rcx 		    ; count down
	jnz print 		  ; if not done counting, do some more

	pop rbp 		    ; restore stack
	mov rax, 0		  ; normal exit
	ret
  
  ;$ nasm -f elf64 Fibonacci.asm -o Fibonacci.o   
  ;$ gcc -no-pie Fibonacci.o  -o Fibonacci 
  ;$ ./Fibonacci                          
  ;fibonacci numbers
  ;           0
  ;           1
  ;           1
  ;           2
  ;           3
  ;           5
  ;           8
  ;           13
  ;           21
  ;           34
 
