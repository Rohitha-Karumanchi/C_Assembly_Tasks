	; Rohitha_Karumanchi
        ; 64 bit, Hello World Program (Getting input)
	; Go to end for Execution COmmands and Output
        ; Asks user for name and prints "Hello , Name".

	 
		 
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
	 
	  ;Asking user to enter name  
	  mov rax, 4     ; sys_write system call
	  mov rbx, 1     ;stdout file description
	  mov rcx, msg1  ;bytes to write
	  mov rdx, len1     ; number of bytes to write
	  int 0x80         ; perform system call
	 
	  ;Reading name from user
          mov     rdx, 255       ; number of bytes to read
	  mov     rcx, sinput    ; reserved space to store our input (known as a buffer)
	  mov     rbx, 0         ; write to the STDIN file
	  mov     rax, 3         ; invoke SYS_READ (kernel opcode 3)
	  int     80h
	 
	  ;Displaying "Hello, " on console  
	  mov rax, 4     ; sys_write system call
	  mov rbx, 1     ;stdout file description
	  mov rcx, msg2  ;bytes to write
	  mov rdx, len2     ; number of bytes to write
	  int 0x80         ; perform system call
	 
	  ;Displaying name on console  
	  mov rax, 4     ; sys_write system call
	  mov rbx, 1     ;stdout file description
	  mov rcx, sinput  ;bytes to write
	  mov rdx, 255     ; number of bytes to write
	  int 0x80         ; perform system call
	 
	 
	  ;exit
	  mov rax, 1     ; sys_exit system call
	  mov rbx, 0      ; exit status is 0
	  int 0x80
  
  
        ; Compile with  :   $ nasm -f elf64 HelloName.asm                                                         
 	; Link with     :   $ ld HelloWorldName.o -o HelloName 
 	; Run with      :   $./HelloName            
	; Please enter your name: Rohitha
	; Hello, Rohitha
