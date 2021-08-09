	; Hello Name Program (Getting input) 32 bit
  ; Reads name from user and prints "Hello, Name"
  ; Scroll down for output and commands
	
	 
		 
	SECTION .data
	msg1        db      'Please enter your name: ', 0h     ; message string asking user for input
	len1 equ $ - msg1
	msg2        db      'Hello, ', 0h                      ; message string to use after user has entered their name
	len2 equ $ - msg2
	 
	SECTION .bss
	sinput:     resb    255                                ; reserve a 255 byte space in memory for the users input string
	 
	SECTION .text
	global  _start
	 
	_start:
	 
	    
	    mov eax, 4         ; sys_write system call
	    mov ebx, 1         ;stdout file description
	    mov ecx, msg1      ;bytes to write
	    mov  edx, len1     ; number of bytes to write
	    int 0x80           ; perform system call
	 
	 
	 
	    mov     edx, 255       ; number of bytes to read
	    mov     ecx, sinput    ; reserved space to store our input (known as a buffer)
	    mov     ebx, 0         ; write to the STDIN file
	    mov     eax, 3         ; invoke SYS_READ (kernel opcode 3)
	    int     80h
	 
	    
	    mov eax, 4         ; sys_write system call
	    mov ebx, 1         ;stdout file description
	    mov ecx, msg2      ;bytes to write
	    mov  edx, len2     ; number of bytes to write
	    int 0x80           ; perform system call
	 
	    
	    mov eax, 4          ; sys_write system call
	    mov ebx, 1          ;stdout file description
	    mov ecx, sinput     ;bytes to write
	    mov  edx, 255       ; number of bytes to write
	    int 0x80            ; perform system call
	 
	 
	  
	   mov eax, 1            ; sys_exit system call
	   mov ebx, 0            ; exit status is 0
	   int 0x80
    
    
  ; Compile with: nasm -f elf HelloName32.asm
	; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 HelloName32.o -o HelloName32
	; Run with: ./HelloName32
  ; Please enter your name : Rohitha
  ; Hello, Rohitha
