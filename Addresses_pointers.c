//Printing variables and addresses using pointers in C.
//Move to the end for OUTPUT


#include<stdio.h>

extern int exnum = 1;               //External Variable
extern int *p_exnum = &exnum;       //Pointer variable

int glnum = 2;                      //Global Variable 
int *p_glnum = &glnum;              //Pointer variable

int main(void){
  int locnum = 3;                   //Local Variable
  int *p_locnum = &locnum;          //Pointer variable
  
  static int stnum = 5;               //Static Variable 
  static int *p_stnum = &stnum;       //Pointer variable
  
  auto int aunum = 6;                   //Automatic
  auto int *p_aunum = &aunum;           //Pointer variable
  
  const int conum = 7;                  //Constant
  const int *p_conum = &conum;          //Pointer variable
  
  printf("External Variable : %d \t Address : %d \n" ,*p_exnum, p_exnum);
  printf("Global Variable : %d \t Address : %d \n" ,*p_glnum, p_glnum);
  printf("Local Variable : %d \t Address : %d \n" ,*p_locnum, p_locnum);
  printf("Static Variable : %d \t Address : %d \n" ,*p_stnum, p_stnum);
  printf("Automatic Variable : %d \t Address : %d \n" ,*p_aunum, p_aunum);
  printf("Constant Variable : %d \t Address : %d \n" ,*p_conum, p_conum);
  
  localfunc();
  
  return 0;
  }

void localfunc() {
    int locfnum = 4;               //Local Variable
    int *p_locfnum = &locfnum;     //Pointer variable
  
    printf("Local Variable inside function Variable : %d \t Address : %d " ,*p_exnum, p_exnum);
    printf("\n\n Accessing variables inside function\n");
    printf("External Variable : %d \t Address : %d \n" ,*p_exnum, p_exnum);
    printf("Global Variable : %d \t Address : %d \n" ,*p_glnum, p_glnum);
   }


/*
OUTPUT:

$ gcc addpoin.c -o addpoin.o
addpoin.c:3:12: warning: ‘exnum’ initialized and declared ‘extern’
    3 | extern int exnum = 1;               //External Variable
      |            ^~~~~
addpoin.c:4:13: warning: ‘p_exnum’ initialized and declared ‘extern’
    4 | extern int *p_exnum = &exnum;       //Pointer variable
      |             ^~~~~~~
addpoin.c: In function ‘main’:
addpoin.c:29:3: warning: implicit declaration of function ‘localfunc’ [-Wimplicit-function-declaration]
   29 |   localfunc();
      |   ^~~~~~~~~
addpoin.c: At top level:
addpoin.c:34:6: warning: conflicting types for ‘localfunc’
   34 | void localfunc() {
      |      ^~~~~~~~~
addpoin.c:29:3: note: previous implicit declaration of ‘localfunc’ was here
   29 |   localfunc();
      |   ^~~~~~~~~
                                                                                                                                                                                                                                             
$ ./addpoin.o               
External Variable : 1    Address : 1597980728 
Global Variable : 2      Address : 1597980732 
Local Variable : 3       Address : 1608167028 
Static Variable : 5      Address : 1597980736 
Automatic Variable : 6   Address : 1608167024 
Constant Variable : 7    Address : 1608167020 
Local Variable inside function Variable : 1      Address : 1597980728 

 Accessing variables inside function
External Variable : 1    Address : 1597980728 
Global Variable : 2      Address : 1597980732 

*/
