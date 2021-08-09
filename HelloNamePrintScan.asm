	; Rohitha Karumanchi
  ; 64 bit Hello World Program (Getting input) 
  ; linking with c using gcc 
  ; Using printf and scanf 
  ; Go to end for commands and output
	

	global  main
	extern printf
	extern scanf
		 
	SECTION .data
	msg1        db      'Please enter your name: ',10,0    ; message string asking user for input
	msg2        db      'Hello, ',0                      ; message string to use after user has entered their name
	format:	db "%ld", 0
	 
	SECTION .bss
	sinput:     resb    255                                ; reserve a 255 byte space in memory for the users input string
	 
	SECTION .text
	
	 
	main:
	 
	push rbp 		; set up stack
	
  ;asking user for name
	mov rdi, msg1 		; arg 1 is a pointer
	mov rax, 0 		; no vector registers in use
	call printf
	    
   ; Reading name from user
	 mov     rdx, 255       ; number of bytes to read
	 mov     rcx, sinput    ; reserved space to store our input (known as a buffer)
	 mov     rbx, 0         ; write to the STDIN file
	 mov     rax, 3         ; invoke SYS_READ (kernel opcode 3)
	 int     80h
		 
  ; Printing "Hello, "   
	mov rdi, msg2 		; arg 1 is a pointer
	mov rax, 0 		; no vector registers in use
	call printf    
	
  ; Printing name read from user
	mov rdi, sinput 	; 
	mov rax, 0 		; no vector registers in use
	call printf   
	
  ;exit
	pop rbp 		; restore stack
	mov rax, 0		; normal exit
	ret 
	  
	; Compile with:$ nasm -f elf64 HelloNamePrintScan.asm -o HelloNamePrintScan.o                                                          
 	; Link with gcc  :$ gcc -no-pie  HelloNamePrintScan.o  -o HelloNamePrintScan    
 	; Run with: $./HelloNamePrintScan            
	; Please enter your name: 
  ; Rohitha
	; Hello, Rohitha
