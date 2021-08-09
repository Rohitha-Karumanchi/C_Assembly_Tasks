;We are printing even numbers from 0 to 100 (using printf)
;logic is incrementing by 2
;Author Rohitha Karumanchi
;Scroll to end for output and commands

global main

extern printf

section .data
	a:	dq	2	; int a=2;
	b:	dq	4	; int b=4
	format:	db "%5ld", 10, 0
	
section .text

main:
	push rbp 		; set up stack
	
	mov rcx, 50 		; rcx will countdown from 50 to 0
	mov rax, [a] 		; rax will hold the current number
	mov rbx, [b] 		; rbx will hold the next number

even:
  ; pushing rcx and rax beause printf might destroy them.
	push rax
	push rcx
	mov rdi, format
	mov rsi,rax
	mov rax, 0
	call printf
  
	pop rcx
	pop rax
	mov rdx, rax 		        ; save the current number
	mov rax, rbx 		        ; next number is now current
	add rbx, 2		          ; get the new next number
	dec rcx 		            ; count down, decrementing by 1
	cmp rcx, 0              ; compare rcx value to 0
	jg even                 ; if the above comparison returns greater than then jump to even label
	
  ;exit
	pop rbp  		; restore stack
	mov rax,0		; normal, no error, return value
	ret			; return
	
  ;$ nasm -f elf64 Even.asm -o Even.o  
  ;$ gcc -no-pie  Even.o  -o Even 
  ;$ ./Even                           
  ;  2
  ;  4
  ;  6
  ;  8
  ; 10
  ; 12
  ; 14
  ; 16
  ; 18
  ; 20
  ; 22
  ; 24
  ; 26
  ; 28
  ; 30
  ; 32
  ; 34
  ; 36
  ; 38
  ; 40
  ; 42
  ; 44
  ; 46
  ; 48
  ; 50
  ; 52
  ; 54
  ; 56
  ; 58
  ; 60
  ; 62
  ; 64
  ; 66
  ; 68
  ; 70
  ; 72
  ; 74
  ; 76
  ; 78
  ; 80
  ; 82
  ; 84
  ; 86
  ; 88
  ; 90
  ; 92
  ; 94
  ; 96
  ; 98
  ; 100
