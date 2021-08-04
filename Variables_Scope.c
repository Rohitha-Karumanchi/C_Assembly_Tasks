#include<stdio.h>

extern int exnum = 1;    //External Variable : can be accessed outside and throughout the program
int glnum = 2;           //Global Variable  : can be accessed throughout the program.

int main(void){
  int locnum = 3;       //Local Variable :Scope is limited to the block
  static int stnum = 5; //Static Variable : Retains its value between multiple function calls
  auto int aunum = 6;   //All variables declared inside block are auto by default
  const int conum = 7;  //Cannot change the value after initialisation
  
  printf("External Variable : %d \n" ,exnum);
  printf("Global Variable : %d \n" ,glnum);
  printf("Local Variable : %d \n" ,locnum);
  printf("Static Variable : %d \n" ,stnum);
  printf("Automatic Variable : %d \n" ,aunum);
  printf("Constant Variable : %d \n" ,conum);
  //printf("Accessing Local Variable declared in function outside function: %d \n" ,locfnum);  // Cannot be accessed : shows error while compilation "error: ‘locfnum’ undeclared "
  localfunc();
  
  return 0;
  }

void localfunc() {
    int locfnum = 4;     //Local Variable : Scope is Limited to the Function
    printf("Local Variable inside function Variable : %d " ,locfnum);
    printf("\n\n Accessing variables inside function\n");
    printf("External Variable : %d \n" ,exnum);
    printf("Global Variable : %d \n" ,glnum);
    //printf("Local Variable : %d \n" ,locnum);  //Cannot be accessed : shows error while compilation "error: ‘locnum’ undeclared "
    //printf("Static Variable : %d \n" ,stnum);   // Cannot be accessed : shows error while compilation "error: ‘stnum’ undeclared "
    //printf("Automatic Variable : %d \n" ,aunum);  // Cannot be accessed : shows error while compilation "error: ‘aunum’ undeclared "
    //printf("Constant Variable : %d \n" ,conum);   // Cannot be accessed : shows error while compilation "error: ‘cofnum’ undeclared "
}



/*
Output using gcc
$ gcc var.c -o varc.o
var.c:3:12: warning: ‘exnum’ initialized and declared ‘extern’
    3 | extern int exnum = 1;    //External Variable : can be accessed outside and throughout the program
      |            ^~~~~
var.c: In function ‘main’:
var.c:19:3: warning: implicit declaration of function ‘localfunc’ [-Wimplicit-function-declaration]
   19 |   localfunc();
      |   ^~~~~~~~~
var.c: At top level:
var.c:24:6: warning: conflicting types for ‘localfunc’
   24 | void localfunc() {
      |      ^~~~~~~~~
var.c:19:3: note: previous implicit declaration of ‘localfunc’ was here
   19 |   localfunc();
      |   ^~~~~~~~~
                                                                                                                                                                                                                                             
$ ./varc.o           
External Variable : 1 
Global Variable : 2 
Local Variable : 3 
Static Variable : 5 
Automatic Variable : 6 
Constant Variable : 7 
Local Variable inside function Variable : 4 

 Accessing variables inside function
External Variable : 1 
Global Variable : 2 
*/
